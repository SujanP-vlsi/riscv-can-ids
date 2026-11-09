import uvm_pkg::*;
`include "uvm_macros.svh"

class can_agent extends uvm_agent;
    `uvm_component_utils(can_agent)

    can_driver                           driver;
    can_monitor                          monitor;
    uvm_sequencer #(can_seq_item)       sequencer;

    function new(string name = "can_agent", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        monitor = can_monitor::type_id::create("monitor", this);
        if (get_is_active() == UVM_ACTIVE) begin
            driver    = can_driver::type_id::create("driver", this);
            sequencer = uvm_sequencer#(can_seq_item)::type_id::create("sequencer", this);
        end
    endfunction

    function void connect_phase(uvm_phase phase);
        super.connect_phase(phase);
        if (get_is_active() == UVM_ACTIVE) begin
            driver.seq_item_port.connect(sequencer.seq_item_export);
        end
    endfunction
endclass
