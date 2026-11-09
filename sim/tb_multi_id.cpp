#include <iostream>
#include <memory>
#include "Vtb_multi_id.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;

void clock_tick(Vtb_multi_id* top, VerilatedVcdC* tfp) {
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
}

void inject_frame(Vtb_multi_id* top, VerilatedVcdC* tfp, uint32_t id, uint32_t dlc, uint32_t data_l) {
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

    auto top = std::make_unique<Vtb_multi_id>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("sim/multi_id_waveform.vcd");

    top->rst_n = 0;
    top->clk   = 0;
    for (int i = 0; i < 5; ++i) clock_tick(top.get(), tfp.get());
    top->rst_n = 1;
    clock_tick(top.get(), tfp.get());

    std::cout << "==========================================================" << std::endl;
    std::cout << "  PHASE 2: MULTI-ID CONCURRENT HARDWARE RATE-LIMITING     " << std::endl;
    std::cout << "==========================================================" << std::endl;

    // Test 1: Interleaved Frames (ID 0x100 followed immediately by ID 0x200 after 2 cycles)
    std::cout << "\n[TEST 1] Interleaved Injection (ID 0x100 then ID 0x200 after 2 cycles)..." << std::endl;
    inject_frame(top.get(), tfp.get(), 0x100, 8, 0x1111);
    
    for (int i = 0; i < 2; ++i) clock_tick(top.get(), tfp.get());

    inject_frame(top.get(), tfp.get(), 0x200, 8, 0x2222);
    clock_tick(top.get(), tfp.get());

    std::cout << "  HW Alert Pin: " << (int)top->hw_alert_o;
    if (top->hw_alert_o == 0) {
        std::cout << " [PASSED - No False Alarm for Interleaved Distinct IDs]" << std::endl;
    } else {
        std::cout << " [FAILED - False Alarm Triggered]" << std::endl;
    }

    // Test 2: Rapid Burst on Same ID (ID 0x100 repeated after only 3 cycles)
    std::cout << "\n[TEST 2] High-Rate DoS Burst on ID 0x100 (3 cycles delta)..." << std::endl;
    for (int i = 0; i < 2; ++i) clock_tick(top.get(), tfp.get());
    inject_frame(top.get(), tfp.get(), 0x100, 8, 0x3333);
    clock_tick(top.get(), tfp.get());

    std::cout << "  HW Alert Pin: " << (int)top->hw_alert_o;
    if (top->hw_alert_o == 1) {
        std::cout << " [PASSED - Per-ID DoS Alert Correctly Asserted!]" << std::endl;
    } else {
        std::cout << " [FAILED]" << std::endl;
    }

    tfp->close();
    return 0;
}
