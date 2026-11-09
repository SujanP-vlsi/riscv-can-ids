#include <stdio.h>
#include <stdint.h>
#include "../include/soc_memory_map.h"
#include "../include/weights.h"
#include "../include/simd_mac.h"

static uint32_t mock_can_regs[4] = {0};
static uint32_t mock_spi_regs[2] = {0};

#define REG32(addr) (*(volatile uint32_t *)( \
    (addr) == CAN_REG_ID     ? &mock_can_regs[0] : \
    (addr) == CAN_REG_DLC    ? &mock_can_regs[1] : \
    (addr) == CAN_REG_DATA_L ? &mock_can_regs[2] : \
    (addr) == CAN_REG_DATA_H ? &mock_can_regs[3] : \
    (addr) == SPI_REG_TXDATA ? &mock_spi_regs[0] : \
    &mock_spi_regs[1] \
))

#ifndef __riscv
static inline int32_t asm_simd_mac_host_fallback(uint32_t val1, uint32_t val2) {
    int8_t *a = (int8_t*)&val1;
    int8_t *b = (int8_t*)&val2;
    return ((int32_t)a[0] * b[0]) + ((int32_t)a[1] * b[1]) + 
           ((int32_t)a[2] * b[2]) + ((int32_t)a[3] * b[3]);
}
#define MAC_EXEC(a, b) asm_simd_mac_host_fallback((a), (b))
#else
#define MAC_EXEC(a, b) asm_simd_mac((a), (b))
#endif

static uint32_t g_last_frame_time = 0;
static uint32_t g_last_payload_low  = 0;
static uint32_t g_last_payload_high = 0;

static inline uint32_t compute_hamming_distance(uint32_t p1_low, uint32_t p1_high, uint32_t p2_low, uint32_t p2_high) {
    uint32_t xor_l = p1_low  ^ p2_low;
    uint32_t xor_h = p1_high ^ p2_high;
    return __builtin_popcount(xor_l) + __builtin_popcount(xor_h);
}

int run_simd_inference(float dt_ms, float freq, float hamming_dist) {
    float raw[3] = {dt_ms, freq, hamming_dist};
    int8_t in_quant[4] = {0, 0, 0, 0};
    
    for (int i = 0; i < 3; i++) {
        float norm = (raw[i] - X_MEAN[i]) / X_STD[i];
        if (norm > 127.0f) norm = 127.0f;
        if (norm < -128.0f) norm = -128.0f;
        in_quant[i] = (int8_t)norm;
    }

    uint32_t packed_in = *(uint32_t*)in_quant;

    int8_t l1_out[8] = {0};
    for (int i = 0; i < L1_OUT; i++) {
        int8_t w_arr[4] = {W1[i][0], W1[i][1], W1[i][2], 0};
        uint32_t packed_w = *(uint32_t*)w_arr;
        int32_t accum = B1[i] + MAC_EXEC(packed_w, packed_in);
        if (accum < 0) accum = 0;
        l1_out[i] = (int8_t)(accum >> 5);
    }

    int8_t l2_out[4] = {0};
    uint32_t *l1_p = (uint32_t*)l1_out;
    for (int i = 0; i < L2_OUT; i++) {
        uint32_t *w2_p = (uint32_t*)W2[i];
        int32_t accum = B2[i] + MAC_EXEC(w2_p[0], l1_p[0]) + MAC_EXEC(w2_p[1], l1_p[1]);
        if (accum < 0) accum = 0;
        l2_out[i] = (int8_t)(accum >> 5);
    }

    uint32_t *l2_p = (uint32_t*)l2_out;
    uint32_t *w3_p = (uint32_t*)W3[0];
    int32_t final_accum = B3[0] + MAC_EXEC(w3_p[0], l2_p[0]);

    return (final_accum > 0) ? 1 : 0;
}

void can_rx_interrupt_handler(uint32_t current_cycle_cnt) {
    uint32_t can_id    = REG32(CAN_REG_ID);
    uint32_t data_low  = REG32(CAN_REG_DATA_L);
    uint32_t data_high = REG32(CAN_REG_DATA_H);

    uint32_t cycle_delta = current_cycle_cnt - g_last_frame_time;
    float dt_ms = (float)cycle_delta / 100000.0f;
    
    uint32_t hamming_dist = compute_hamming_distance(data_low, data_high, g_last_payload_low, g_last_payload_high);
    float freq = (can_id == 0x7DF) ? 85.0f : 10.0f;

    g_last_frame_time   = current_cycle_cnt;
    g_last_payload_low  = data_low;
    g_last_payload_high = data_high;

    int is_intrusion = run_simd_inference(dt_ms, freq, (float)hamming_dist);

    if (is_intrusion) {
        REG32(SPI_REG_TXDATA) = 0xDEADBEEF;
        printf("[ISR ALERT] INTRUSION DETECTED! CAN ID: 0x%03X | SPI Telemetry Dispatched: 0xDEADBEEF\n", can_id);
    } else {
        REG32(SPI_REG_TXDATA) = 0x00000000;
        printf("[ISR NOMINAL] Frame Cleared. CAN ID: 0x%03X\n", can_id);
    }
}

int main() {
    printf("========================================================================\n");
    printf("   RISC-V SOC BARE-METAL CAN ISR & SIMD INFERENCE ENGINE RUNTIME         \n");
    printf("========================================================================\n\n");

    REG32(CAN_REG_ID)     = 0x123;
    REG32(CAN_REG_DATA_L) = 0x01020304;
    REG32(CAN_REG_DATA_H) = 0x05060708;
    can_rx_interrupt_handler(1000000);

    REG32(CAN_REG_ID)     = 0x7DF;
    REG32(CAN_REG_DATA_L) = 0xFFFFFFFF;
    REG32(CAN_REG_DATA_H) = 0xFFFFFFFF;
    can_rx_interrupt_handler(1010000);

    printf("\n========================================================================\n");
    return 0;
}
