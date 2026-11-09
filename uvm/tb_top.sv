import uvm_pkg::*;
`include "uvm_macros.svh"

module tb_top;

    logic clk;
    logic rst_n;

    // 100 MHz Clock Generation
    always #5 clk = ~clk;

    // Instantiate Virtual Interface
    soc_if vif(clk, rst_n);

    // Instantiate SoC Top Unit Under Test (DUT)
    soc_top dut (
        .clk                 (vif.clk),
        .rst_n               (vif.rst_n),
        .pc_in               (vif.pc_in),
        .instr_in            (vif.instr_in),
        .alert_telemetry_out (vif.alert_telemetry)
    );

    initial begin
        clk = 0;
        rst_n = 0;
        #20 rst_n = 1;

        // Register Interface in UVM Config DB
        uvm_config_db#(virtual soc_if)::set(null, "*", "vif", vif);

        // Run Default UVM Test
        run_test("soc_base_test");
    end

endmodule
