`timescale 1ns/1ps

module soc_top_axi_lite (
    input  logic        clk_i,
    input  logic        rst_ni,
    
    // External CAN Bus Frame Injection Interface
    input  logic        can_rx_valid_i,
    input  logic [31:0] can_rx_id_i,
    input  logic [31:0] can_rx_payload_i,
    
    // SoC Status Flags
    output logic        ids_alert_o,
    output logic [31:0] sys_cycle_cnt_o
);

    // Internal Memory Mapped Registers
    logic [31:0] can_reg_id;
    logic [31:0] can_reg_payload;
    logic [31:0] spi_reg_txdata;
    logic [64:0] cycle_counter;

    // Execution Stage Signals
    logic [31:0] exec_instr;
    logic [31:0] operand_a;
    logic [31:0] operand_b;
    logic [31:0] alu_result;
    logic        simd_valid;

    // Instantiate Core Execution Stage with SIMD Unit
    riscv_exec_stage u_exec_stage (
        .instr_i      (exec_instr),
        .operand_a_i  (operand_a),
        .operand_b_i  (operand_b),
        .alu_result_o (alu_result),
        .simd_valid_o (simd_valid)
    );

    // System Cycle Counter Logic
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            cycle_counter <= 64'd0;
        end else begin
            cycle_counter <= cycle_counter + 1'b1;
        end
    end
    assign sys_cycle_cnt_o = cycle_counter[31:0];

    // AXI Peripheral Memory Map Read/Write Logic
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            can_reg_id      <= 32'h0;
            can_reg_payload <= 32'h0;
            spi_reg_txdata  <= 32'h0;
            ids_alert_o     <= 1'b0;
        end else begin
            // Ingest incoming CAN frames into Memory Mapped CAN Registers
            if (can_rx_valid_i) begin
                can_reg_id      <= can_rx_id_i;
                can_reg_payload <= can_rx_payload_i;
                
                // Alert trigger condition: High-ID (>= 0x700) or suspicious bit pattern
                if (can_rx_id_i >= 32'h00000700) begin
                    ids_alert_o <= 1'b1;
                end else begin
                    ids_alert_o <= 1'b0;
                end
            end
        end
    end

    // Instruction & Register Forwarding Simulation Logic
    always_comb begin
        exec_instr = 32'h0020800B; // Custom-0 SIMD MAC instruction word
        operand_a  = can_reg_payload;
        operand_b  = 32'h01010101;  // INT8 Unit weight pattern [1, 1, 1, 1]
    end

endmodule
