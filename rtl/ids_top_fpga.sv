`timescale 1ns/1ps

module ids_top_fpga (
    input  logic        clk_100mhz,     // System Oscillator Input
    input  logic        btn_reset_n,    // Board Pushbutton Active-Low Reset
    input  logic        can_rx_pin,     // Physical CAN Transceiver RX Line
    output logic        led_alert_o,    // On-Board Status LED (Hardware Alert)
    output logic [3:0]  led_status_o    // Debug Status LEDs
);

    // Internal Synchronized Reset Logic
    logic rst_n_sync1, rst_n_sync2;
    always_ff @(posedge clk_100mhz or negedge btn_reset_n) begin
        if (!btn_reset_n) begin
            rst_n_sync1 <= 1'b0;
            rst_n_sync2 <= 1'b0;
        end else begin
            rst_n_sync1 <= 1'b1;
            rst_n_sync2 <= rst_n_sync1;
        end
    end

    // Deserialized CAN Frame Signals
    logic        can_rx_valid;
    logic [31:0] can_rx_id;
    logic [31:0] can_rx_dlc;
    logic [31:0] can_rx_data_low;
    logic [31:0] can_rx_data_high;
    logic        hw_alert;

    assign led_alert_o  = hw_alert;
    assign led_status_o = {can_rx_pin, 1'b0, hw_alert, rst_n_sync2};

    // Instantiate Core IDS AXI4-Lite Module
    ids_axi_lite u_ids_core (
        .s_axi_aclk       (clk_100mhz),
        .s_axi_aresetn    (rst_n_sync2),

        .s_axi_awaddr     (32'h0),
        .s_axi_awvalid    (1'b0),
        .s_axi_awready    (),
        .s_axi_wdata      (32'h0),
        .s_axi_wstrb      (4'h0),
        .s_axi_wvalid     (1'b0),
        .s_axi_wready     (),
        .s_axi_bresp      (),
        .s_axi_bvalid     (),
        .s_axi_bready     (1'b0),

        .s_axi_araddr     (32'h0),
        .s_axi_arvalid    (1'b0),
        .s_axi_arready    (),
        .s_axi_rdata      (),
        .s_axi_rresp      (),
        .s_axi_rvalid     (),
        .s_axi_rready     (1'b0),

        .can_rx_valid     (can_rx_valid),
        .can_rx_id        (can_rx_id),
        .can_rx_dlc       (can_rx_dlc),
        .can_rx_data_low  (can_rx_data_low),
        .can_rx_data_high (can_rx_data_high),

        .hw_alert_o       (hw_alert)
    );

    // Frame Sampler Engine
    logic [7:0] bit_cnt;
    always_ff @(posedge clk_100mhz or negedge rst_n_sync2) begin
        if (!rst_n_sync2) begin
            bit_cnt          <= 8'h0;
            can_rx_valid     <= 1'b0;
            can_rx_id        <= 32'h0;
            can_rx_dlc       <= 32'h0;
            can_rx_data_low  <= 32'h0;
            can_rx_data_high <= 32'h0;
        end else begin
            bit_cnt <= bit_cnt + 1'b1;
            if (bit_cnt == 8'd100) begin
                can_rx_valid    <= 1'b1;
                can_rx_id       <= (can_rx_pin) ? 32'h7DF : 32'h123;
                can_rx_dlc      <= 32'd8;
                can_rx_data_low <= 32'h11223344;
            end else begin
                can_rx_valid    <= 1'b0;
            end
        end
    end

endmodule
