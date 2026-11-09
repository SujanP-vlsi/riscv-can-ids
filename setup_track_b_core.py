import os

os.makedirs("rtl", exist_ok=True)
os.makedirs("sim", exist_ok=True)

# 1. Top-Level Execution Stage with Custom SIMD Opcode Decoder (rtl/riscv_exec_stage.sv)
sv_exec_stage = """`timescale 1ns/1ps

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
"""
with open("rtl/riscv_exec_stage.sv", "w") as f:
    f.write(sv_exec_stage)

# 2. Pipeline Integration Testbench (sim/tb_riscv_exec_stage.sv)
sv_tb_exec = """`timescale 1ns/1ps

module tb_riscv_exec_stage;

    logic [31:0] instr;
    logic [31:0] operand_a;
    logic [31:0] operand_b;
    logic [31:0] alu_result;
    logic        simd_valid;

    // Instantiate Execution Stage
    riscv_exec_stage dut (
        .instr_i      (instr),
        .operand_a_i  (operand_a),
        .operand_b_i  (operand_b),
        .alu_result_o (alu_result),
        .simd_valid_o (simd_valid)
    );

    int errors = 0;

    initial begin
        $display("==========================================================================");
        $display("   TRACK B: RISC-V EXECUTION PIPELINE & OPCODE DECODER INTEGRATION        ");
        $display("==========================================================================");

        // Test 1: Standard ADD Opcode (7'b0110011, funct3: 0)
        instr     = 32'h00000033; // ADD r0, r0, r0
        operand_a = 32'd100;
        operand_b = 32'd50;
        #10;
        if (alu_result === 32'd150 && simd_valid === 1'b0) begin
            $display("[PASS Standard ALU] ADD Opcode (0x33) -> Result: %d, SIMD Flag: %b", alu_result, simd_valid);
        end else begin
            $display("[FAIL Standard ALU] Mismatch in standard opcode dispatch");
            errors++;
        end

        // Test 2: Custom-0 SIMD MAC Opcode (.insn r 0x0B, 0x0, 0x00, rd, rs1, rs2)
        // Encoded R-type instruction with opcode = 7'b0001011 (0x0B)
        instr     = 32'h0020800B; 
        operand_a = 32'h0AFB1402; // [10, -5, 20, 2]
        operand_b = 32'h0304FE0C; // [3, 4, -2, 12]
        #10;
        if ($signed(alu_result) === -6 && simd_valid === 1'b1) begin
            $display("[PASS Custom SIMD]  Opcode (0x0B) -> Result: %d, SIMD Flag: %b", $signed(alu_result), simd_valid);
        end else begin
            $display("[FAIL Custom SIMD]  SIMD instruction not decoded correctly");
            errors++;
        end

        $display("--------------------------------------------------------------------------");
        if (errors == 0) begin
            $display("   CORE DECODE & EXECUTION PIPELINE INTEGRATION VERIFIED.");
        end else begin
            $display("   INTEGRATION FAILED WITH %0d ERRORS.", errors);
        end
        $display("==========================================================================");
        $finish;
    end

endmodule
"""
with open("sim/tb_riscv_exec_stage.sv", "w") as f:
    f.write(sv_tb_exec)

# 3. Update Track B Makefile
mk_b = """IVERILOG ?= iverilog
VVP ?= vvp

all: sim_exec_stage

sim_exec_stage: rtl/simd_mac_unit.sv rtl/riscv_exec_stage.sv sim/tb_riscv_exec_stage.sv
	$(IVERILOG) -g2012 -o build_tb_exec rtl/simd_mac_unit.sv rtl/riscv_exec_stage.sv sim/tb_riscv_exec_stage.sv
	$(VVP) build_tb_exec

clean:
	rm -rf build_tb_exec obj_dir build_benchmark

.PHONY: all sim_exec_stage clean
"""
with open("Makefile.track_b", "w") as f:
    f.write(mk_b)

print("[SUCCESS] Track B CPU pipeline integration generator created.")
