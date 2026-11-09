import os
import sys
import urllib.request
import numpy as np
import pandas as pd
import torch
import torch.nn as nn
import torch.optim as optim
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix

os.makedirs("ml/dataset", exist_ok=True)
os.makedirs("firmware/include", exist_ok=True)

def get_real_dataset_path():
    target_path = "ml/dataset/Car_Hacking_5percent.csv"
    if os.path.exists("ml/dataset"):
        csv_files = [f for f in os.listdir("ml/dataset") if f.endswith(".csv") and "sample" not in f]
        if csv_files:
            chosen = os.path.join("ml/dataset", csv_files[0])
            print(f"[DATASET] Detected local authentic dataset: {chosen}")
            return chosen

    print("[DATASET] Downloading 5% slice of authentic HCRL Car-Hacking dataset...")
    url = "https://raw.githubusercontent.com/Western-OC2-Lab/Intrusion-Detection-System-Using-CNN-and-Transfer-Learning/main/data/Car_Hacking_5%25.csv"
    try:
        urllib.request.urlretrieve(url, target_path)
        print(f"[DATASET] Download complete -> {target_path}")
        return target_path
    except Exception as e:
        print(f"[ERROR] Failed to download dataset: {e}")
        sys.exit(1)

def extract_features_from_hcrl(csv_path):
    print(f"[PARSER] Reading dataset from {csv_path}...")
    
    df_sample = pd.read_csv(csv_path, nrows=5)
    first_col = str(df_sample.columns[0]).strip()
    
    is_headerless = False
    try:
        float(first_col)
        is_headerless = True
    except ValueError:
        is_headerless = False
        
    if is_headerless:
        num_cols = len(df_sample.columns)
        if num_cols >= 12:
            cols = ['Timestamp', 'CAN ID', 'DLC', 'DATA[0]', 'DATA[1]', 'DATA[2]', 'DATA[3]', 'DATA[4]', 'DATA[5]', 'DATA[6]', 'DATA[7]', 'Flag'] + [f'Extra_{i}' for i in range(num_cols - 12)]
        elif num_cols == 5:
            cols = ['Timestamp', 'CAN ID', 'DLC', 'DATA', 'Flag']
        else:
            cols = [f'col_{i}' for i in range(num_cols)]
        df = pd.read_csv(csv_path, header=None, names=cols)
    else:
        df = pd.read_csv(csv_path)
        
    df.columns = [str(c).strip() for c in df.columns]
    num_samples = len(df)

    # 1. Delta T (ms) - dimension N
    ts_cols = [c for c in df.columns if 'time' in c.lower() or 'ts' in c.lower()]
    if ts_cols:
        timestamps = pd.to_numeric(df[ts_cols[0]], errors='coerce').fillna(0).values
    else:
        timestamps = pd.to_numeric(df.iloc[:, 0], errors='coerce').fillna(0).values

    delta_t = np.diff(timestamps, prepend=timestamps[0]) * 1000.0
    delta_t = np.clip(delta_t, 0.0, 1000.0)

    # 2. CAN ID Frequency - dimension N
    id_cols = [c for c in df.columns if 'id' in c.lower()]
    if id_cols:
        can_ids = df[id_cols[0]].astype(str).values
    else:
        can_ids = df.iloc[:, 1].astype(str).values

    id_freqs = np.zeros(num_samples, dtype=np.float32)
    window = 50
    for i in range(num_samples):
        start = max(0, i - window)
        id_freqs[i] = np.sum(can_ids[start:i+1] == can_ids[i])

    # 3. Payload Hamming Distance - dimension N
    hamming_dists = np.zeros(num_samples, dtype=np.float32)
    data_cols = [c for c in df.columns if 'data[' in c.lower()]
    
    if len(data_cols) >= 8:
        byte_cols = data_cols[:8]
        raw_bytes = df[byte_cols].fillna('0').astype(str).map(lambda x: int(x, 16) if x not in ['nan', ''] else 0).values
        for i in range(1, num_samples):
            xor_val = np.bitwise_xor(raw_bytes[i], raw_bytes[i-1])
            hamming_dists[i] = sum(bin(b).count('1') for b in xor_val)
    else:
        payload_cols = [c for c in df.columns if 'data' in c.lower() or 'payload' in c.lower()]
        p_col = payload_cols[0] if payload_cols else df.columns[3]
        payload_str = df[p_col].fillna('').astype(str).values
        prev_p = np.zeros(8, dtype=np.uint8)
        for i in range(num_samples):
            try:
                curr_p = np.array([int(b, 16) for b in payload_str[i].split()[:8]], dtype=np.uint8)
                if len(curr_p) < 8:
                    curr_p = np.pad(curr_p, (0, 8 - len(curr_p)))
            except ValueError:
                curr_p = np.zeros(8, dtype=np.uint8)
            
            if i > 0:
                xor_val = np.bitwise_xor(curr_p, prev_p)
                hamming_dists[i] = sum(bin(b).count('1') for b in xor_val)
            prev_p = curr_p

    # 4. Labels - dimension N
    label_cols = [c for c in df.columns if 'flag' in c.lower() or 'label' in c.lower() or 'class' in c.lower()]
    if label_cols:
        labels = df[label_cols[0]].astype(str).map(lambda x: 1 if x in ['T', 'Attack', '1', '1.0'] else 0).values
    else:
        labels = df.iloc[:, -1].astype(str).map(lambda x: 1 if x in ['T', 'Attack', '1', '1.0'] else 0).values

    X = np.column_stack((delta_t, id_freqs, hamming_dists)).astype(np.float32)
    y = labels.astype(np.float32).reshape(-1, 1)

    return X, y

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

def main():
    csv_path = get_real_dataset_path()
    X, y = extract_features_from_hcrl(csv_path)
    
    split = int(len(X) * 0.8)
    X_train, X_test = X[:split], X[split:]
    y_train, y_test = y[:split], y[split:]
    
    x_mean = X_train.mean(axis=0)
    x_std  = X_train.std(axis=0) + 1e-5
    X_train_norm = (X_train - x_mean) / x_std
    X_test_norm  = (X_test - x_mean) / x_std
    
    model = CAN_IDS_MLP()
    criterion = nn.BCEWithLogitsLoss()
    optimizer = optim.Adam(model.parameters(), lr=0.01)
    
    print(f"[TRAINING] Training PyTorch Model on {len(X_train):,d} Authentic HCRL Log Features...")
    X_tr_t = torch.tensor(X_train_norm)
    y_tr_t = torch.tensor(y_train)
    
    for epoch in range(150):
        optimizer.zero_grad()
        out = model(X_tr_t)
        loss = criterion(out, y_tr_t)
        loss.backward()
        optimizer.step()
        
    model.eval()
    with torch.no_grad():
        test_logits = model(torch.tensor(X_test_norm))
        test_preds  = (torch.sigmoid(test_logits).numpy() > 0.5).astype(int)
        
    y_true = y_test.astype(int).flatten()
    y_pred = test_preds.flatten()
    
    acc  = accuracy_score(y_true, y_pred)
    prec = precision_score(y_true, y_pred, zero_division=0)
    rec  = recall_score(y_true, y_pred, zero_division=0)
    f1   = f1_score(y_true, y_pred, zero_division=0)
    cm   = confusion_matrix(y_true, y_pred)
    
    print("\n==========================================================================")
    print("      ACADEMIC PUBLICATION EVALUATION METRICS (AUTHENTIC HCRL DATASET)    ")
    print("==========================================================================")
    print(f"  Dataset File : {csv_path}")
    print(f"  Total Samples: {len(X):,d} (Train: {len(X_train):,d} | Test: {len(X_test):,d})")
    print(f"  Accuracy     : {acc*100:.2f}%")
    print(f"  Precision    : {prec*100:.2f}%")
    print(f"  Recall       : {rec*100:.2f}%")
    print(f"  F1-Score     : {f1*100:.2f}%")
    print("\n  Confusion Matrix:")
    print(f"    TN: {cm[0][0]:7d} | FP: {cm[0][1]:7d}")
    if len(cm) > 1:
        print(f"    FN: {cm[1][0]:7d} | TP: {cm[1][1]:7d}")
    print("==========================================================================\n")
    
    def quantize_tensor(t):
        qmax = 127
        scale = np.max(np.abs(t)) / qmax
        if scale == 0: scale = 1.0
        return np.clip(np.round(t / scale), -128, 127).astype(np.int8)

    w1_q = quantize_tensor(model.fc1.weight.detach().numpy())
    b1_q = quantize_tensor(model.fc1.bias.detach().numpy())
    w2_q = quantize_tensor(model.fc2.weight.detach().numpy())
    b2_q = quantize_tensor(model.fc2.bias.detach().numpy())
    w3_q = quantize_tensor(model.fc3.weight.detach().numpy())
    b3_q = quantize_tensor(model.fc3.bias.detach().numpy())
    
    lines = [
        "#ifndef WEIGHTS_H",
        "#define WEIGHTS_H",
        "",
        "#include <stdint.h>",
        "",
        "#define L1_IN  3",
        "#define L1_OUT 8",
        "#define L2_IN  8",
        "#define L2_OUT 4",
        "#define L3_IN  4",
        "#define L3_OUT 1",
        "",
        f"static const float X_MEAN[3] = {{{x_mean[0]:.4f}f, {x_mean[1]:.4f}f, {x_mean[2]:.4f}f}};",
        f"static const float X_STD[3]  = {{{x_std[0]:.4f}f, {x_std[1]:.4f}f, {x_std[2]:.4f}f}};",
        "",
        "static const int8_t W1[L1_OUT][L1_IN] = {"
    ]
    for row in w1_q:
        lines.append("    {" + ", ".join(f"{x:4d}" for x in row) + "},")
    lines.append("};")
    lines.append("static const int8_t B1[L1_OUT] = {" + ", ".join(f"{x:4d}" for x in b1_q) + "};")
    lines.append("")
    lines.append("static const int8_t W2[L2_OUT][L2_IN] = {")
    for row in w2_q:
        lines.append("    {" + ", ".join(f"{x:4d}" for x in row) + "},")
    lines.append("};")
    lines.append("static const int8_t B2[L2_OUT] = {" + ", ".join(f"{x:4d}" for x in b2_q) + "};")
    lines.append("")
    lines.append("static const int8_t W3[L3_OUT][L3_IN] = {")
    for row in w3_q:
        lines.append("    {" + ", ".join(f"{x:4d}" for x in row) + "},")
    lines.append("};")
    lines.append("static const int8_t B3[L3_OUT] = {" + ", ".join(f"{x:4d}" for x in b3_q) + "};")
    lines.append("")
    lines.append("#endif // WEIGHTS_H")

    with open("firmware/include/weights.h", "w") as f:
        f.write("\n".join(lines) + "\n")
    print("[SUCCESS] Production INT8 weights.h generated from authentic HCRL dataset.")

if __name__ == "__main__":
    main()
