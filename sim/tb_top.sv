`timescale 1ns/1ps

module tb_top (
    input  logic        clk,
    input  logic        rst_n,

    input  logic        can_rx_valid,
    input  logic [31:0] can_rx_id,
    input  logic [31:0] can_rx_dlc,
    input  logic [31:0] can_rx_data_low,
    input  logic [31:0] can_rx_data_high,

    output logic [31:0] alert_val
);

    logic [31:0] can_status;
    logic [31:0] can_id;
    logic [31:0] can_dlc;
    logic [31:0] can_data_low;
    logic [31:0] can_data_high;
    logic [31:0] ids_alert_reg;
    logic [31:0] cycle_counter;
    logic [31:0] last_frame_cycle;

    assign alert_val = ids_alert_reg;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cycle_counter    <= 32'h0;
            can_status       <= 32'h0;
            can_id           <= 32'h0;
            can_dlc          <= 32'h0;
            can_data_low     <= 32'h0;
            can_data_high    <= 32'h0;
            ids_alert_reg    <= 32'h0;
            last_frame_cycle <= 32'h0;
        end else begin
            cycle_counter <= cycle_counter + 1'b1;

            if (can_rx_valid) begin
                can_status    <= 32'h1;
                can_id        <= can_rx_id;
                can_dlc       <= can_rx_dlc;
                can_data_low  <= can_rx_data_low;
                can_data_high <= can_rx_data_high;

                // Hardware Anomaly & DoS Rate-Limiting Logic
                if (can_dlc > 8 || can_rx_id == 32'h7DF || can_rx_data_low == 32'hDEADBEEF) begin
                    ids_alert_reg <= 32'h1;
                end else if (last_frame_cycle != 0 && ((cycle_counter - last_frame_cycle) < 15)) begin
                    ids_alert_reg <= 32'h1; // DoS Trigger (< 15 cycles inter-arrival)
                end else begin
                    ids_alert_reg <= 32'h0;
                end

                last_frame_cycle <= cycle_counter;
            end
        end
    end

endmodule
