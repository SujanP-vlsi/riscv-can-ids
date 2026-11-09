# Vivado Synthesis & Timing Report TCL Script
create_project -in_memory -part xc7a100tcsg324-1

read_verilog -sv rtl/ids_axi_lite.sv
read_xdc constraints/ids_axi_lite.xdc

# Run Out-of-Context Synthesis for Artix-7 FPGA target
synth_design -top ids_axi_lite -part xc7a100tcsg324-1 -mode out_of_context

# Generate timing and resource utilization reports
report_utilization -file reports/utilization.rpt
report_timing_summary -file reports/timing_summary.rpt

puts "[SUCCESS] Vivado synthesis completed. Reports written to reports/ directory."
