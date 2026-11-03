#include <stdio.h>
#include "can_ids.h"

threat_level_t inspect_can_frame(const can_frame_t *frame) {
    if (frame->id <= DOS_CAN_ID_THRESHOLD) {
        return ATTACK_DOS;
    }
    return TRAFFIC_NORMAL;
}

int main(void) {
    can_frame_t test_frame = {
        .id = 0x000,
        .dlc = 8,
        .data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        .timestamp = 1050
    };

    threat_level_t status = inspect_can_frame(&test_frame);

    if (status == ATTACK_DOS) {
        return 1;
    }

    return 0;
}
