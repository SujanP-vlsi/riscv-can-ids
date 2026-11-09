interface soc_if (input logic clk, input logic rst_n);
    logic [31:0] pc_in;
    logic [31:0] instr_in;
    logic [31:0] alert_telemetry;
    
    logic [10:0] can_rx_id;
    logic [64:0] can_rx_data;
    logic        irq_trigger;

    clocking drv_cb @(posedge clk);
        default input #1ns output #1ns;
        output can_rx_id, can_rx_data, irq_trigger, pc_in, instr_in;
        input  alert_telemetry;
    endclocking

    clocking mon_cb @(posedge clk);
        default input #1ns output #1ns;
        input can_rx_id, can_rx_data, irq_trigger, alert_telemetry;
    endclocking
endinterface
