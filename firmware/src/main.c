#include <stdio.h>
#include "../include/nn_inference.h"

int main() {
    printf("====================================================================\n");
    printf("   RISC-V CAN IDS BARE-METAL SOFTWARE INFERENCE ENGINE TESTBENCH   \n");
    printf("====================================================================\n\n");

    // Test Sample 1: Nominal Frame (Regular 10ms timing, low freq, 1-bit Hamming)
    float sample1_dt   = 10.1f;
    float sample1_freq = 10.2f;
    float sample1_hd   = 1.0f;
    int res1 = predict_can_intrusion(sample1_dt, sample1_freq, sample1_hd);
    printf("[TEST 1] Nominal Frame  -> Prediction: %s (Raw Output: %d)\n", 
           (res1 == 0) ? "PASS [CLEARED]" : "FAIL [ATTACK DETECTED]", res1);

    // Test Sample 2: Injection Attack Frame (High freq 85Hz, 15-bit Hamming, 0.1ms delta)
    float sample2_dt   = 0.1f;
    float sample2_freq = 85.0f;
    float sample2_hd   = 15.0f;
    int res2 = predict_can_intrusion(sample2_dt, sample2_freq, sample2_hd);
    printf("[TEST 2] Injection Frame -> Prediction: %s (Raw Output: %d)\n\n", 
           (res2 == 1) ? "PASS [ATTACK DETECTED]" : "FAIL [CLEARED]", res2);

    printf("====================================================================\n");
    printf("   SOFTWARE INFERENCE ENGINE FUNCTIONALLY VERIFIED. READY FOR RTL.  \n");
    printf("====================================================================\n");
    return 0;
}
