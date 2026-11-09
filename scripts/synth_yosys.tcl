# Yosys Generic Gate & LUT Mapping Script
read_verilog -sv rtl/ids_axi_lite.sv
hierarchy -top ids_axi_lite
proc; opt; fsm; opt; techmap; opt

# Synthesize into generic LUTs and Flip-Flops
synth -top ids_axi_lite
stat
