## Artix-7 FPGA (xc7a100tcsg324-1) Pin Constraints
set_property -dict { PACKAGE_PIN E3  IOSTANDARD LVCMOS33 } [get_ports { clk_100mhz }];
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports { clk_100mhz }];

set_property -dict { PACKAGE_PIN C12 IOSTANDARD LVCMOS33 } [get_ports { btn_reset_n }];
set_property -dict { PACKAGE_PIN H17 IOSTANDARD LVCMOS33 } [get_ports { led_alert_o }];

set_property -dict { PACKAGE_PIN J13 IOSTANDARD LVCMOS33 } [get_ports { led_status_o[0] }];
set_property -dict { PACKAGE_PIN N14 IOSTANDARD LVCMOS33 } [get_ports { led_status_o[1] }];
set_property -dict { PACKAGE_PIN R18 IOSTANDARD LVCMOS33 } [get_ports { led_status_o[2] }];
set_property -dict { PACKAGE_PIN V17 IOSTANDARD LVCMOS33 } [get_ports { led_status_o[3] }];

set_property -dict { PACKAGE_PIN D14 IOSTANDARD LVCMOS33 } [get_ports { can_rx_pin }];
