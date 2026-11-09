#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/nn_inference.h"

int predict_can_intrusion(float inter_arrival_ms, float id_frequency, float hamming_distance) {
    // 1. Feature Normalization
    float raw_feat[3] = {inter_arrival_ms, id_frequency, hamming_distance};
    int8_t in_quant[3];
    
    for (int i = 0; i < 3; i++) {
        float norm = (raw_feat[i] - X_MEAN[i]) / X_STD[i];
        // Clip normalized inputs to INT8 range [-128, 127]
        if (norm > 127.0f) norm = 127.0f;
        if (norm < -128.0f) norm = -128.0f;
        in_quant[i] = (int8_t)roundf(norm);
    }

    // 2. Layer 1 Forward Pass (3 -> 8) + ReLU
    int8_t l1_out[L1_OUT];
    for (int i = 0; i < L1_OUT; i++) {
        int32_t accum = B1[i];
        for (int j = 0; j < L1_IN; j++) {
            accum += (int32_t)W1[i][j] * (int32_t)in_quant[j]; // Plain C Multiply-Accumulate
        }
        // ReLU Activation
        if (accum < 0) accum = 0;
        // Scale down accumulator to INT8 range
        accum = accum >> 5; 
        if (accum > 127) accum = 127;
        l1_out[i] = (int8_t)accum;
    }

    // 3. Layer 2 Forward Pass (8 -> 4) + ReLU
    int8_t l2_out[L2_OUT];
    for (int i = 0; i < L2_OUT; i++) {
        int32_t accum = B2[i];
        for (int j = 0; j < L2_IN; j++) {
            accum += (int32_t)W2[i][j] * (int32_t)l1_out[j];
        }
        // ReLU Activation
        if (accum < 0) accum = 0;
        accum = accum >> 5;
        if (accum > 127) accum = 127;
        l2_out[i] = (int8_t)accum;
    }

    // 4. Layer 3 Forward Pass (4 -> 1)
    int32_t final_accum = B3[0];
    for (int j = 0; j < L3_IN; j++) {
        final_accum += (int32_t)W3[0][j] * (int32_t)l2_out[j];
    }

    // Classification Threshold (Positive accumulator indicates attack sample)
    return (final_accum > 0) ? 1 : 0;
}
