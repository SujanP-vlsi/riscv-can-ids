// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_ibex_axi_top__Syms.h"


void Vtb_ibex_axi_top___024root__trace_chg_0_sub_0(Vtb_ibex_axi_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_ibex_axi_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_ibex_axi_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_ibex_axi_top___024root*>(voidSelf);
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_ibex_axi_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_ibex_axi_top___024root__trace_chg_0_sub_0(Vtb_ibex_axi_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rvalid));
        bufp->chgIData(oldp+1,(vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rdata),32);
        bufp->chgIData(oldp+2,(vlSelf->tb_ibex_axi_top__DOT__m_axi_awaddr),32);
        bufp->chgIData(oldp+3,(vlSelf->tb_ibex_axi_top__DOT__m_axi_wdata),32);
        bufp->chgIData(oldp+4,(vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr),32);
        bufp->chgIData(oldp+5,(vlSelf->tb_ibex_axi_top__DOT__m_axi_rdata),32);
        bufp->chgCData(oldp+6,(vlSelf->tb_ibex_axi_top__DOT__m_axi_wstrb),4);
        bufp->chgCData(oldp+7,(vlSelf->tb_ibex_axi_top__DOT__m_axi_bresp),2);
        bufp->chgCData(oldp+8,(vlSelf->tb_ibex_axi_top__DOT__m_axi_rresp),2);
        bufp->chgBit(oldp+9,(vlSelf->tb_ibex_axi_top__DOT__m_axi_awvalid));
        bufp->chgBit(oldp+10,(vlSelf->tb_ibex_axi_top__DOT__m_axi_awready));
        bufp->chgBit(oldp+11,(vlSelf->tb_ibex_axi_top__DOT__m_axi_wvalid));
        bufp->chgBit(oldp+12,(vlSelf->tb_ibex_axi_top__DOT__m_axi_wready));
        bufp->chgBit(oldp+13,(vlSelf->tb_ibex_axi_top__DOT__m_axi_bvalid));
        bufp->chgBit(oldp+14,(vlSelf->tb_ibex_axi_top__DOT__m_axi_bready));
        bufp->chgBit(oldp+15,(vlSelf->tb_ibex_axi_top__DOT__m_axi_arvalid));
        bufp->chgBit(oldp+16,(vlSelf->tb_ibex_axi_top__DOT__m_axi_arready));
        bufp->chgBit(oldp+17,(vlSelf->tb_ibex_axi_top__DOT__m_axi_rvalid));
        bufp->chgBit(oldp+18,(vlSelf->tb_ibex_axi_top__DOT__m_axi_rready));
        bufp->chgCData(oldp+19,(vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state),2);
        bufp->chgIData(oldp+20,(vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_status),32);
        bufp->chgIData(oldp+21,(vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_id),32);
        bufp->chgIData(oldp+22,(vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc),32);
        bufp->chgIData(oldp+23,(vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low),32);
        bufp->chgIData(oldp+24,(vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high),32);
        bufp->chgIData(oldp+25,(vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg),32);
        bufp->chgIData(oldp+26,(vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+27,(vlSelf->tb_ibex_axi_top__DOT__sram_req));
        bufp->chgBit(oldp+28,(vlSelf->tb_ibex_axi_top__DOT__axi_req));
        bufp->chgIData(oldp+29,(vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr),32);
        bufp->chgBit(oldp+30,(vlSelf->tb_ibex_axi_top__DOT__cpu_data_req));
        bufp->chgCData(oldp+31,(vlSelf->tb_ibex_axi_top__DOT__cpu_data_be),4);
    }
    bufp->chgBit(oldp+32,(vlSelf->clk));
    bufp->chgBit(oldp+33,(vlSelf->rst_n));
    bufp->chgBit(oldp+34,(vlSelf->can_rx_valid));
    bufp->chgIData(oldp+35,(vlSelf->can_rx_id),32);
    bufp->chgIData(oldp+36,(vlSelf->can_rx_dlc),32);
    bufp->chgIData(oldp+37,(vlSelf->can_rx_data_low),32);
    bufp->chgIData(oldp+38,(vlSelf->can_rx_data_high),32);
    bufp->chgBit(oldp+39,(vlSelf->hw_alert_o));
    bufp->chgBit(oldp+40,(((IData)(vlSelf->tb_ibex_axi_top__DOT__sram_req) 
                           | ((IData)(vlSelf->tb_ibex_axi_top__DOT__axi_req) 
                              & (0U == (IData)(vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state))))));
    bufp->chgBit(oldp+41,(((IData)(vlSelf->tb_ibex_axi_top__DOT__sram_req) 
                           | (IData)(vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rvalid))));
    bufp->chgIData(oldp+42,(((IData)(vlSelf->tb_ibex_axi_top__DOT__sram_req)
                              ? vlSelf->tb_ibex_axi_top__DOT__mem
                             [(0xfffU & (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                                         >> 2U))] : vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rdata)),32);
    bufp->chgBit(oldp+43,(((IData)(vlSelf->tb_ibex_axi_top__DOT__axi_req) 
                           & (0U == (IData)(vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state)))));
}

void Vtb_ibex_axi_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_ibex_axi_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_ibex_axi_top___024root*>(voidSelf);
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
