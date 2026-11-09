#include <iostream>
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
    std::cout << "\n[AXI TEST 1] Injecting Malformed CAN Frame (DLC=12)..." << std::endl;
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
    std::cout << "\n[AXI TEST 2] Writing 0x00 to IDS_ALERT_REG via AXI (0x20000000)..." << std::endl;
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
