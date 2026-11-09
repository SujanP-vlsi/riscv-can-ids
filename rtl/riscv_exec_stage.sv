`timescale 1ns/1ps

module riscv_exec_stage (
    input  logic [31:0] instr_i,        // 32-bit fetched instruction word
    input  logic [31:0] operand_a_i,    // rs1 register value
    input  logic [31:0] operand_b_i,    // rs2 register value
    output logic [31:0] alu_result_o,   // Selected execution output (rd)
    output logic        simd_valid_o    // Flag indicating custom SIMD opcode decoded
);

    // RISC-V Instruction Fields
    logic [6:0] opcode;
    logic [2:0] funct3;

    assign opcode = instr_i[6:0];
    assign funct3 = instr_i[14:12];

    // Decode custom-0 opcode space (7'b0001011) with funct3 = 3'b000
    assign simd_valid_o = (opcode == 7'b0001011) && (funct3 == 3'b000);

    // Sub-module outputs
    logic [31:0] std_alu_result;
    logic [31:0] simd_mac_result;

    // 1. Standard ALU Operations (Basic ADD fallback)
    assign std_alu_result = operand_a_i + operand_b_i;

    // 2. Custom 4x INT8 SIMD MAC Unit Instance
    simd_mac_unit u_simd_mac (
        .operand_a_i (operand_a_i),
        .operand_b_i (operand_b_i),
        .result_o    (simd_mac_result)
    );

    // 3. Execution Multiplexer: Route SIMD result when custom-0 decoded, else standard ALU
    assign alu_result_o = simd_valid_o ? simd_mac_result : std_alu_result;

endmodule
