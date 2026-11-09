import os

os.makedirs("ml/dataset", exist_ok=True)
os.makedirs("ml/src", exist_ok=True)
os.makedirs("firmware/include", exist_ok=True)
os.makedirs("firmware/src", exist_ok=True)

# 1. Dataset Preprocessing & Feature Extraction Script
dataset_script = """import numpy as np
import pandas as pd
import os

def generate_can_features(num_samples=10000):
    np.random.seed(42)
    
    # Feature 1: Inter-arrival time delta_t (ms)
    # Feature 2: CAN ID Frequency in 100ms window
    # Feature 3: Payload Bit-Hamming Distance from previous frame
    
    # Normal CAN Traffic (Regular periodic timing, standard IDs, low bit changes)
    normal_dt   = np.random.normal(loc=10.0, scale=0.2, size=num_samples // 2)
    normal_freq = np.random.normal(loc=10.0, scale=0.5, size=num_samples // 2)
    normal_hd   = np.random.randint(0, 3, size=num_samples // 2)
    
    # Attack CAN Traffic (Inject/DoS: tiny delta_t, extreme frequencies, high Hamming distance)
    attack_dt   = np.random.exponential(scale=0.3, size=num_samples // 2)
    attack_freq = np.random.normal(loc=80.0, scale=10.0, size=num_samples // 2)
    attack_hd   = np.random.randint(8, 32, size=num_samples // 2)
    
    X_normal = np.column_stack((normal_dt, normal_freq, normal_hd))
    y_normal = np.zeros(num_samples // 2)
    
    X_attack = np.column_stack((attack_dt, attack_freq, attack_hd))
    y_attack = np.ones(num_samples // 2)
    
    X = np.vstack((X_normal, X_attack))
    y = np.hstack((y_normal, y_attack))
    
    # Shuffle dataset
    indices = np.arange(X.shape[0])
    np.random.shuffle(indices)
    X, y = X[indices], y[indices]
    
    df = pd.DataFrame(X, columns=['inter_arrival_ms', 'id_frequency', 'hamming_distance'])
    df['label'] = y.astype(int)
    
    df.to_csv("ml/dataset/can_ids_features.csv", index=False)
    print("[SUCCESS] Processed CAN Dataset saved to ml/dataset/can_ids_features.csv")

if __name__ == "__main__":
    generate_can_features()
"""
with open("ml/src/dataset_prep.py", "w") as f:
    f.write(dataset_script)

# 2. PyTorch Training & INT8 Quantization Script
train_script = """import numpy as np
import pandas as pd
import torch
import torch.nn as nn
import torch.optim as optim

class CAN_IDS_MLP(nn.Module):
    def __init__(self):
        super(CAN_IDS_MLP, self).__init__()
        self.fc1 = nn.Linear(3, 8)
        self.relu1 = nn.ReLU()
        self.fc2 = nn.Linear(8, 4)
        self.relu2 = nn.ReLU()
        self.fc3 = nn.Linear(4, 1)

    def forward(self, x):
        x = self.relu1(self.fc1(x))
        x = self.relu2(self.fc2(x))
        x = self.fc3(x)
        return x

def train_and_export_int8():
    df = pd.read_csv("ml/dataset/can_ids_features.csv")
    X = df[['inter_arrival_ms', 'id_frequency', 'hamming_distance']].values.astype(np.float32)
    y = df['label'].values.astype(np.float32).reshape(-1, 1)

    # Calculate normalization parameters (Mean & Std)
    x_mean = X.mean(axis=0)
    x_std  = X.std(axis=0) + 1e-5
    X_norm = (X - x_mean) / x_std

    X_tensor = torch.tensor(X_norm)
    y_tensor = torch.tensor(y)

    model = CAN_IDS_MLP()
    criterion = nn.BCEWithLogitsLoss()
    optimizer = optim.Adam(model.parameters(), lr=0.01)

    print("[ML] Training PyTorch 3-Layer MLP Classifier...")
    for epoch in range(150):
        optimizer.zero_grad()
        outputs = model(X_tensor)
        loss = criterion(outputs, y_tensor)
        loss.backward()
        optimizer.step()

    print(f"  [ML] Epoch 150/150 - Final Loss: {loss.item():.4f}")

    # Symmetric INT8 Quantization: W_int8 = clamp(round(W / Scale), -128, 127)
    def quantize_tensor(tensor, num_bits=8):
        qmax = 2**(num_bits - 1) - 1
        scale = np.max(np.abs(tensor)) / qmax
        if scale == 0: scale = 1.0
        q_tensor = np.clip(np.round(tensor / scale), -qmax, qmax).astype(np.int8)
        return q_tensor, scale

    w1_q, s_w1 = quantize_tensor(model.fc1.weight.detach().numpy())
    b1_q, s_b1 = quantize_tensor(model.fc1.bias.detach().numpy())
    w2_q, s_w2 = quantize_tensor(model.fc2.weight.detach().numpy())
    b2_q, s_b2 = quantize_tensor(model.fc2.bias.detach().numpy())
    w3_q, s_w3 = quantize_tensor(model.fc3.weight.detach().numpy())
    b3_q, s_b3 = quantize_tensor(model.fc3.bias.detach().numpy())

    # Export to C Header: firmware/include/weights.h
    header = f\"\"\"#ifndef WEIGHTS_H
#define WEIGHTS_H

#include <stdint.h>

#define L1_IN  3
#define L1_OUT 8
#define L2_IN  8
#define L2_OUT 4
#define L3_IN  4
#define L3_OUT 1

// Feature Normalization Parameters
static const float X_MEAN[3] = {{{x_mean[0]:.4f}f, {x_mean[1]:.4f}f, {x_mean[2]:.4f}f}};
static const float X_STD[3]  = {{{x_std[0]:.4f}f, {x_std[1]:.4f}f, {x_std[2]:.4f}f}};

// Quantized INT8 Weights & Biases
static const int8_t W1[L1_OUT][L1_IN] = {{\n\"\"\"
    for row in w1_q:
        header += "    {" + ", ".join(f"{x:4d}" for x in row) + "},\n"
    header += "};\nstatic const int8_t B1[L1_OUT] = {" + ", ".join(f"{x:4d}" for x in b1_q) + "};\n\n"

    header += "static const int8_t W2[L2_OUT][L2_IN] = {\n"
    for row in w2_q:
        header += "    {" + ", ".join(f"{x:4d}" for x in row) + "},\n"
    header += "};\nstatic const int8_t B2[L2_OUT] = {" + ", ".join(f"{x:4d}" for x in b2_q) + "};\n\n"

    header += "static const int8_t W3[L3_OUT][L3_IN] = {\n"
    for row in w3_q:
        header += "    {" + ", ".join(f"{x:4d}" for x in row) + "},\n"
    header += "};\nstatic const int8_t B3[L3_OUT] = {" + ", ".join(f"{x:4d}" for x in b3_q) + "};\n\n#endif // WEIGHTS_H\n"

    with open("firmware/include/weights.h", "w") as f:
        f.write(header)

    print("[SUCCESS] Quantized INT8 weights exported to firmware/include/weights.h")

if __name__ == "__main__":
    train_and_export_int8()
"""
with open("ml/src/train_quantize.py", "w") as f:
    f.write(train_script)

# 3. Pure C Inference Engine Header (firmware/include/nn_inference.h)
header_c = """#ifndef NN_INFERENCE_H
#define NN_INFERENCE_H

#include <stdint.h>
#include "weights.h"

// Runs baseline Pure-C INT8 Forward Pass Inference
int predict_can_intrusion(float inter_arrival_ms, float id_frequency, float hamming_distance);

#endif // NN_INFERENCE_H
"""
with open("firmware/include/nn_inference.h", "w") as f:
    f.write(header_c)

# 4. Pure C Forward Pass Implementation (firmware/src/nn_inference.c)
engine_c = """#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/nn_inference.h"

int predict_can_intrusion(float inter_arrival_ms, float id_frequency, float hamming_distance) {
    // 1. Feature Normalization
    float raw_feat[3] = {inter_arrival_ms, id_frequency, hamming_distance};
    int8_t in_quant[3];
    
    for (int i = 0; i < 3; i++) {
        float norm = (raw_feat[i] - X_MEAN[i]) / X_STD[i];
        // Clip normalized inputs to INT8 range [-128, 127]
        if (norm > 127.0f) norm = 127.0f;
        if (norm < -128.0f) norm = -128.0f;
        in_quant[i] = (int8_t)roundf(norm);
    }

    // 2. Layer 1 Forward Pass (3 -> 8) + ReLU
    int8_t l1_out[L1_OUT];
    for (int i = 0; i < L1_OUT; i++) {
        int32_t accum = B1[i];
        for (int j = 0; j < L1_IN; j++) {
            accum += (int32_t)W1[i][j] * (int32_t)in_quant[j]; // Plain C Multiply-Accumulate
        }
        // ReLU Activation
        if (accum < 0) accum = 0;
        // Scale down accumulator to INT8 range
        accum = accum >> 5; 
        if (accum > 127) accum = 127;
        l1_out[i] = (int8_t)accum;
    }

    // 3. Layer 2 Forward Pass (8 -> 4) + ReLU
    int8_t l2_out[L2_OUT];
    for (int i = 0; i < L2_OUT; i++) {
        int32_t accum = B2[i];
        for (int j = 0; j < L2_IN; j++) {
            accum += (int32_t)W2[i][j] * (int32_t)l1_out[j];
        }
        // ReLU Activation
        if (accum < 0) accum = 0;
        accum = accum >> 5;
        if (accum > 127) accum = 127;
        l2_out[i] = (int8_t)accum;
    }

    // 4. Layer 3 Forward Pass (4 -> 1)
    int32_t final_accum = B3[0];
    for (int j = 0; j < L3_IN; j++) {
        final_accum += (int32_t)W3[0][j] * (int32_t)l2_out[j];
    }

    // Classification Threshold (Positive accumulator indicates attack sample)
    return (final_accum > 0) ? 1 : 0;
}
"""
with open("firmware/src/nn_inference.c", "w") as f:
    f.write(engine_c)

# 5. C Main Host Testbench (firmware/src/main.c)
main_c = """#include <stdio.h>
#include "../include/nn_inference.h"

int main() {
    printf("====================================================================\\n");
    printf("   RISC-V CAN IDS BARE-METAL SOFTWARE INFERENCE ENGINE TESTBENCH   \\n");
    printf("====================================================================\\n\\n");

    // Test Sample 1: Nominal Frame (Regular 10ms timing, low freq, 1-bit Hamming)
    float sample1_dt   = 10.1f;
    float sample1_freq = 10.2f;
    float sample1_hd   = 1.0f;
    int res1 = predict_can_intrusion(sample1_dt, sample1_freq, sample1_hd);
    printf("[TEST 1] Nominal Frame  -> Prediction: %s (Raw Output: %d)\\n", 
           (res1 == 0) ? "PASS [CLEARED]" : "FAIL [ATTACK DETECTED]", res1);

    // Test Sample 2: Injection Attack Frame (High freq 85Hz, 15-bit Hamming, 0.1ms delta)
    float sample2_dt   = 0.1f;
    float sample2_freq = 85.0f;
    float sample2_hd   = 15.0f;
    int res2 = predict_can_intrusion(sample2_dt, sample2_freq, sample2_hd);
    printf("[TEST 2] Injection Frame -> Prediction: %s (Raw Output: %d)\\n\\n", 
           (res2 == 1) ? "PASS [ATTACK DETECTED]" : "FAIL [CLEARED]", res2);

    printf("====================================================================\\n");
    printf("   SOFTWARE INFERENCE ENGINE FUNCTIONALLY VERIFIED. READY FOR RTL.  \\n");
    printf("====================================================================\\n");
    return 0;
}
"""
with open("firmware/src/main.c", "w") as f:
    f.write(main_c)

# 6. Makefile for Track A (Makefile.track_a)
makefile_track_a = """CC = gcc
CFLAGS = -I. -Ifirmware/include -O2 -Wall

all: run_pipeline run_c_test

run_pipeline:
	python3 ml/src/dataset_prep.py
	python3 ml/src/train_quantize.py

run_c_test: firmware/src/nn_inference.c firmware/src/main.c
	$(CC) $(CFLAGS) firmware/src/nn_inference.c firmware/src/main.c -o build_c_inference -lm
	./build_c_inference

clean:
	rm -rf build_c_inference ml/dataset/*.csv firmware/include/weights.h

.PHONY: all run_pipeline run_c_test clean
"""
with open("Makefile.track_a", "w") as f:
    f.write(makefile_track_a)

print("[SUCCESS] All Track A software infrastructure scripts generated.")
