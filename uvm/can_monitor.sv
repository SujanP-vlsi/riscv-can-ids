import uvm_pkg::*;
`include "uvm_macros.svh"

class can_monitor extends uvm_monitor;
    `uvm_component_utils(can_monitor)

    virtual soc_if vif;
    uvm_analysis_port #(can_seq_item) item_collected_port;

    function new(string name = "can_monitor", uvm_component parent = null);
        super.new(name, parent);
        item_collected_port = new("item_collected_port", this);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if (!uvm_config_db#(virtual soc_if)::get(this, "", "vif", vif))
            `uvm_fatal("MON", "Could not retrieve virtual interface 'vif' from config_db")
    endfunction

    task run_phase(uvm_phase phase);
        can_seq_item item;
        forever begin
            @(vif.mon_cb);
            if (vif.mon_cb.irq_trigger) begin
                item = can_seq_item::type_id::create("mon_item");
                item.can_id  = vif.mon_cb.can_rx_id;
                item.payload = vif.mon_cb.can_rx_data;
                item_collected_port.write(item);
            end
        end
    endtask
endclass
