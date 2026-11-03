import numpy as np
import pandas as pd

def generate_synthetic_can_data(num_samples=1000):
    """Generates synthetic CAN bus traffic (Normal vs DoS Attack)."""
    np.random.seed(42)
    # CAN ID: Normal traffic uses 0x0120, 0x0240, 0x0380; DoS injects dominant 0x0000
    can_ids = np.random.choice([0x0120, 0x0240, 0x0380, 0x0000], size=num_samples, p=[0.3, 0.3, 0.3, 0.1])
    dlc = np.random.randint(1, 9, size=num_samples)
    payload_byte0 = np.random.randint(0, 256, size=num_samples)
    
    # Label: 1 if attack (0x0000 ID), else 0
    labels = (can_ids == 0x0000).astype(int)
    
    df = pd.DataFrame({
        'can_id': can_ids,
        'dlc': dlc,
        'byte0': payload_byte0,
        'label': labels
    })
    return df

if __name__ == "__main__":
    data = generate_synthetic_can_data()
    print("Generated CAN Dataset Preview:")
    print(data.head())
    print("\nClass Distribution:")
    print(data['label'].value_counts())
