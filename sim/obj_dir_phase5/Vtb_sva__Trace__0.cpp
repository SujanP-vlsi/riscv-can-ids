// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_sva__Syms.h"


void Vtb_sva___024root__trace_chg_0_sub_0(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_sva___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_chg_0\n"); );
    // Body
    Vtb_sva___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sva___024root*>(voidSelf);
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_sva___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void Vtb_sva___024root__trace_chg_dtype____0(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar);
void Vtb_sva___024root__trace_chg_dtype____1(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar);

void Vtb_sva___024root__trace_chg_0_sub_0(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_chg_0_sub_0\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__VtraceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc),32);
        bufp->chgIData(oldp+3,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter),32);
        Vtb_sva___024root__trace_chg_dtype____0(vlSelf, bufp, 7, vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle);
        Vtb_sva___024root__trace_chg_dtype____1(vlSelf, bufp, 23, vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag);
        bufp->chgSData(oldp+39,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags),16);
        bufp->chgBit(oldp+40,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q));
        bufp->chgIData(oldp+41,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q),32);
        bufp->chgBit(oldp+42,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q));
        bufp->chgBit(oldp+43,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q));
        bufp->chgBit(oldp+44,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q));
        bufp->chgBit(oldp+45,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q));
    }
    bufp->chgBit(oldp+46,(vlSelfRef.__VprimaryPorts.clk));
    bufp->chgBit(oldp+47,(vlSelfRef.__VprimaryPorts.rst_n));
    bufp->chgIData(oldp+48,(vlSelfRef.__VprimaryPorts.s_axi_awaddr),32);
    bufp->chgBit(oldp+49,(vlSelfRef.__VprimaryPorts.s_axi_awvalid));
    bufp->chgBit(oldp+50,(vlSelfRef.__VprimaryPorts.s_axi_awready));
    bufp->chgIData(oldp+51,(vlSelfRef.__VprimaryPorts.s_axi_wdata),32);
    bufp->chgCData(oldp+52,(vlSelfRef.__VprimaryPorts.s_axi_wstrb),4);
    bufp->chgBit(oldp+53,(vlSelfRef.__VprimaryPorts.s_axi_wvalid));
    bufp->chgBit(oldp+54,(vlSelfRef.__VprimaryPorts.s_axi_wready));
    bufp->chgCData(oldp+55,(vlSelfRef.__VprimaryPorts.s_axi_bresp),2);
    bufp->chgBit(oldp+56,(vlSelfRef.__VprimaryPorts.s_axi_bvalid));
    bufp->chgBit(oldp+57,(vlSelfRef.__VprimaryPorts.s_axi_bready));
    bufp->chgIData(oldp+58,(vlSelfRef.__VprimaryPorts.s_axi_araddr),32);
    bufp->chgBit(oldp+59,(vlSelfRef.__VprimaryPorts.s_axi_arvalid));
    bufp->chgBit(oldp+60,(vlSelfRef.__VprimaryPorts.s_axi_arready));
    bufp->chgIData(oldp+61,(vlSelfRef.__VprimaryPorts.s_axi_rdata),32);
    bufp->chgCData(oldp+62,(vlSelfRef.__VprimaryPorts.s_axi_rresp),2);
    bufp->chgBit(oldp+63,(vlSelfRef.__VprimaryPorts.s_axi_rvalid));
    bufp->chgBit(oldp+64,(vlSelfRef.__VprimaryPorts.s_axi_rready));
    bufp->chgBit(oldp+65,(vlSelfRef.__VprimaryPorts.can_rx_valid));
    bufp->chgIData(oldp+66,(vlSelfRef.__VprimaryPorts.can_rx_id),32);
    bufp->chgIData(oldp+67,(vlSelfRef.__VprimaryPorts.can_rx_dlc),32);
    bufp->chgIData(oldp+68,(vlSelfRef.__VprimaryPorts.can_rx_data_low),32);
    bufp->chgIData(oldp+69,(vlSelfRef.__VprimaryPorts.can_rx_data_high),32);
    bufp->chgBit(oldp+70,(vlSelfRef.__VprimaryPorts.hw_alert_o));
    bufp->chgCData(oldp+71,(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot),4);
    bufp->chgBit(oldp+72,(((::IData)(vlSelfRef.__VprimaryPorts.s_axi_awvalid) 
                           & ((::IData)(vlSelfRef.__VprimaryPorts.s_axi_wvalid) 
                              & ((~ (::IData)(vlSelfRef.__VprimaryPorts.s_axi_bvalid)) 
                                 & (0x20000000U == vlSelfRef.__VprimaryPorts.s_axi_awaddr))))));
}

void Vtb_sva___024root__trace_chg_dtype____0(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_chg_dtype____0\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
}

void Vtb_sva___024root__trace_chg_dtype____1(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_chg_dtype____1\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
}

void Vtb_sva___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_cleanup\n"); );
    // Body
    Vtb_sva___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sva___024root*>(voidSelf);
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->vlInst.TOP.__VtraceActivity[0U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[1U] = 0U;
}
