`timescale 1ns/1ps

module tb_ibex_axi_top (
    input  logic        clk,
    input  logic        rst_n,

    // Dynamic CAN Injection Interface
    input  logic        can_rx_valid,
    input  logic [31:0] can_rx_id,
    input  logic [31:0] can_rx_dlc,
    input  logic [31:0] can_rx_data_low,
    input  logic [31:0] can_rx_data_high,

    // Hardware Alert Pin Output
    output logic        hw_alert_o
);

    // SRAM Array (16 KB)
    logic [31:0] mem [0:4095];

    initial begin
        $readmemh("sw/firmware.hex", mem);
    end

    // Interconnect Routing & AXI Signals
    logic        sram_req;
    logic        axi_req;
    logic [31:0] cpu_data_addr;
    logic [31:0] cpu_data_wdata;
    logic        cpu_data_we;
    logic [3:0]  cpu_data_be;
    logic        cpu_data_req;
    logic        cpu_data_gnt;
    logic        cpu_data_rvalid;
    logic [31:0] cpu_data_rdata;

    logic        axi_bridge_gnt;
    logic        axi_bridge_rvalid;
    logic [31:0] axi_bridge_rdata;

    logic [31:0] m_axi_awaddr, m_axi_wdata, m_axi_araddr, m_axi_rdata;
    logic [3:0]  m_axi_wstrb;
    logic [1:0]  m_axi_bresp, m_axi_rresp;
    logic        m_axi_awvalid, m_axi_awready, m_axi_wvalid, m_axi_wready;
    logic        m_axi_bvalid, m_axi_bready, m_axi_arvalid, m_axi_arready;
    logic        m_axi_rvalid, m_axi_rready;

    // Address Decoder Logic
    assign sram_req = cpu_data_req && (cpu_data_addr < 32'h10000000);
    assign axi_req  = cpu_data_req && (cpu_data_addr >= 32'h10000000);

    // Response Muxing
    assign cpu_data_gnt    = sram_req ? 1'b1 : axi_bridge_gnt;
    assign cpu_data_rvalid = sram_req ? 1'b1 : axi_bridge_rvalid;
    assign cpu_data_rdata  = sram_req ? mem[cpu_data_addr[13:2]] : axi_bridge_rdata;

    // SRAM Write Operation
    always_ff @(posedge clk) begin
        if (sram_req && cpu_data_we) begin
            if (cpu_data_be[0]) mem[cpu_data_addr[13:2]][7:0]   <= cpu_data_wdata[7:0];
            if (cpu_data_be[1]) mem[cpu_data_addr[13:2]][15:8]  <= cpu_data_wdata[15:8];
            if (cpu_data_be[2]) mem[cpu_data_addr[13:2]][23:16] <= cpu_data_wdata[23:16];
            if (cpu_data_be[3]) mem[cpu_data_addr[13:2]][31:24] <= cpu_data_wdata[31:24];
        end
    end

    // Host Emulated Processor Memory Master Driver
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cpu_data_req   <= 1'b0;
            cpu_data_we    <= 1'b0;
            cpu_data_addr  <= 32'h0;
            cpu_data_wdata <= 32'h0;
            cpu_data_be    <= 4'h0;
        end
    end

    // Ibex to AXI4-Lite Master Bridge Instantiation
    ibex_axi_bridge u_axi_bridge (
        .clk             ( clk               ),
        .rst_n           ( rst_n             ),
        .data_req_i      ( axi_req           ),
        .data_gnt_o      ( axi_bridge_gnt    ),
        .data_rvalid_o   ( axi_bridge_rvalid ),
        .data_we_i       ( cpu_data_we       ),
        .data_be_i       ( cpu_data_be       ),
        .data_addr_i     ( cpu_data_addr     ),
        .data_wdata_i    ( cpu_data_wdata    ),
        .data_rdata_o    ( axi_bridge_rdata  ),
        .m_axi_awaddr    ( m_axi_awaddr      ),
        .m_axi_awvalid   ( m_axi_awvalid     ),
        .m_axi_awready   ( m_axi_awready     ),
        .m_axi_wdata     ( m_axi_wdata       ),
        .m_axi_wstrb     ( m_axi_wstrb       ),
        .m_axi_wvalid    ( m_axi_wvalid      ),
        .m_axi_wready    ( m_axi_wready      ),
        .m_axi_bresp     ( m_axi_bresp       ),
        .m_axi_bvalid    ( m_axi_bvalid      ),
        .m_axi_bready    ( m_axi_bready      ),
        .m_axi_araddr    ( m_axi_araddr      ),
        .m_axi_arvalid   ( m_axi_arvalid     ),
        .m_axi_arready   ( m_axi_arready     ),
        .m_axi_rdata     ( m_axi_rdata       ),
        .m_axi_rresp     ( m_axi_rresp       ),
        .m_axi_rvalid    ( m_axi_rvalid      ),
        .m_axi_rready    ( m_axi_rready      )
    );

    // Target IDS AXI4-Lite Slave Peripheral Instantiation
    ids_axi_lite u_ids_axi_lite (
        .s_axi_aclk       ( clk              ),
        .s_axi_aresetn    ( rst_n            ),
        .s_axi_awaddr     ( m_axi_awaddr     ),
        .s_axi_awvalid    ( m_axi_awvalid    ),
        .s_axi_awready    ( m_axi_awready    ),
        .s_axi_wdata      ( m_axi_wdata      ),
        .s_axi_wstrb      ( m_axi_wstrb      ),
        .s_axi_wvalid     ( m_axi_wvalid     ),
        .s_axi_wready     ( m_axi_wready     ),
        .s_axi_bresp      ( m_axi_bresp      ),
        .s_axi_bvalid     ( m_axi_bvalid     ),
        .s_axi_bready     ( m_axi_bready     ),
        .s_axi_araddr     ( m_axi_araddr     ),
        .s_axi_arvalid    ( m_axi_arvalid    ),
        .s_axi_arready    ( m_axi_arready    ),
        .s_axi_rdata      ( m_axi_rdata      ),
        .s_axi_rresp      ( m_axi_rresp      ),
        .s_axi_rvalid     ( m_axi_rvalid     ),
        .s_axi_rready     ( m_axi_rready     ),
        .can_rx_valid     ( can_rx_valid     ),
        .can_rx_id        ( can_rx_id        ),
        .can_rx_dlc       ( can_rx_dlc       ),
        .can_rx_data_low  ( can_rx_data_low  ),
        .can_rx_data_high ( can_rx_data_high ),
        .hw_alert_o       ( hw_alert_o       )
    );

endmodule
