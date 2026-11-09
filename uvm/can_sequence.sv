import uvm_pkg::*;
`include "uvm_macros.svh"

class can_random_seq extends uvm_sequence #(can_seq_item);
    `uvm_object_utils(can_random_seq)

    function new(string name = "can_random_seq");
        super.new(name);
    endfunction

    task body();
        can_seq_item item;
        
        // 1. Nominal CAN Frame Traffic Sequence (10 Frames)
        repeat (10) begin
            item = can_seq_item::type_id::create("item");
            start_item(item);
            if (!item.randomize() with { is_attack_frame == 0; can_id == 11'h123; })
                `uvm_fatal("SEQ", "Randomization failed for nominal frame")
            finish_item(item);
        end

        // 2. Intrusion Burst Traffic Sequence (5 Frames)
        repeat (5) begin
            item = can_seq_item::type_id::create("item");
            start_item(item);
            if (!item.randomize() with { is_attack_frame == 1; can_id == 11'h7DF; payload == 64'hFFFFFFFFFFFFFFFF; })
                `uvm_fatal("SEQ", "Randomization failed for attack frame")
            finish_item(item);
        end
    endtask
endclass
