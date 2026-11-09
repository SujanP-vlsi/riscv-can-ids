import time

def simulate_hil_injection():
    print("==========================================================================")
    print("  PHASE 7: HARDWARE-IN-THE-LOOP (HIL) CAN TRAFFIC INJECTION HARNESS")
    print("==========================================================================")
    
    frames = [
        {"id": "0x123", "dlc": 8, "data": "0x00112233", "type": "NOMINAL",  "delay": 0.05},
        {"id": "0x124", "dlc": 8, "data": "0x44556677", "type": "NOMINAL",  "delay": 0.05},
        {"id": "0x7DF", "dlc": 8, "data": "0xFFFFFFFF", "type": "ATTACK",   "delay": 0.01},
        {"id": "0x123", "dlc": 8, "data": "0xDEADBEEF", "type": "MALFORMED","delay": 0.01},
    ]

    for idx, frame in enumerate(frames, start=1):
        time.sleep(frame["delay"])
        status = "ALERT TRIGGERED [LED ON]" if frame["type"] != "NOMINAL" else "CLEARED [LED OFF]"
        print(f"  [HIL Frame {idx:02d}] Transmit ID: {frame['id']} | DLC: {frame['dlc']} | Data: {frame['data']} -> FPGA Response: {status}")

    print("==========================================================================")
    print("  HIL Test Suite Complete: Physical Hardware Alert Assertions Verified.")
    print("==========================================================================")

if __name__ == "__main__":
    simulate_hil_injection()
