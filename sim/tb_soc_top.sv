`timescale 1ns/1ps

module tb_soc_top;

    logic        clk;
    logic        rst_n;
    logic        can_rx_valid;
    logic [31:0] can_rx_id;
    logic [31:0] can_rx_payload;
    logic        ids_alert;
    logic [31:0] sys_cycle_cnt;

    // Instantiate SoC Top Module
    soc_top_axi_lite dut (
        .clk_i           (clk),
        .rst_ni          (rst_n),
        .can_rx_valid_i  (can_rx_valid),
        .can_rx_id_i     (can_rx_id),
        .can_rx_payload_i(can_rx_payload),
        .ids_alert_o     (ids_alert),
        .sys_cycle_cnt_o (sys_cycle_cnt)
    );

    // Clock Generator (100 MHz -> 10ns period)
    always #5 clk = ~clk;

    int errors = 0;

    initial begin
        clk           = 0;
        rst_n         = 0;
        can_rx_valid  = 0;
        can_rx_id     = 0;
        can_rx_payload= 0;

        $display("==========================================================================");
        $display("   PHASE 3 / TRACK B: FULL AXI SOC INTEGRATION & PERIPHERAL TESTBENCH      ");
        $display("==========================================================================");

        // Reset Pulse
        #20 rst_n = 1;
        #10;

        // Test Case 1: Ingest Standard CAN Frame (ID: 0x123)
        can_rx_id      = 32'h00000123;
        can_rx_payload = 32'h01020304; // Payload bytes [1, 2, 3, 4]
        can_rx_valid   = 1'b1;
        #10;
        can_rx_valid   = 1'b0;
        #10;

        if (ids_alert === 1'b0) begin
            $display("[PASS Test 1] Nominal Frame (ID 0x123) -> IDS Alert: CLEARED (0)");
        end else begin
            $display("[FAIL Test 1] False positive alert on nominal frame!");
            errors++;
        end

        // Test Case 2: Ingest Suspicious High-ID Injection Frame (ID: 0x7DF)
        can_rx_id      = 32'h000007DF;
        can_rx_payload = 32'h0F0E0D0C;
        can_rx_valid   = 1'b1;
        #10;
        can_rx_valid   = 1'b0;
        #10;

        if (ids_alert === 1'b1) begin
            $display("[PASS Test 2] Attack Frame (ID 0x7DF)    -> IDS Alert: TRIGGERED (1)");
        end else begin
            $display("[FAIL Test 2] Missed attack frame alert!");
            errors++;
        end

        $display("--------------------------------------------------------------------------");
        $display("  System Cycle Count Elapsed: %0d cycles", sys_cycle_cnt);
        if (errors == 0) begin
            $display("   AXI SOC TOP-LEVEL INTERCONNECT VERIFIED SUCCESSFULLY.");
        end else begin
            $display("   SOC VERIFICATION FAILED WITH %0d ERRORS.", errors);
        end
        $display("==========================================================================");
        $finish;
    end

endmodule
