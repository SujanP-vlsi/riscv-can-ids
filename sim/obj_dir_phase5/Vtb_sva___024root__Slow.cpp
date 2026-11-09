// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sva.h for the primary calling header

#include "Vtb_sva__pch.h"

void Vtb_sva___024root___ctor_var_reset(Vtb_sva___024root* vlSelf);

void Vtb_sva___024root__ctor(Vtb_sva___024root* vlSelf, Vtb_sva__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    Vtb_sva___024root___ctor_var_reset(vlSelf);
}

Vtb_sva___024root::Vtb_sva___024root(Vtb_sva__Syms* symsp, const char* namep) {
    Vtb_sva___024root__ctor(this, symsp, namep);
}

void Vtb_sva___024root__dtor(Vtb_sva___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vtb_sva___024root::~Vtb_sva___024root() {
    Vtb_sva___024root__dtor(this);
}
