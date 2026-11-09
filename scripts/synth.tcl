# Yosys Synthesis Script for IDS AXI-Lite Core
read_verilog -sv rtl/ids_axi_lite.sv
hierarchy -top ids_axi_lite
proc; opt; fsm; opt; techmap; opt

# Generic Synthesis Mapping
synth -top ids_axi_lite
stat
