read_verilog rtl/simd_mac_unit.v
read_verilog rtl/axi_lite_interconnect.v
read_verilog rtl/riscv_core_top.v
read_verilog rtl/soc_top.v

hierarchy -top soc_top

proc
opt
fsm
opt
techmap
opt

abc -g AND,NAND,OR,NOR,XOR,XNOR,MUX,INV

clean
flatten

stat
write_verilog synthesis/soc_gate_level_netlist.v
