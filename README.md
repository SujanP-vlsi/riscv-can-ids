# RISC-V CAN Bus Intrusion Detection System (riscv-can-ids)

An end-to-end implementation of a hardware-accelerated Intrusion Detection System (IDS) for Controller Area Networks (CAN) targeting a modified lowRISC Ibex RISC-V core.

## Repository Layout
- rtl/     : SystemVerilog sources (MAC unit, wrapper, decoder modifications)
- sw/      : Bare-metal C code, drivers, and verification benchmarks
- model/   : Python training and quantization scripts
- tb/      : Testbenches (directed and UVM)
- results/ : Cycle counts, coverage reports, metrics
- docs/    : Report and presentation slides
