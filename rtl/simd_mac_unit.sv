`timescale 1ns/1ps

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
