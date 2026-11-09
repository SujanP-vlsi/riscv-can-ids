`timescale 1ns/1ps

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
