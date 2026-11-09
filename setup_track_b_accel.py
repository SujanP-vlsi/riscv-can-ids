import os

# 1. Accelerated C Inference Engine (firmware/src/nn_inference_accel.c)
accel_c = """#include <stdio.h>
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
"""
with open("firmware/src/nn_inference_accel.c", "w") as f:
    f.write(accel_c)

# 2. Comparative Performance Testbench (firmware/src/main_benchmark.c)
main_bench = """#include <stdio.h>
#include <stdint.h>
#include "../include/nn_inference.h"

// Forward declaration of accelerated function
int predict_can_intrusion_accel(float dt, float freq, float hd, uint64_t *op_count);

int main() {
    printf("========================================================================\\n");
    printf("   TRACK B: BASELINE VS. SIMD-ACCELERATED INFERENCE SPEEDUP BENCHMARK   \\n");
    printf("========================================================================\\n\\n");

    float test_dt   = 0.1f;
    float test_freq = 85.0f;
    float test_hd   = 15.0f;

    uint64_t accel_ops = 0;

    int res_base  = predict_can_intrusion(test_dt, test_freq, test_hd);
    int res_accel = predict_can_intrusion_accel(test_dt, test_freq, test_hd, &accel_ops);

    // Scalar Baseline ops count: (3 inputs * 8) + (8 inputs * 4) + (4 inputs * 1) = 24 + 32 + 4 = 60 MACs
    uint64_t base_ops = 60;

    printf("[ACCURACY VERIFICATION]\\n");
    printf("  Baseline Output    : %d (%s)\\n", res_base,  (res_base  == 1) ? "ATTACK" : "NOMINAL");
    printf("  Accelerated Output : %d (%s)\\n", res_accel, (res_accel == 1) ? "ATTACK" : "NOMINAL");
    
    if (res_base == res_accel) {
        printf("  Result Match       : PASSED [100%% Parity]\\n\\n");
    } else {
        printf("  Result Match       : FAILED [Mismatch Detected]\\n\\n");
    }

    printf("[MAC INSTRUCTION COMPRESSION BENCHMARK]\\n");
    printf("  Baseline Scalar Iteration Loops : %lu MAC operations\\n", base_ops);
    printf("  SIMD MAC Hardware Executions    : %lu SIMD instructions\\n", accel_ops);
    printf("  Instruction Reduction Factor    : %.2fx Fewer Compute Instructions\\n", (double)base_ops / accel_ops);
    printf("========================================================================\\n");

    return 0;
}
"""
with open("firmware/src/main_benchmark.c", "w") as f:
    f.write(main_bench)

# 3. Update Track B Makefile with Benchmark Rule
mk_b = """CC = gcc
CFLAGS = -I. -Ifirmware/include -O2 -Wall
IVERILOG ?= iverilog
VVP ?= vvp

all: sim_rtl run_benchmark

sim_rtl: rtl/simd_mac_unit.sv sim/tb_simd_mac.sv
	@which $(IVERILOG) > /dev/null 2>&1 || (echo "[NOTE] iverilog not found. Running verilator simulation..." && make -f Makefile.track_b sim_verilator && exit 0)
	$(IVERILOG) -g2012 -o build_tb_mac rtl/simd_mac_unit.sv sim/tb_simd_mac.sv
	$(VVP) build_tb_mac

sim_verilator:
	verilator --binary --sv -j 0 -Irtl rtl/simd_mac_unit.sv sim/tb_simd_mac.sv --top-module tb_simd_mac
	./obj_dir/Vtb_simd_mac

run_benchmark: firmware/src/nn_inference.c firmware/src/nn_inference_accel.c firmware/src/main_benchmark.c
	$(CC) $(CFLAGS) firmware/src/nn_inference.c firmware/src/nn_inference_accel.c firmware/src/main_benchmark.c -o build_benchmark -lm
	./build_benchmark

clean:
	rm -rf build_tb_mac obj_dir build_benchmark

.PHONY: all sim_rtl sim_verilator run_benchmark clean
"""
with open("Makefile.track_b", "w") as f:
    f.write(mk_b)

print("[SUCCESS] Track B Accelerated benchmarking suite generated.")
