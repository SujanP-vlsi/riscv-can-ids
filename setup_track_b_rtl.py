import os

os.makedirs("rtl", exist_ok=True)
os.makedirs("sim", exist_ok=True)
os.makedirs("firmware/include", exist_ok=True)
os.makedirs("firmware/src", exist_ok=True)

# 1. SystemVerilog 4x INT8 SIMD MAC Hardware Unit (rtl/simd_mac_unit.sv)
sv_mac_unit = """`timescale 1ns/1ps

// ============================================================================
// Module: simd_mac_unit
// Description: Custom RISC-V Custom-0 Execution Unit. Multiplies four pairs
//              of 8-bit signed integers in parallel and accumulates into a
//              32-bit signed result in a single clock cycle.
// ============================================================================
module simd_mac_unit (
    input  logic [31:0] operand_a_i, // rs1: packed 4x INT8 [A3, A2, A1, A0]
    input  logic [31:0] operand_b_i, // rs2: packed 4x INT8 [B3, B2, B1, B0]
    output logic [31:0] result_o     // rd:  32-bit accumulated sum
);

    // Internal signed 8-bit signals and 16-bit intermediate products
    logic signed [7:0]  a_val[4];
    logic signed [7:0]  b_val[4];
    logic signed [15:0] prod[4];

    genvar i;
    generate
        for (i = 0; i < 4; i++) begin : g_simd_mult
            assign a_val[i] = $signed(operand_a_i[8*i +: 8]);
            assign b_val[i] = $signed(operand_b_i[8*i +: 8]);
            assign prod[i]  = a_val[i] * b_val[i];
        end
    endgenerate

    // Sum four 16-bit products into a single 32-bit signed output
    assign result_o = $signed(prod[0]) + $signed(prod[1]) + $signed(prod[2]) + $signed(prod[3]);

endmodule
"""
with open("rtl/simd_mac_unit.sv", "w") as f:
    f.write(sv_mac_unit)

# 2. SystemVerilog RTL Testbench (sim/tb_simd_mac.sv)
sv_tb = """`timescale 1ns/1ps

module tb_simd_mac;

    logic [31:0] operand_a;
    logic [31:0] operand_b;
    logic [31:0] result;

    // Instantiate DUT
    simd_mac_unit dut (
        .operand_a_i (operand_a),
        .operand_b_i (operand_b),
        .result_o    (result)
    );

    int errors = 0;

    // Function calculating expected software sum
    function automatic logic signed [31:0] ref_simd_mac(input logic [31:0] a, input logic [31:0] b);
        logic signed [7:0]  a_b[4];
        logic signed [7:0]  b_b[4];
        logic signed [31:0] sum;
        sum = 0;
        for (int k = 0; k < 4; k++) begin
            a_b[k] = $signed(a[8*k +: 8]);
            b_b[k] = $signed(b[8*k +: 8]);
            sum = sum + (a_b[k] * b_b[k]);
        end
        return sum;
    endfunction

    initial begin
        $display("==========================================================================");
        $display("   PHASE 2 / TRACK B: SIMD MAC HARDWARE EXECUTION UNIT RTL TESTBENCH     ");
        $display("==========================================================================");

        // Test 1: Known Vector Test
        // Vector A: [10, -5, 20,  2]  -> 0x0A, 0xFB, 0x14, 0x02 -> 0x0AFB1402
        // Vector B: [ 3,  4, -2, 12]  -> 0x03, 0x04, 0xFE, 0x0C -> 0x0304FE0C
        // Expected: (10*3) + (-5*4) + (20*-2) + (2*12) = 30 - 20 - 40 + 24 = -6
        operand_a = 32'h0AFB1402;
        operand_b = 32'h0304FE0C;
        #10;
        if ($signed(result) === -6) begin
            $display("[PASS Test 1] Known Operands -> Result: %d (Expected: -6)", $signed(result));
        end else begin
            $display("[FAIL Test 1] Result: %d (Expected: -6)", $signed(result));
            errors++;
        end

        // Test 2: Max Positive Bounds
        operand_a = 32'h7F7F7F7F; // [127, 127, 127, 127]
        operand_b = 32'h7F7F7F7F; // [127, 127, 127, 127]
        #10;
        // 4 * (127 * 127) = 64516
        if ($signed(result) === 64516) begin
            $display("[PASS Test 2] Max Bounds -> Result: %d (Expected: 64516)", $signed(result));
        end else begin
            $display("[FAIL Test 2] Result: %d", $signed(result));
            errors++;
        end

        // Test 3: Random Vector Stimulus Sweep
        for (int t = 0; t < 100; t++) begin
            operand_a = $random;
            operand_b = $random;
            #10;
            if (result !== ref_simd_mac(operand_a, operand_b)) begin
                $display("[FAIL Random Test %0d] A=0x%0h B=0x%0h RTL=%d Ref=%d", 
                         t, operand_a, operand_b, $signed(result), ref_simd_mac(operand_a, operand_b));
                errors++;
            end
        end

        $display("--------------------------------------------------------------------------");
        if (errors == 0) begin
            $display("   ALL 102 RTL STIMULUS TESTS PASSED. HARDWARE MAC UNIT VERIFIED.");
        end else begin
            $display("   TEST SUITE FAILED WITH %0d ERRORS.", errors);
        end
        $display("==========================================================================");
        $finish;
    end

endmodule
"""
with open("sim/tb_simd_mac.sv", "w") as f:
    f.write(sv_tb)

# 3. C Assembly Intrinsic Header (firmware/include/simd_mac.h)
c_intrinsic = """#ifndef SIMD_MAC_H
#define SIMD_MAC_H

#include <stdint.h>

// RISC-V Custom-0 (Opcode 0x0B) Inline Assembly Intrinsic
// Executes hardware 4x INT8 SIMD MAC in 1 clock cycle.
static inline int32_t asm_simd_mac(uint32_t val1, uint32_t val2) {
    int32_t result;
    __asm__ __volatile__ (
        ".insn r 0x0B, 0x0, 0x00, %0, %1, %2 \\n\\t"
        : "=r" (result)
        : "r" (val1), "r" (val2)
    );
    return result;
}

#endif // SIMD_MAC_H
"""
with open("firmware/include/simd_mac.h", "w") as f:
    f.write(c_intrinsic)

# 4. Track B Makefile (Makefile.track_b)
makefile_track_b = """IVERILOG ?= iverilog
VVP ?= vvp

all: sim_rtl

sim_rtl: rtl/simd_mac_unit.sv sim/tb_simd_mac.sv
	@which $(IVERILOG) > /dev/null 2>&1 || (echo "[NOTE] iverilog not found. Using Verilator for RTL verification..." && make -f Makefile.track_b sim_verilator && exit 0)
	$(IVERILOG) -g2012 -o build_tb_mac rtl/simd_mac_unit.sv sim/tb_simd_mac.sv
	$(VVP) build_tb_mac

sim_verilator:
	verilator --binary --sv -j 0 -Irtl rtl/simd_mac_unit.sv sim/tb_simd_mac.sv --top-module tb_simd_mac
	./obj_dir/Vtb_simd_mac

clean:
	rm -rf build_tb_mac obj_dir

.PHONY: all sim_rtl sim_verilator clean
"""
with open("Makefile.track_b", "w") as f:
    f.write(makefile_track_b)

print("[SUCCESS] Track B SystemVerilog RTL and C Intrinsic headers generated.")
