module riscv_core_top (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [31:0] instr_in,
    input  wire [31:0] reg_rs1_data,
    input  wire [31:0] reg_rs2_data,
    output wire [31:0] reg_rd_data,
    output wire        is_simd_instr
);
    wire [6:0] opcode = instr_in[6:0];
    assign is_simd_instr = (opcode == 7'h0B);

    wire [31:0] simd_out;
    simd_mac_unit u_simd_unit (
        .operand_a (reg_rs1_data),
        .operand_b (reg_rs2_data),
        .mac_result(simd_out)
    );

    assign reg_rd_data = is_simd_instr ? simd_out : (reg_rs1_data + reg_rs2_data);
endmodule
