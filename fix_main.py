main_c = """#include <stdint.h>

#define CAN_STATUS    (*(volatile uint32_t *)0x10000000)
#define CAN_ID        (*(volatile uint32_t *)0x10000004)
#define CAN_DLC       (*(volatile uint32_t *)0x10000008)
#define CAN_DATA_LOW  (*(volatile uint32_t *)0x1000000C)
#define CAN_DATA_HIGH (*(volatile uint32_t *)0x10000010)
#define CYCLE_COUNTER (*(volatile uint32_t *)0x10000014)

#define IDS_ALERT     (*(volatile uint32_t *)0x20000000)

#define DOS_THRESHOLD_CYCLES 100

int main(void) {
    uint32_t last_frame_time = 0;
    uint8_t  last_seq_cnt = 0;
    uint8_t  seq_initialized = 0;

    while (1) {
        if (CAN_STATUS & 0x01) {
            uint32_t current_time = CYCLE_COUNTER;
            uint32_t delta_t      = current_time - last_frame_time;
            
            uint32_t id     = CAN_ID;
            uint32_t dlc    = CAN_DLC;
            uint32_t data_l = CAN_DATA_LOW;

            uint8_t alert = 0;

            if (dlc > 8) {
                alert = 1;
            } else if (id == 0x7DF) {
                alert = 1;
            } else if (data_l == 0xDEADBEEF) {
                alert = 1;
            } else if (last_frame_time != 0 && delta_t < DOS_THRESHOLD_CYCLES) {
                alert = 1;
            } else if (id == 0x100) {
                uint8_t current_seq = (uint8_t)(data_l & 0x0F);
                if (seq_initialized) {
                    uint8_t expected_seq = (last_seq_cnt + 1) & 0x0F;
                    if (current_seq != expected_seq) {
                        alert = 1;
                    }
                }
                last_seq_cnt = current_seq;
                seq_initialized = 1;
            }

            IDS_ALERT = alert ? 0x01 : 0x00;
            last_frame_time = current_time;
            CAN_STATUS = 0x00;
        }
    }
    return 0;
}
"""

with open("sw/main.c", "w") as f:
    f.write(main_c)

print("[SUCCESS] sw/main.c generated successfully.")
