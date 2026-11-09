import numpy as np
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
