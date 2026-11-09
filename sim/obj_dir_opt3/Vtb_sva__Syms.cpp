// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_sva__pch.h"
#include "Vtb_sva.h"
#include "Vtb_sva___024root.h"

// FUNCTIONS
Vtb_sva__Syms::~Vtb_sva__Syms()
{
}

Vtb_sva__Syms::Vtb_sva__Syms(VerilatedContext* contextp, const char* namep, Vtb_sva* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(65);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_axi_top__u_ids_axi_lite.configure(this, name(), "tb_axi_top.u_ids_axi_lite", "u_ids_axi_lite", -9, VerilatedScope::SCOPE_OTHER);
}
