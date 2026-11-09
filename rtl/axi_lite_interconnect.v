module axi_lite_interconnect (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [31:0] s_axi_awaddr,
    input  wire        s_axi_awvalid,
    output reg         s_axi_awready,
    input  wire [31:0] s_axi_wdata,
    input  wire        s_axi_wvalid,
    output reg         s_axi_wready,
    output reg  [1:0]  s_axi_bresp,
    output reg         s_axi_bvalid,
    input  wire        s_axi_bready,
    input  wire [31:0] s_axi_araddr,
    input  wire        s_axi_arvalid,
    output reg         s_axi_arready,
    output reg  [31:0] s_axi_rdata,
    output reg  [1:0]  s_axi_rresp,
    output reg         s_axi_rvalid,
    input  wire        s_axi_rready,

    output reg  [31:0] target_addr,
    output reg  [31:0] write_data,
    output reg         write_enable,
    output reg         read_enable,
    input  wire [31:0] read_data
);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            s_axi_bvalid  <= 1'b0;
            s_axi_arready <= 1'b0;
            s_axi_rvalid  <= 1'b0;
            s_axi_rdata   <= 32'h0;
            target_addr   <= 32'h0;
            write_data    <= 32'h0;
            write_enable  <= 1'b0;
            read_enable   <= 1'b0;
        end else begin
            s_axi_awready <= s_axi_awvalid;
            s_axi_wready  <= s_axi_wvalid;
            s_axi_arready <= s_axi_arvalid;

            if (s_axi_awvalid && s_axi_wvalid) begin
                target_addr  <= s_axi_awaddr;
                write_data   <= s_axi_wdata;
                write_enable <= 1'b1;
                s_axi_bvalid <= 1'b1;
            end else begin
                write_enable <= 1'b0;
                if (s_axi_bready) s_axi_bvalid <= 1'b0;
            end

            if (s_axi_arvalid) begin
                target_addr  <= s_axi_araddr;
                read_enable  <= 1'b1;
                s_axi_rdata  <= read_data;
                s_axi_rvalid <= 1'b1;
            end else begin
                read_enable <= 1'b0;
                if (s_axi_rready) s_axi_rvalid <= 1'b0;
            end
        end
    end
endmodule
