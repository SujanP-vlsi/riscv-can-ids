// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_top__Syms.h"


void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->tb_top__DOT__can_status),32);
        bufp->chgIData(oldp+1,(vlSelf->tb_top__DOT__can_id),32);
        bufp->chgIData(oldp+2,(vlSelf->tb_top__DOT__can_dlc),32);
        bufp->chgIData(oldp+3,(vlSelf->tb_top__DOT__can_data_low),32);
        bufp->chgIData(oldp+4,(vlSelf->tb_top__DOT__can_data_high),32);
        bufp->chgIData(oldp+5,(vlSelf->tb_top__DOT__ids_alert_reg),32);
        bufp->chgIData(oldp+6,(vlSelf->tb_top__DOT__cycle_counter),32);
        bufp->chgIData(oldp+7,(vlSelf->tb_top__DOT__last_frame_cycle),32);
    }
    bufp->chgBit(oldp+8,(vlSelf->clk));
    bufp->chgBit(oldp+9,(vlSelf->rst_n));
    bufp->chgBit(oldp+10,(vlSelf->can_rx_valid));
    bufp->chgIData(oldp+11,(vlSelf->can_rx_id),32);
    bufp->chgIData(oldp+12,(vlSelf->can_rx_dlc),32);
    bufp->chgIData(oldp+13,(vlSelf->can_rx_data_low),32);
    bufp->chgIData(oldp+14,(vlSelf->can_rx_data_high),32);
    bufp->chgIData(oldp+15,(vlSelf->alert_val),32);
}

void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
