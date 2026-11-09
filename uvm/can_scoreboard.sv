import uvm_pkg::*;
`include "uvm_macros.svh"

class can_scoreboard extends uvm_scoreboard;
    `uvm_component_utils(can_scoreboard)

    uvm_analysis_imp #(can_seq_item, can_scoreboard) item_collected_export;
    
    int total_frames_checked = 0;
    int total_attacks_detected = 0;

    function new(string name = "can_scoreboard", uvm_component parent = null);
        super.new(name, parent);
        item_collected_export = new("item_collected_export", this);
    endfunction

    function void write(can_seq_item item);
        total_frames_checked++;
        if (item.can_id == 11'h7DF || item.is_attack_frame) begin
            total_attacks_detected++;
            `uvm_info("SCOREBOARD", $sformatf("ATTACK CAN FRAME DETECTED | ID: 0x%03X | Payload: 0x%16X", item.can_id, item.payload), UVM_LOW)
        end else begin
            `uvm_info("SCOREBOARD", $sformatf("NOMINAL CAN FRAME PROCESSED | ID: 0x%03X", item.can_id), UVM_HIGH)
        end
    endfunction

    function void report_phase(uvm_phase phase);
        super.report_phase(phase);
        `uvm_info("SCOREBOARD", $sformatf("========================================================="), UVM_LOW)
        `uvm_info("SCOREBOARD", $sformatf("  UVM SCOREBOARD SUMMARY REPORT                          "), UVM_LOW)
        `uvm_info("SCOREBOARD", $sformatf("========================================================="), UVM_LOW)
        `uvm_info("SCOREBOARD", $sformatf("  Total CAN Frames Monitored : %0d", total_frames_checked), UVM_LOW)
        `uvm_info("SCOREBOARD", $sformatf("  Total Attack Frames Flagged: %0d", total_attacks_detected), UVM_LOW)
        `uvm_info("SCOREBOARD", $sformatf("========================================================="), UVM_LOW)
    endfunction
endclass
