read_verilog -sv rtl/ids_axi_lite.sv
hierarchy -top ids_axi_lite
proc; opt; fsm; opt; techmap; opt
write_verilog -noattr rtl/ids_synth_netlist.v
