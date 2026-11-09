#include <iostream>
#include <memory>
#include <cstdint>
#include "Vtb_sva.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "ids_driver.h"

uint64_t main_time = 0;

void clock_tick(Vtb_sva* top, VerilatedVcdC* tfp) {
    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(main_time++);

    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(main_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    auto top = std::make_unique<Vtb_sva>();
    auto tfp = std::make_unique<VerilatedVcdC>();

    top->trace(tfp.get(), 99);
    tfp->open("sim/firmware_cosim.vcd");

    // Reset Initialization
    top->rst_n = 0;
    top->clk   = 0;
    top->s_axi_arvalid = 0;
    top->s_axi_rready  = 0;
    top->s_axi_awvalid = 0;
    top->s_axi_wvalid  = 0;
    top->s_axi_bready  = 0;

    for (int i = 0; i < 5; ++i) clock_tick(top.get(), tfp.get());
    top->rst_n = 1;
    clock_tick(top.get(), tfp.get());

    std::cout << "==========================================================" << std::endl;
    std::cout << "  PHASE 5: RISC-V FIRMWARE & HARDWARE CO-SIMULATION       " << std::endl;
    std::cout << "==========================================================" << std::endl;

    // Test 1: Ingest Attack Frame (ID 0x7DF Diagnostic Spoofing)
    std::cout << "\n[CO-SIM TEST 1] Ingesting Attack Frame (ID 0x7DF)..." << std::endl;
    top->can_rx_id        = 0x7DF;
    top->can_rx_dlc       = 8;
    top->can_rx_data_low  = 0x11223344;
    top->can_rx_data_high = 0x0;
    top->can_rx_valid     = 1;
    clock_tick(top.get(), tfp.get());
    top->can_rx_valid     = 0;
    clock_tick(top.get(), tfp.get());

    std::cout << "  HW Interrupt Pin (hw_alert_o): " << (int)top->hw_alert_o << std::endl;

    // Test 2: RISC-V AXI Read of Alert Register (0x20000000)
    std::cout << "\n[CO-SIM TEST 2] RISC-V CPU Reading ALERT Register via AXI4-Lite..." << std::endl;
    top->s_axi_araddr  = IDS_ALERT_BASE_ADDR;
    top->s_axi_arvalid = 1;
    clock_tick(top.get(), tfp.get());
    top->s_axi_arvalid = 0;
    top->s_axi_rready  = 1;
    clock_tick(top.get(), tfp.get());
    
    std::cout << "  AXI Read Data Received by CPU: 0x" << std::hex << top->s_axi_rdata << std::dec << std::endl;
    top->s_axi_rready  = 0;

    // Test 3: RISC-V CPU AXI Write Clear (Writing 0x0 to 0x20000000)
    std::cout << "\n[CO-SIM TEST 3] RISC-V CPU Clearing Interrupt Register via AXI Write..." << std::endl;
    top->s_axi_awaddr  = IDS_ALERT_BASE_ADDR;
    top->s_axi_awvalid = 1;
    top->s_axi_wdata   = 0x00000000;
    top->s_axi_wvalid  = 1;
    top->s_axi_wstrb   = 0xF;
    clock_tick(top.get(), tfp.get());

    top->s_axi_awvalid = 0;
    top->s_axi_wvalid  = 0;
    top->s_axi_bready  = 1;
    clock_tick(top.get(), tfp.get());
    top->s_axi_bready  = 0;
    clock_tick(top.get(), tfp.get());

    std::cout << "  HW Interrupt Pin (hw_alert_o) After Clear: " << (int)top->hw_alert_o;
    if (top->hw_alert_o == 0) {
        std::cout << " [PASSED - Interrupt Cleared by RISC-V Firmware!]" << std::endl;
    } else {
        std::cout << " [FAILED]" << std::endl;
    }

    tfp->close();
    return 0;
}
