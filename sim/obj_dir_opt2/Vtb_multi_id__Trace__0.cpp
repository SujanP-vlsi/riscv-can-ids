// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_multi_id__Syms.h"


void Vtb_multi_id___024root__trace_chg_0_sub_0(Vtb_multi_id___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_multi_id___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root__trace_chg_0\n"); );
    // Init
    Vtb_multi_id___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_multi_id___024root*>(voidSelf);
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_multi_id___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_multi_id___024root__trace_chg_0_sub_0(Vtb_multi_id___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root__trace_chg_0_sub_0\n"); );
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
        bufp->chgIData(oldp+7,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0]),32);
        bufp->chgIData(oldp+8,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[1]),32);
        bufp->chgIData(oldp+9,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[2]),32);
        bufp->chgIData(oldp+10,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[3]),32);
        bufp->chgIData(oldp+11,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[4]),32);
        bufp->chgIData(oldp+12,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[5]),32);
        bufp->chgIData(oldp+13,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[6]),32);
        bufp->chgIData(oldp+14,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[7]),32);
        bufp->chgIData(oldp+15,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[8]),32);
        bufp->chgIData(oldp+16,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[9]),32);
        bufp->chgIData(oldp+17,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[10]),32);
        bufp->chgIData(oldp+18,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[11]),32);
        bufp->chgIData(oldp+19,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[12]),32);
        bufp->chgIData(oldp+20,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[13]),32);
        bufp->chgIData(oldp+21,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[14]),32);
        bufp->chgIData(oldp+22,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[15]),32);
        bufp->chgIData(oldp+23,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0]),32);
        bufp->chgIData(oldp+24,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[1]),32);
        bufp->chgIData(oldp+25,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[2]),32);
        bufp->chgIData(oldp+26,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[3]),32);
        bufp->chgIData(oldp+27,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[4]),32);
        bufp->chgIData(oldp+28,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[5]),32);
        bufp->chgIData(oldp+29,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[6]),32);
        bufp->chgIData(oldp+30,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[7]),32);
        bufp->chgIData(oldp+31,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[8]),32);
        bufp->chgIData(oldp+32,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[9]),32);
        bufp->chgIData(oldp+33,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[10]),32);
        bufp->chgIData(oldp+34,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[11]),32);
        bufp->chgIData(oldp+35,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[12]),32);
        bufp->chgIData(oldp+36,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[13]),32);
        bufp->chgIData(oldp+37,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[14]),32);
        bufp->chgIData(oldp+38,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[15]),32);
        bufp->chgSData(oldp+39,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags),16);
        bufp->chgIData(oldp+40,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+41,(vlSelf->clk));
    bufp->chgBit(oldp+42,(vlSelf->rst_n));
    bufp->chgIData(oldp+43,(vlSelf->s_axi_awaddr),32);
    bufp->chgBit(oldp+44,(vlSelf->s_axi_awvalid));
    bufp->chgBit(oldp+45,(vlSelf->s_axi_awready));
    bufp->chgIData(oldp+46,(vlSelf->s_axi_wdata),32);
    bufp->chgCData(oldp+47,(vlSelf->s_axi_wstrb),4);
    bufp->chgBit(oldp+48,(vlSelf->s_axi_wvalid));
    bufp->chgBit(oldp+49,(vlSelf->s_axi_wready));
    bufp->chgCData(oldp+50,(vlSelf->s_axi_bresp),2);
    bufp->chgBit(oldp+51,(vlSelf->s_axi_bvalid));
    bufp->chgBit(oldp+52,(vlSelf->s_axi_bready));
    bufp->chgIData(oldp+53,(vlSelf->s_axi_araddr),32);
    bufp->chgBit(oldp+54,(vlSelf->s_axi_arvalid));
    bufp->chgBit(oldp+55,(vlSelf->s_axi_arready));
    bufp->chgIData(oldp+56,(vlSelf->s_axi_rdata),32);
    bufp->chgCData(oldp+57,(vlSelf->s_axi_rresp),2);
    bufp->chgBit(oldp+58,(vlSelf->s_axi_rvalid));
    bufp->chgBit(oldp+59,(vlSelf->s_axi_rready));
    bufp->chgBit(oldp+60,(vlSelf->can_rx_valid));
    bufp->chgIData(oldp+61,(vlSelf->can_rx_id),32);
    bufp->chgIData(oldp+62,(vlSelf->can_rx_dlc),32);
    bufp->chgIData(oldp+63,(vlSelf->can_rx_data_low),32);
    bufp->chgIData(oldp+64,(vlSelf->can_rx_data_high),32);
    bufp->chgBit(oldp+65,(vlSelf->hw_alert_o));
    bufp->chgCData(oldp+66,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot),4);
}

void Vtb_multi_id___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root__trace_cleanup\n"); );
    // Init
    Vtb_multi_id___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_multi_id___024root*>(voidSelf);
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
