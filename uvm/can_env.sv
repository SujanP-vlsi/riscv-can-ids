import uvm_pkg::*;
`include "uvm_macros.svh"

class can_env extends uvm_env;
    `uvm_component_utils(can_env)

    can_agent      agent;
    can_scoreboard scoreboard;

    function new(string name = "can_env", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        agent      = can_agent::type_id::create("agent", this);
        scoreboard = can_scoreboard::type_id::create("scoreboard", this);
    endfunction

    function void connect_phase(uvm_phase phase);
        super.connect_phase(phase);
        agent.monitor.item_collected_port.connect(scoreboard.item_collected_export);
    endfunction
endclass
