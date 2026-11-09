#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/weights.h"
#include "../include/simd_mac.h"

// Host-side fallback for SIMD MAC if compiling on x86_64 host without RISC-V toolchain
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

int predict_can_intrusion_accel(float inter_arrival_ms, float id_frequency, float hamming_distance, uint64_t *op_count) {
    *op_count = 0;
    
    // 1. Feature Normalization
    float raw_feat[3] = {inter_arrival_ms, id_frequency, hamming_distance};
    int8_t in_quant[4] = {0, 0, 0, 0}; // Pad 3 features to 4 for 32-bit SIMD alignment
    
    for (int i = 0; i < 3; i++) {
        float norm = (raw_feat[i] - X_MEAN[i]) / X_STD[i];
        if (norm > 127.0f) norm = 127.0f;
        if (norm < -128.0f) norm = -128.0f;
        in_quant[i] = (int8_t)roundf(norm);
    }

    // Pack 4x INT8 inputs into a single 32-bit word for register loading
    uint32_t packed_input = *(uint32_t*)in_quant;

    // 2. Layer 1 Forward Pass (3 -> 8) using SIMD MAC
    int8_t l1_out[8] = {0};
    for (int i = 0; i < L1_OUT; i++) {
        // Pack weights W1[i][0..2] + 0 padding into 32-bit register
        int8_t w_packed_arr[4] = {W1[i][0], W1[i][1], W1[i][2], 0};
        uint32_t packed_w = *(uint32_t*)w_packed_arr;
        
        // SINGLE-CYCLE HARDWARE ACCELERATED SIMD MAC
        int32_t accum = B1[i] + MAC_EXEC(packed_w, packed_input);
        (*op_count)++;

        if (accum < 0) accum = 0; // ReLU
        accum = accum >> 5;
        if (accum > 127) accum = 127;
        l1_out[i] = (int8_t)accum;
    }

    // 3. Layer 2 Forward Pass (8 -> 4) using 2 SIMD MAC executions per output neuron
    int8_t l2_out[4] = {0};
    uint32_t *l1_packed = (uint32_t*)l1_out; // 8 bytes = two 32-bit packed words

    for (int i = 0; i < L2_OUT; i++) {
        uint32_t *w2_packed = (uint32_t*)W2[i]; // 8 weight bytes = two 32-bit words
        
        // 2 SIMD MAC instructions process all 8 inputs
        int32_t accum = B2[i] + MAC_EXEC(w2_packed[0], l1_packed[0]) 
                              + MAC_EXEC(w2_packed[1], l1_packed[1]);
        (*op_count) += 2;

        if (accum < 0) accum = 0; // ReLU
        accum = accum >> 5;
        if (accum > 127) accum = 127;
        l2_out[i] = (int8_t)accum;
    }

    // 4. Layer 3 Forward Pass (4 -> 1) using 1 SIMD MAC execution
    uint32_t *l2_packed = (uint32_t*)l2_out;
    uint32_t *w3_packed = (uint32_t*)W3[0];

    int32_t final_accum = B3[0] + MAC_EXEC(w3_packed[0], l2_packed[0]);
    (*op_count)++;

    return (final_accum > 0) ? 1 : 0;
}
