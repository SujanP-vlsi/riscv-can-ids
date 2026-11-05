#include <stdint.h>

typedef struct {
    uint32_t id;
    uint8_t  dlc;
    uint8_t  data[8];
} CANFrame;

int inspect_can_frame(const CANFrame *frame) {
    if (frame->id < 6) {
        return 1; // Intrusion detected
    }
    return 0; // Normal frame
}

// Memory-mapped address monitored during simulation
volatile uint32_t *const IDS_RESULT_REG = (uint32_t *) 0x20000000;

int main(void) {
    CANFrame test_frames[3] = {
        { .id = 0x002, .dlc = 8, .data = {0} }, // Intrusion
        { .id = 0x1A0, .dlc = 8, .data = {0} }, // Normal
        { .id = 0x004, .dlc = 8, .data = {0} }  // Intrusion
    };

    for (int i = 0; i < 3; i++) {
        int result = inspect_can_frame(&test_frames[i]);
        *IDS_RESULT_REG = result;
    }

    while (1); // Trap CPU in infinite loop
}
