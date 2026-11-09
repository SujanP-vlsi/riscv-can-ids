import uvm_pkg::*;
`include "uvm_macros.svh"

class can_seq_item extends uvm_sequence_item;
    rand bit [10:0] can_id;
    rand bit [3:0]  dlc;
    rand bit [63:0] payload;
    rand bit        is_attack_frame;

    `uvm_object_utils_begin(can_seq_item)
        `uvm_field_int(can_id,          UVM_ALL_ON)
        `uvm_field_int(dlc,             UVM_ALL_ON)
        `uvm_field_int(payload,         UVM_ALL_ON)
        `uvm_field_int(is_attack_frame, UVM_ALL_ON)
    `uvm_object_utils_end

    function new(string name = "can_seq_item");
        super.new(name);
    endfunction

    constraint valid_dlc { dlc == 4'h8; }
    constraint attack_dist { is_attack_frame dist {1 := 20, 0 := 80}; }
endclass
