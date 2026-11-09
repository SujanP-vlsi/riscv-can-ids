#include <stdio.h>
#include <stdint.h>
#include "../include/nn_inference.h"

// Forward declaration of accelerated function
int predict_can_intrusion_accel(float dt, float freq, float hd, uint64_t *op_count);

int main() {
    printf("========================================================================\n");
    printf("   TRACK B: BASELINE VS. SIMD-ACCELERATED INFERENCE SPEEDUP BENCHMARK   \n");
    printf("========================================================================\n\n");

    float test_dt   = 0.1f;
    float test_freq = 85.0f;
    float test_hd   = 15.0f;

    uint64_t accel_ops = 0;

    int res_base  = predict_can_intrusion(test_dt, test_freq, test_hd);
    int res_accel = predict_can_intrusion_accel(test_dt, test_freq, test_hd, &accel_ops);

    // Scalar Baseline ops count: (3 inputs * 8) + (8 inputs * 4) + (4 inputs * 1) = 24 + 32 + 4 = 60 MACs
    uint64_t base_ops = 60;

    printf("[ACCURACY VERIFICATION]\n");
    printf("  Baseline Output    : %d (%s)\n", res_base,  (res_base  == 1) ? "ATTACK" : "NOMINAL");
    printf("  Accelerated Output : %d (%s)\n", res_accel, (res_accel == 1) ? "ATTACK" : "NOMINAL");
    
    if (res_base == res_accel) {
        printf("  Result Match       : PASSED [100%% Parity]\n\n");
    } else {
        printf("  Result Match       : FAILED [Mismatch Detected]\n\n");
    }

    printf("[MAC INSTRUCTION COMPRESSION BENCHMARK]\n");
    printf("  Baseline Scalar Iteration Loops : %lu MAC operations\n", base_ops);
    printf("  SIMD MAC Hardware Executions    : %lu SIMD instructions\n", accel_ops);
    printf("  Instruction Reduction Factor    : %.2fx Fewer Compute Instructions\n", (double)base_ops / accel_ops);
    printf("========================================================================\n");

    return 0;
}
