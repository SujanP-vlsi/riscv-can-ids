import os

# 1. Update rtl/ids_axi_lite.sv with compliant AXI4-Lite state machines
axi_sv = """`timescale 1ns/1ps

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

    // CAN Frame Hardware Inputs
    input  logic        can_rx_valid,
    input  logic [31:0] can_rx_id,
    input  logic [31:0] can_rx_dlc,
    input  logic [31:0] can_rx_data_low,
    input  logic [31:0] can_rx_data_high,

    // Physical Hardware Alert Pin
    output logic        hw_alert_o
);

    logic [31:0] can_status;
    logic [31:0] can_id;
    logic [31:0] can_dlc;
    logic [31:0] can_data_low;
    logic [31:0] can_data_high;
    logic [31:0] ids_alert_reg;
    logic [31:0] cycle_counter;

    assign hw_alert_o = ids_alert_reg[0];

    // Global Cycle Counter
    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            cycle_counter <= 32'h0;
        end else begin
            cycle_counter <= cycle_counter + 1'b1;
        end
    end

    // --- AXI4-Lite Write Channel FSM ---
    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            s_axi_awready <= 1'b0;
            s_axi_wready  <= 1'b0;
            s_axi_bvalid  <= 1'b0;
            s_axi_bresp   <= 2'b00;
            can_status    <= 32'h0;
            can_id        <= 32'h0;
            can_dlc       <= 32'h0;
            can_data_low  <= 32'h0;
            can_data_high <= 32'h0;
            ids_alert_reg <= 32'h0;
        end else begin
            if (can_rx_valid) begin
                can_status    <= 32'h1;
                can_id        <= can_rx_id;
                can_dlc       <= can_rx_dlc;
                can_data_low  <= can_rx_data_low;
                can_data_high <= can_rx_data_high;

                if (can_rx_dlc > 8 || can_rx_id == 32'h7DF || can_rx_data_low == 32'hDEADBEEF) begin
                    ids_alert_reg <= 32'h1;
                end
            end

            // Write Address Ready Handshake
            if (s_axi_awvalid && !s_axi_awready) s_axi_awready <= 1'b1;
            else s_axi_awready <= 1'b0;

            // Write Data Ready Handshake
            if (s_axi_wvalid && !s_axi_wready) s_axi_wready <= 1'b1;
            else s_axi_wready <= 1'b0;

            // Write Execution
            if (s_axi_awvalid && s_axi_wvalid && !s_axi_bvalid) begin
                s_axi_bvalid <= 1'b1;
                s_axi_bresp  <= 2'b00;

                case (s_axi_awaddr)
                    32'h10000000: can_status    <= s_axi_wdata;
                    32'h20000000: ids_alert_reg <= s_axi_wdata;
                    default: ;
                endcase
            end else if (s_axi_bvalid && s_axi_bready) begin
                s_axi_bvalid <= 1'b0;
            end
        end
    end

    // --- AXI4-Lite Read Channel FSM ---
    always_ff @(posedge s_axi_aclk or negedge s_axi_aresetn) begin
        if (!s_axi_aresetn) begin
            s_axi_arready <= 1'b0;
            s_axi_rvalid  <= 1'b0;
            s_axi_rresp   <= 2'b00;
            s_axi_rdata   <= 32'h0;
        end else begin
            // Address Read Ready Handshake
            if (s_axi_arvalid && !s_axi_arready) begin
                s_axi_arready <= 1'b1;
            end else begin
                s_axi_arready <= 1'b0;
            end

            // Data Read Valid Handshake
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

endmodule
"""
os.makedirs("rtl", exist_ok=True)
with open("rtl/ids_axi_lite.sv", "w") as f:
    f.write(axi_sv)

# 2. Update sim/tb_axi_top.cpp with bounded timeout loops
tb_cpp = """#include <iostream>
#include <memory>
#include "Vtb_axi_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;

void clock_tick(Vtb_axi_top* top, VerilatedVcdC* tfp) {
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
}

// Bounded Non-Blocking AXI Read Helper
uint32_t axi_read(Vtb_axi_top* top, VerilatedVcdC* tfp, uint32_t addr) {
    top->s_axi_araddr  = addr;
    top->s_axi_arvalid = 1;
    top->s_axi_rready  = 1;

    uint32_t read_val = 0;
    bool done = false;

    for (int i = 0; i < 20; ++i) {
        clock_tick(top, tfp);

        if (top->s_axi_arready) {
            top->s_axi_arvalid = 0;
        }
        if (top->s_axi_rvalid && top->s_axi_rready) {
            read_val = top->s_axi_rdata;
            top->s_axi_rready = 0;
            done = true;
            break;
        }
    }

    if (!done) {
        std::cout << "[ERROR] AXI Read Timeout at address 0x" << std::hex << addr << std::dec << std::endl;
    }
    return read_val;
}

// Bounded Non-Blocking AXI Write Helper
void axi_write(Vtb_axi_top* top, VerilatedVcdC* tfp, uint32_t addr, uint32_t data) {
    top->s_axi_awaddr  = addr;
    top->s_axi_awvalid = 1;
    top->s_axi_wdata   = data;
    top->s_axi_wstrb   = 0xF;
    top->s_axi_wvalid  = 1;
    top->s_axi_bready  = 1;

    bool done = false;

    for (int i = 0; i < 20; ++i) {
        clock_tick(top, tfp);

        if (top->s_axi_awready) top->s_axi_awvalid = 0;
        if (top->s_axi_wready)  top->s_axi_wvalid  = 0;

        if (top->s_axi_bvalid && top->s_axi_bready) {
            top->s_axi_bready = 0;
            done = true;
            break;
        }
    }

    if (!done) {
        std::cout << "[ERROR] AXI Write Timeout at address 0x" << std::hex << addr << std::dec << std::endl;
    }
}

void inject_frame(Vtb_axi_top* top, VerilatedVcdC* tfp, uint32_t id, uint32_t dlc, uint32_t data_l) {
    top->can_rx_id        = id;
    top->can_rx_dlc       = dlc;
    top->can_rx_data_low  = data_l;
    top->can_rx_data_high = 0;
    top->can_rx_valid     = 1;
    clock_tick(top, tfp);
    top->can_rx_valid     = 0;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Vtb_axi_top>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("sim/axi_waveform.vcd");

    top->rst_n = 0;
    top->clk   = 0;
    top->s_axi_awvalid = 0;
    top->s_axi_wvalid  = 0;
    top->s_axi_bready  = 0;
    top->s_axi_arvalid = 0;
    top->s_axi_rready  = 0;

    for (int i = 0; i < 5; ++i) clock_tick(top.get(), tfp.get());
    top->rst_n = 1;
    clock_tick(top.get(), tfp.get());

    std::cout << "==========================================================" << std::endl;
    std::cout << "   AXI4-LITE SLAVE PERIPHERAL PROTOCOL VERIFICATION        " << std::endl;
    std::cout << "==========================================================" << std::endl;

    // Test 1: Ingest Malformed Frame and query via AXI Read
    std::cout << "\\n[AXI TEST 1] Injecting Malformed CAN Frame (DLC=12)..." << std::endl;
    inject_frame(top.get(), tfp.get(), 0x100, 12, 0x11223344);

    for (int i = 0; i < 3; ++i) clock_tick(top.get(), tfp.get());

    std::cout << "  Reading CAN_STATUS via AXI (0x10000000)..." << std::endl;
    uint32_t status = axi_read(top.get(), tfp.get(), 0x10000000);
    std::cout << "    Read Value: 0x" << std::hex << status << std::dec << std::endl;

    std::cout << "  Reading IDS_ALERT_REG via AXI (0x20000000)..." << std::endl;
    uint32_t alert_reg = axi_read(top.get(), tfp.get(), 0x20000000);
    std::cout << "    Read Value: 0x" << std::hex << alert_reg << std::dec << std::endl;

    if (alert_reg == 0x1 && top->hw_alert_o == 1) {
        std::cout << "  STATUS: PASSED (AXI Read Verified Alert Assertion)" << std::endl;
    } else {
        std::cout << "  STATUS: FAILED" << std::endl;
    }

    // Test 2: Clear Alert Register via AXI Write
    std::cout << "\\n[AXI TEST 2] Writing 0x00 to IDS_ALERT_REG via AXI (0x20000000)..." << std::endl;
    axi_write(top.get(), tfp.get(), 0x20000000, 0x00000000);

    alert_reg = axi_read(top.get(), tfp.get(), 0x20000000);
    std::cout << "  Post-Write Read Value: 0x" << std::hex << alert_reg << std::dec << std::endl;

    if (alert_reg == 0x0 && top->hw_alert_o == 0) {
        std::cout << "  STATUS: PASSED (AXI Write Successfully Cleared Alert)" << std::endl;
    } else {
        std::cout << "  STATUS: FAILED" << std::endl;
    }

    tfp->close();
    return 0;
}
"""
os.makedirs("sim", exist_ok=True)
with open("sim/tb_axi_top.cpp", "w") as f:
    f.write(tb_cpp)

print("[SUCCESS] AXI handshake fix script executed.")
