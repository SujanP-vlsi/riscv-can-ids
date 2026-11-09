# Xilinx Artix-7 Timing Constraint (100 MHz Clock Target)
create_clock -period 10.000 -name s_axi_aclk [get_ports s_axi_aclk]

# Input / Output Delays for Out-Of-Context Synthesis
set_input_delay -clock s_axi_aclk 2.000 [get_ports {s_axi_awvalid s_axi_wvalid s_axi_arvalid s_axi_rready s_axi_bready can_rx_valid}]
set_output_delay -clock s_axi_aclk 2.000 [get_ports {s_axi_awready s_axi_wready s_axi_arready s_axi_rvalid s_axi_bvalid hw_alert_o}]
