`timescale 1ns/1ps

module ids_axi_lite (
    input  logic        s_axi_aclk,
    input  logic        s_axi_aresetn,

    // AXI4-Lite Write Address Channel
    input  logic [31:0] s_axi_awaddr,
    input  logic        s_axi_awvalid,
    output logic        s_axi_awready,

    // AXI4-Lite Write Data Channel
    input  logic [31:0] s_axi_wdata,
    input  logic [3:0]  s_axi_wstrb,
    input  logic        s_axi_wvalid,
    output logic        s_axi_wready,

    // AXI4-Lite Write Response Channel
    output logic [1:0]  s_axi_bresp,
    output logic        s_axi_bvalid,
    input  logic        s_axi_bready,

    // AXI4-Lite Read Address Channel
    input  logic [31:0] s_axi_araddr,
    input  logic        s_axi_arvalid,
    output logic        s_axi_arready,

    // AXI4-Lite Read Data Channel
    output logic [31:0] s_axi_rdata,
    output logic [1:0]  s_axi_rresp,
    output logic        s_axi_rvalid,
    input  logic        s_axi_rready,

    // CAN Frame Dynamic Inputs
    input  logic        can_rx_valid,
    input  logic [31:0] can_rx_id,
    input  logic [31:0] can_rx_dlc,
    input  logic [31:0] can_rx_data_low,
    input  logic [31:0] can_rx_data_high,

    // Hardware Alert Line Output
    output logic        hw_alert_o
);

    // MMIO Registers
    logic [31:0] can_status;
    logic [31:0] can_id;
    logic [31:0] can_dlc;
    logic [31:0] can_data_low;
    logic [31:0] can_data_high;
    logic [31:0] ids_alert_reg;
    logic [31:0] cycle_counter;

    // Tag-Matched Hardware LUT Table (16 Slots)
    logic [31:0] lut_last_cycle [0:15];
    logic [31:0] lut_tag        [0:15];
    logic [15:0] lut_valid_flags;

    // XOR Hash Indexing
    logic [3:0] id_slot;
    assign id_slot = can_rx_id[3:0] ^ can_rx_id[7:4] ^ can_rx_id[11:8];

    assign hw_alert_o = ids_alert_reg[0];

    // Global Free-Running Cycle Counter
    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            cycle_counter <= 32'h0;
        end else begin
            cycle_counter <= cycle_counter + 1'b1;
        end
    end

    // AXI Write Hit Flag for ALERT Register (0x20000000)
    logic axi_write_alert;
    assign axi_write_alert = s_axi_awvalid && s_axi_wvalid && !s_axi_bvalid && (s_axi_awaddr == 32'h20000000);

    // Consolidated Single-Driver Engine for Anomaly Detection & AXI Write-Back
    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            can_status      <= 32'h0;
            can_id          <= 32'h0;
            can_dlc         <= 32'h0;
            can_data_low    <= 32'h0;
            can_data_high   <= 32'h0;
            ids_alert_reg   <= 32'h0;
            lut_valid_flags <= 16'h0;

            for (int i = 0; i < 16; i++) begin
                lut_last_cycle[i] <= 32'h0;
                lut_tag[i]        <= 32'h0;
            end
        end else begin
            if (can_rx_valid) begin
                can_status    <= 32'h1;
                can_id        <= can_rx_id;
                can_dlc       <= can_rx_dlc;
                can_data_low  <= can_rx_data_low;
                can_data_high <= can_rx_data_high;

                // Anomaly Rules & Tag-Verified Rate Limiting
                if (can_rx_dlc > 8 || can_rx_id == 32'h7DF || can_rx_data_low == 32'hDEADBEEF) begin
                    ids_alert_reg <= 32'h1;
                end else if (lut_valid_flags[id_slot] && 
                           (lut_tag[id_slot] == can_rx_id) && 
                           ((cycle_counter - lut_last_cycle[id_slot]) < 15)) begin
                    ids_alert_reg <= 32'h1;
                end else begin
                    ids_alert_reg <= 32'h0;
                end

                lut_last_cycle[id_slot]  <= cycle_counter;
                lut_tag[id_slot]         <= can_rx_id;
                lut_valid_flags[id_slot] <= 1'b1;
            end else if (axi_write_alert) begin
                ids_alert_reg <= s_axi_wdata; // Host RISC-V AXI Clear / Write-Back
            end
        end
    end

    // AXI Read Channel FSM
    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            s_axi_arready <= 1'b0;
            s_axi_rvalid  <= 1'b0;
            s_axi_rresp   <= 2'b00;
            s_axi_rdata   <= 32'h0;
        end else begin
            if (s_axi_arvalid && !s_axi_arready) s_axi_arready <= 1'b1;
            else s_axi_arready <= 1'b0;

            if (s_axi_arvalid && !s_axi_rvalid) begin
                s_axi_rvalid <= 1'b1;
                s_axi_rresp  <= 2'b00;

                case (s_axi_araddr)
                    32'h10000000: s_axi_rdata <= can_status;
                    32'h10000004: s_axi_rdata <= can_id;
                    32'h10000008: s_axi_rdata <= can_dlc;
                    32'h1000000C: s_axi_rdata <= can_data_low;
                    32'h10000010: s_axi_rdata <= can_data_high;
                    32'h10000014: s_axi_rdata <= cycle_counter;
                    32'h20000000: s_axi_rdata <= ids_alert_reg;
                    default:      s_axi_rdata <= 32'h0;
                endcase
            end else if (s_axi_rvalid && s_axi_rready) begin
                s_axi_rvalid <= 1'b0;
            end
        end
    end

    // AXI Write Channel Handshake FSM
    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            s_axi_bvalid  <= 1'b0;
            s_axi_bresp   <= 2'b00;
        end else begin
            if (s_axi_awvalid && !s_axi_awready) s_axi_awready <= 1'b1;
            else s_axi_awready <= 1'b0;

            if (s_axi_wvalid && !s_axi_wready) s_axi_wready <= 1'b1;
            else s_axi_wready <= 1'b0;

            if (s_axi_awvalid && s_axi_wvalid && !s_axi_bvalid) begin
                s_axi_bvalid <= 1'b1;
                s_axi_bresp  <= 2'b00;
            end else if (s_axi_bvalid && s_axi_bready) begin
                s_axi_bvalid <= 1'b0;
            end
        end
    end

`ifndef SYNTHESIS
    // --- SIMULATION-ONLY SYSTEMVERILOG ASSERTIONS (SVA) ---
    logic        can_rx_valid_q;
    logic [31:0] can_rx_dlc_q;
    logic        s_axi_rvalid_q;
    logic        s_axi_rready_q;
    logic        s_axi_bvalid_q;
    logic        s_axi_bready_q;

    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            can_rx_valid_q <= 1'b0;
            can_rx_dlc_q   <= 32'h0;
            s_axi_rvalid_q <= 1'b0;
            s_axi_rready_q <= 1'b0;
            s_axi_bvalid_q <= 1'b0;
            s_axi_bready_q <= 1'b0;
        end else begin
            can_rx_valid_q <= can_rx_valid;
            can_rx_dlc_q   <= can_rx_dlc;
            s_axi_rvalid_q <= s_axi_rvalid;
            s_axi_rready_q <= s_axi_rready;
            s_axi_bvalid_q <= s_axi_bvalid;
            s_axi_bready_q <= s_axi_bready;
        end
    end

    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (s_axi_aresetn && can_rx_valid_q && (can_rx_dlc_q > 8)) begin
            assert (hw_alert_o == 1'b1) 
                else $error("[SVA VIOLATION] Protocol anomaly failed to assert hw_alert_o on next cycle!");
        end
    end

    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (s_axi_aresetn && s_axi_rvalid_q && !s_axi_rready_q) begin
            assert (s_axi_rvalid == 1'b1) 
                else $error("[SVA VIOLATION] s_axi_rvalid dropped before s_axi_rready was asserted!");
        end
    end

    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (s_axi_aresetn && s_axi_bvalid_q && !s_axi_bready_q) begin
            assert (s_axi_bvalid == 1'b1) 
                else $error("[SVA VIOLATION] s_axi_bvalid dropped before s_axi_bready was asserted!");
        end
    end
`endif

endmodule
