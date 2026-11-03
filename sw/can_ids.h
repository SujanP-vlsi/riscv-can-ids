#ifndef CAN_IDS_H
#define CAN_IDS_H

#include <stdint.h>

typedef struct {
    uint32_t id;        // Standard (11-bit) or Extended (29-bit) CAN ID
    uint8_t  dlc;       // Data Length Code (0-8 bytes)
    uint8_t  data[8];   // Payload bytes
    uint32_t timestamp; // Cycle timestamp
} can_frame_t;

typedef enum {
    TRAFFIC_NORMAL = 0,
    ATTACK_DOS     = 1,
    ATTACK_FUZZING = 2,
    ATTACK_SPOOF   = 3
} threat_level_t;

#define DOS_CAN_ID_THRESHOLD  0x005

threat_level_t inspect_can_frame(const can_frame_t *frame);

#endif // CAN_IDS_H
