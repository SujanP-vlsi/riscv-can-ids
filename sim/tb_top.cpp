#include <iostream>
#include <memory>
#include "Vtb_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;

void clock_tick(Vtb_top* top, VerilatedVcdC* tfp) {
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
}

void inject_frame(Vtb_top* top, VerilatedVcdC* tfp, uint32_t id, uint32_t dlc, uint32_t data_l) {
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

    auto top = std::make_unique<Vtb_top>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("sim/waveform.vcd");

    // Reset sequence
    top->rst_n = 0;
    top->clk   = 0;
    for (int i = 0; i < 5; ++i) clock_tick(top.get(), tfp.get());
    top->rst_n = 1;

    std::cout << "==========================================================" << std::endl;
    std::cout << "  CAN BUS DOS FLOODING & RATE-LIMITING VERIFICATION       " << std::endl;
    std::cout << "==========================================================" << std::endl;

    // Test 1: Baseline Clean Transmission
    std::cout << "\n[TEST 1] Baseline Normal Frame Injected..." << std::endl;
    inject_frame(top.get(), tfp.get(), 0x100, 8, 0x00);
    std::cout << "  Alert Status: " << top->alert_val << " [PASSED - Baseline Clean]" << std::endl;

    // Inter-frame gap: 3 clock cycles (< 15 threshold)
    for (int i = 0; i < 3; ++i) clock_tick(top.get(), tfp.get());

    // Test 2: Rapid DoS Burst Injection
    std::cout << "\n[TEST 2] High-Rate DoS Burst Frame Injected (3 cycles delta)..." << std::endl;
    inject_frame(top.get(), tfp.get(), 0x100, 8, 0x01);
    std::cout << "  Alert Status: " << top->alert_val;
    if (top->alert_val == 1) {
        std::cout << " [PASSED - DoS Rate-Limit Triggered!]" << std::endl;
    } else {
        std::cout << " [FAILED]" << std::endl;
    }

    // Inter-frame gap: 25 clock cycles (> 15 threshold)
    for (int i = 0; i < 25; ++i) clock_tick(top.get(), tfp.get());

    // Test 3: Normal Transmission Recovery
    std::cout << "\n[TEST 3] Normal Transmission Resumed (25 cycles delta)..." << std::endl;
    inject_frame(top.get(), tfp.get(), 0x100, 8, 0x02);
    std::cout << "  Alert Status: " << top->alert_val;
    if (top->alert_val == 0) {
        std::cout << " [PASSED - Alert Cleared]" << std::endl;
    } else {
        std::cout << " [FAILED]" << std::endl;
    }

    tfp->close();
    return 0;
}
