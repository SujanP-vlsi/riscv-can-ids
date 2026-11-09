`timescale 1ns/1ps

module ibex_axi_bridge (
    input  logic        clk,
    input  logic        rst_n,

    // Ibex Data Interface
    input  logic        data_req_i,
    output logic        data_gnt_o,
    output logic        data_rvalid_o,
    input  logic        data_we_i,
    input  logic [3:0]  data_be_i,
    input  logic [31:0] data_addr_i,
    input  logic [31:0] data_wdata_i,
    output logic [31:0] data_rdata_o,

    // AXI4-Lite Master Interface
    output logic [31:0] m_axi_awaddr,
    output logic        m_axi_awvalid,
    input  logic        m_axi_awready,
    output logic [31:0] m_axi_wdata,
    output logic [3:0]  m_axi_wstrb,
    output logic        m_axi_wvalid,
    input  logic        m_axi_wready,
    input  logic [1:0]  m_axi_bresp,
    input  logic        m_axi_bvalid,
    output logic        m_axi_bready,
    output logic [31:0] m_axi_araddr,
    output logic        m_axi_arvalid,
    input  logic        m_axi_arready,
    input  logic [31:0] m_axi_rdata,
    input  logic [1:0]  m_axi_rresp,
    input  logic        m_axi_rvalid,
    output logic        m_axi_rready
);

    typedef enum logic [1:0] { IDLE, WRITE_TX, READ_TX, WAIT_RESP } state_t;
    state_t state;

    assign data_gnt_o = data_req_i && (state == IDLE);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state         <= IDLE;
            m_axi_awvalid <= 1'b0;
            m_axi_wvalid  <= 1'b0;
            m_axi_bready  <= 1'b0;
            m_axi_arvalid <= 1'b0;
            m_axi_rready  <= 1'b0;
            data_rvalid_o <= 1'b0;
            data_rdata_o  <= 32'h0;
            m_axi_awaddr  <= 32'h0;
            m_axi_wdata   <= 32'h0;
            m_axi_wstrb   <= 4'h0;
            m_axi_araddr  <= 32'h0;
        end else begin
            case (state)
                IDLE: begin
                    data_rvalid_o <= 1'b0;
                    if (data_req_i) begin
                        if (data_we_i) begin
                            state         <= WRITE_TX;
                            m_axi_awaddr  <= data_addr_i;
                            m_axi_awvalid <= 1'b1;
                            m_axi_wdata   <= data_wdata_i;
                            m_axi_wstrb   <= data_be_i;
                            m_axi_wvalid  <= 1'b1;
                            m_axi_bready  <= 1'b1;
                        end else begin
                            state         <= READ_TX;
                            m_axi_araddr  <= data_addr_i;
                            m_axi_arvalid <= 1'b1;
                            m_axi_rready  <= 1'b1;
                        end
                    end
                end

                WRITE_TX: begin
                    if (m_axi_awready) m_axi_awvalid <= 1'b0;
                    if (m_axi_wready)  m_axi_wvalid  <= 1'b0;

                    if (m_axi_bvalid && m_axi_bready) begin
                        m_axi_bready  <= 1'b0;
                        data_rvalid_o <= 1'b1;
                        state         <= IDLE;
                    end
                end

                READ_TX: begin
                    if (m_axi_arready) m_axi_arvalid <= 1'b0;

                    if (m_axi_rvalid && m_axi_rready) begin
                        m_axi_rready  <= 1'b0;
                        data_rdata_o  <= m_axi_rdata;
                        data_rvalid_o <= 1'b1;
                        state         <= IDLE;
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
