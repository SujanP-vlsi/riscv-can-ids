import uvm_pkg::*;
`include "uvm_macros.svh"

class can_driver extends uvm_driver #(can_seq_item);
    `uvm_component_utils(can_driver)

    virtual soc_if vif;

    function new(string name = "can_driver", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if (!uvm_config_db#(virtual soc_if)::get(this, "", "vif", vif))
            `uvm_fatal("DRV", "Could not retrieve virtual interface 'vif' from config_db")
    endfunction

    task run_phase(uvm_phase phase);
        can_seq_item req_item;
        forever begin
            seq_item_port.get_next_item(req_item);
            drive_can_frame(req_item);
            seq_item_port.item_done();
        end
    endtask

    task drive_can_frame(can_seq_item item);
        @(vif.drv_cb);
        vif.drv_cb.can_rx_id   <= item.can_id;
        vif.drv_cb.can_rx_data <= item.payload;
        vif.drv_cb.irq_trigger <= 1'b1;
        @(vif.drv_cb);
        vif.drv_cb.irq_trigger <= 1'b0;
    endtask
endclass
