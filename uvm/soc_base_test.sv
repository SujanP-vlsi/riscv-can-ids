import uvm_pkg::*;
`include "uvm_macros.svh"

class soc_base_test extends uvm_test;
    `uvm_component_utils(soc_base_test)

    can_env env;

    function new(string name = "soc_base_test", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        env = can_env::type_id::create("env", this);
    endfunction

    task run_phase(uvm_phase phase);
        can_random_seq seq;
        phase.raise_objection(this);
        `uvm_info("TEST", "Starting UVM CAN IDS Verification Test...", UVM_LOW)
        seq = can_random_seq::type_id::create("seq");
        seq.start(env.agent.sequencer);
        #100ns;
        `uvm_info("TEST", "Completed UVM CAN IDS Verification Test.", UVM_LOW)
        phase.drop_objection(this);
    endtask
endclass
