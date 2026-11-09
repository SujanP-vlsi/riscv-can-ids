#ifndef IDS_DRIVER_H
#define IDS_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

#define IDS_BASE_ADDR         0x10000000U
#define IDS_ALERT_BASE_ADDR   0x20000000U

#define IDS_REG_CAN_STATUS    (IDS_BASE_ADDR + 0x00U)
#define IDS_REG_CAN_ID        (IDS_BASE_ADDR + 0x04U)
#define IDS_REG_CAN_DLC       (IDS_BASE_ADDR + 0x08U)
#define IDS_REG_CAN_DATA_LOW  (IDS_BASE_ADDR + 0x0CU)
#define IDS_REG_CAN_DATA_HIGH (IDS_BASE_ADDR + 0x10U)
#define IDS_REG_CYCLE_CNT     (IDS_BASE_ADDR + 0x14U)
#define IDS_REG_ALERT         (IDS_ALERT_BASE_ADDR + 0x00U)

typedef struct {
    volatile uint32_t CAN_STATUS;
    volatile uint32_t CAN_ID;
    volatile uint32_t CAN_DLC;
    volatile uint32_t CAN_DATA_LOW;
    volatile uint32_t CAN_DATA_HIGH;
    volatile uint32_t CYCLE_COUNTER;
} ids_hw_regs_t;

static inline uint32_t ids_read_status(void) {
    return *(volatile uint32_t*)(IDS_REG_CAN_STATUS);
}

static inline uint32_t ids_read_alert(void) {
    return *(volatile uint32_t*)(IDS_REG_ALERT);
}

static inline void ids_clear_alert(void) {
    *(volatile uint32_t*)(IDS_REG_ALERT) = 0x00000000U;
}

static inline uint32_t ids_read_last_id(void) {
    return *(volatile uint32_t*)(IDS_REG_CAN_ID);
}

#endif // IDS_DRIVER_H
