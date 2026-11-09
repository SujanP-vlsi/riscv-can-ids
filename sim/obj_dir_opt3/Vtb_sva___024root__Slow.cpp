// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sva.h for the primary calling header

#include "Vtb_sva__pch.h"
#include "Vtb_sva__Syms.h"
#include "Vtb_sva___024root.h"

void Vtb_sva___024root___ctor_var_reset(Vtb_sva___024root* vlSelf);

Vtb_sva___024root::Vtb_sva___024root(Vtb_sva__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_sva___024root___ctor_var_reset(this);
}

void Vtb_sva___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_sva___024root::~Vtb_sva___024root() {
}
