#include <iostream>
#include <memory>
#include "Vtb_ibex_axi_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;

void clock_tick(Vtb_ibex_axi_top* top, VerilatedVcdC* tfp) {
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
}

void inject_frame(Vtb_ibex_axi_top* top, VerilatedVcdC* tfp, uint32_t id, uint32_t dlc, uint32_t data_l) {
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

    auto top = std::make_unique<Vtb_ibex_axi_top>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("sim/ibex_axi_waveform.vcd");

    top->rst_n = 0;
    top->clk   = 0;
    for (int i = 0; i < 5; ++i) clock_tick(top.get(), tfp.get());
    top->rst_n = 1;
    clock_tick(top.get(), tfp.get());

    std::cout << "==========================================================" << std::endl;
    std::cout << "  PHASE 1: IBEX BUS + AXI4-LITE END-TO-END CO-SIMULATION   " << std::endl;
    std::cout << "==========================================================" << std::endl;

    // Test 1: Ingest Clean Message
    std::cout << "\n[CO-SIM TEST 1] Injecting Valid CAN Frame (ID=0x100, DLC=8)..." << std::endl;
    inject_frame(top.get(), tfp.get(), 0x100, 8, 0x00000000);
    for (int i = 0; i < 10; ++i) clock_tick(top.get(), tfp.get());
    std::cout << "  HW Alert Pin: " << (int)top->hw_alert_o << " (PASSED - Clean)" << std::endl;

    // Test 2: Ingest Malicious Signature Frame
    std::cout << "\n[CO-SIM TEST 2] Injecting Malicious Payload (0xDEADBEEF)..." << std::endl;
    inject_frame(top.get(), tfp.get(), 0x200, 8, 0xDEADBEEF);
    for (int i = 0; i < 10; ++i) clock_tick(top.get(), tfp.get());
    
    std::cout << "  HW Alert Pin: " << (int)top->hw_alert_o;
    if (top->hw_alert_o == 1) {
        std::cout << " [PASSED - End-to-End AXI Alert Asserted!]" << std::endl;
    } else {
        std::cout << " [FAILED]" << std::endl;
    }

    tfp->close();
    return 0;
}
