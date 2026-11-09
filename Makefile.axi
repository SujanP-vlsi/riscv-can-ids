VERILATOR := verilator

SIM_DIR := sim
SIM_SV  := $(abspath $(SIM_DIR)/tb_axi_top.sv)
SIM_CPP := $(abspath $(SIM_DIR)/tb_axi_top.cpp)
RTL_SV  := $(abspath rtl/ids_axi_lite.sv)

sim-axi-build:
	$(VERILATOR) --trace -Wall -Wno-UNUSEDSIGNAL -Wno-UNDRIVEN -Irtl --top-module tb_axi_top --cc $(SIM_SV) $(RTL_SV) --exe $(SIM_CPP) --Mdir sim/obj_dir_axi -o Vtb_axi_top
	make -C sim/obj_dir_axi -f Vtb_axi_top.mk Vtb_axi_top

sim-axi: sim-axi-build
	./sim/obj_dir_axi/Vtb_axi_top

synth:
	@which yosys > /dev/null 2>&1 || (echo "[ERROR] Yosys is not installed on this system. Install via package manager or run simulation only." && exit 1)
	yosys -s scripts/synth.tcl

clean-axi:
	rm -rf sim/obj_dir_axi sim/axi_waveform.vcd fix_axi.py

.PHONY: sim-axi-build sim-axi synth clean-axi
