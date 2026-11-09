// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_axi_top__Syms.h"


void Vtb_axi_top___024root__trace_chg_0_sub_0(Vtb_axi_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_axi_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axi_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_axi_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_axi_top___024root*>(voidSelf);
    Vtb_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_axi_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_axi_top___024root__trace_chg_0_sub_0(Vtb_axi_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axi_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status),32);
        bufp->chgIData(oldp+1,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id),32);
        bufp->chgIData(oldp+2,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc),32);
        bufp->chgIData(oldp+3,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low),32);
        bufp->chgIData(oldp+4,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high),32);
        bufp->chgIData(oldp+5,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg),32);
        bufp->chgIData(oldp+6,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter),32);
    }
    bufp->chgBit(oldp+7,(vlSelf->clk));
    bufp->chgBit(oldp+8,(vlSelf->rst_n));
    bufp->chgIData(oldp+9,(vlSelf->s_axi_awaddr),32);
    bufp->chgBit(oldp+10,(vlSelf->s_axi_awvalid));
    bufp->chgBit(oldp+11,(vlSelf->s_axi_awready));
    bufp->chgIData(oldp+12,(vlSelf->s_axi_wdata),32);
    bufp->chgCData(oldp+13,(vlSelf->s_axi_wstrb),4);
    bufp->chgBit(oldp+14,(vlSelf->s_axi_wvalid));
    bufp->chgBit(oldp+15,(vlSelf->s_axi_wready));
    bufp->chgCData(oldp+16,(vlSelf->s_axi_bresp),2);
    bufp->chgBit(oldp+17,(vlSelf->s_axi_bvalid));
    bufp->chgBit(oldp+18,(vlSelf->s_axi_bready));
    bufp->chgIData(oldp+19,(vlSelf->s_axi_araddr),32);
    bufp->chgBit(oldp+20,(vlSelf->s_axi_arvalid));
    bufp->chgBit(oldp+21,(vlSelf->s_axi_arready));
    bufp->chgIData(oldp+22,(vlSelf->s_axi_rdata),32);
    bufp->chgCData(oldp+23,(vlSelf->s_axi_rresp),2);
    bufp->chgBit(oldp+24,(vlSelf->s_axi_rvalid));
    bufp->chgBit(oldp+25,(vlSelf->s_axi_rready));
    bufp->chgBit(oldp+26,(vlSelf->can_rx_valid));
    bufp->chgIData(oldp+27,(vlSelf->can_rx_id),32);
    bufp->chgIData(oldp+28,(vlSelf->can_rx_dlc),32);
    bufp->chgIData(oldp+29,(vlSelf->can_rx_data_low),32);
    bufp->chgIData(oldp+30,(vlSelf->can_rx_data_high),32);
    bufp->chgBit(oldp+31,(vlSelf->hw_alert_o));
}

void Vtb_axi_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_axi_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_axi_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_axi_top___024root*>(voidSelf);
    Vtb_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
