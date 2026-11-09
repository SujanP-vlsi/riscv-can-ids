import numpy as np
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
    header = f"""#ifndef WEIGHTS_H
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
static const int8_t W1[L1_OUT][L1_IN] = {{\n"""

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
