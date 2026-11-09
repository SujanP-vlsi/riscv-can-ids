module soc_top (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [31:0] pc_in,
    input  wire [31:0] instr_in,
    output wire [31:0] alert_telemetry_out
);
    wire [31:0] rs1_dummy = 32'h01020304;
    wire [31:0] rs2_dummy = 32'h05060708;
    wire [31:0] core_rd_out;
    wire        is_simd;

    riscv_core_top u_core (
        .clk           (clk),
        .rst_n         (rst_n),
        .instr_in      (instr_in),
        .reg_rs1_data  (rs1_dummy),
        .reg_rs2_data  (rs2_dummy),
        .reg_rd_data   (core_rd_out),
        .is_simd_instr (is_simd)
    );

    assign alert_telemetry_out = core_rd_out;
endmodule
