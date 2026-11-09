// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_sva__Syms.h"


VL_ATTR_COLD void Vtb_sva___024root__trace_init_sub__TOP__0(Vtb_sva___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+48,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+51,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+55,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+58,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"s_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+61,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"s_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+65,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"s_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"can_rx_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"can_rx_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"can_rx_dlc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"can_rx_data_low",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"can_rx_data_high",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+72,0,"hw_alert_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tb_axi_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+48,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+51,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+55,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+58,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"s_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+61,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"s_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+65,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"s_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"can_rx_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"can_rx_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"can_rx_dlc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"can_rx_data_low",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"can_rx_data_high",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+72,0,"hw_alert_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_ids_axi_lite", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+48,0,"s_axi_aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"s_axi_aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+51,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+55,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+58,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"s_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+61,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"s_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+63,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+65,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"s_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"can_rx_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"can_rx_id",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"can_rx_dlc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"can_rx_data_low",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"can_rx_data_high",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+72,0,"hw_alert_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"can_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"can_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"can_dlc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"can_data_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"can_data_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"ids_alert_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"cycle_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("lut_last_cycle", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+8+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("lut_tag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+24+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+40,0,"lut_valid_flags",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+73,0,"id_slot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+41,0,"can_rx_valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"can_rx_dlc_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+43,0,"s_axi_rvalid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"s_axi_rready_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"s_axi_bvalid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"s_axi_bready_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+47,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_sva___024root__trace_init_top(Vtb_sva___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_init_top\n"); );
    // Body
    Vtb_sva___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_sva___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_sva___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_sva___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_sva___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_sva___024root__trace_register(Vtb_sva___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_sva___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_sva___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_sva___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_sva___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_sva___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_const_0\n"); );
    // Init
    Vtb_sva___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sva___024root*>(voidSelf);
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtb_sva___024root__trace_full_0_sub_0(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_sva___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_full_0\n"); );
    // Init
    Vtb_sva___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sva___024root*>(voidSelf);
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_sva___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_sva___024root__trace_full_0_sub_0(Vtb_sva___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status),32);
    bufp->fullIData(oldp+2,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id),32);
    bufp->fullIData(oldp+3,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc),32);
    bufp->fullIData(oldp+4,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low),32);
    bufp->fullIData(oldp+5,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high),32);
    bufp->fullIData(oldp+6,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg),32);
    bufp->fullIData(oldp+7,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter),32);
    bufp->fullIData(oldp+8,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0]),32);
    bufp->fullIData(oldp+9,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[1]),32);
    bufp->fullIData(oldp+10,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[2]),32);
    bufp->fullIData(oldp+11,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[3]),32);
    bufp->fullIData(oldp+12,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[4]),32);
    bufp->fullIData(oldp+13,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[5]),32);
    bufp->fullIData(oldp+14,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[6]),32);
    bufp->fullIData(oldp+15,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[7]),32);
    bufp->fullIData(oldp+16,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[8]),32);
    bufp->fullIData(oldp+17,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[9]),32);
    bufp->fullIData(oldp+18,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[10]),32);
    bufp->fullIData(oldp+19,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[11]),32);
    bufp->fullIData(oldp+20,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[12]),32);
    bufp->fullIData(oldp+21,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[13]),32);
    bufp->fullIData(oldp+22,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[14]),32);
    bufp->fullIData(oldp+23,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[15]),32);
    bufp->fullIData(oldp+24,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0]),32);
    bufp->fullIData(oldp+25,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[1]),32);
    bufp->fullIData(oldp+26,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[2]),32);
    bufp->fullIData(oldp+27,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[3]),32);
    bufp->fullIData(oldp+28,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[4]),32);
    bufp->fullIData(oldp+29,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[5]),32);
    bufp->fullIData(oldp+30,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[6]),32);
    bufp->fullIData(oldp+31,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[7]),32);
    bufp->fullIData(oldp+32,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[8]),32);
    bufp->fullIData(oldp+33,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[9]),32);
    bufp->fullIData(oldp+34,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[10]),32);
    bufp->fullIData(oldp+35,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[11]),32);
    bufp->fullIData(oldp+36,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[12]),32);
    bufp->fullIData(oldp+37,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[13]),32);
    bufp->fullIData(oldp+38,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[14]),32);
    bufp->fullIData(oldp+39,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[15]),32);
    bufp->fullSData(oldp+40,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags),16);
    bufp->fullBit(oldp+41,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q));
    bufp->fullIData(oldp+42,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q),32);
    bufp->fullBit(oldp+43,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q));
    bufp->fullBit(oldp+44,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q));
    bufp->fullBit(oldp+45,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q));
    bufp->fullBit(oldp+46,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q));
    bufp->fullIData(oldp+47,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+48,(vlSelf->clk));
    bufp->fullBit(oldp+49,(vlSelf->rst_n));
    bufp->fullIData(oldp+50,(vlSelf->s_axi_awaddr),32);
    bufp->fullBit(oldp+51,(vlSelf->s_axi_awvalid));
    bufp->fullBit(oldp+52,(vlSelf->s_axi_awready));
    bufp->fullIData(oldp+53,(vlSelf->s_axi_wdata),32);
    bufp->fullCData(oldp+54,(vlSelf->s_axi_wstrb),4);
    bufp->fullBit(oldp+55,(vlSelf->s_axi_wvalid));
    bufp->fullBit(oldp+56,(vlSelf->s_axi_wready));
    bufp->fullCData(oldp+57,(vlSelf->s_axi_bresp),2);
    bufp->fullBit(oldp+58,(vlSelf->s_axi_bvalid));
    bufp->fullBit(oldp+59,(vlSelf->s_axi_bready));
    bufp->fullIData(oldp+60,(vlSelf->s_axi_araddr),32);
    bufp->fullBit(oldp+61,(vlSelf->s_axi_arvalid));
    bufp->fullBit(oldp+62,(vlSelf->s_axi_arready));
    bufp->fullIData(oldp+63,(vlSelf->s_axi_rdata),32);
    bufp->fullCData(oldp+64,(vlSelf->s_axi_rresp),2);
    bufp->fullBit(oldp+65,(vlSelf->s_axi_rvalid));
    bufp->fullBit(oldp+66,(vlSelf->s_axi_rready));
    bufp->fullBit(oldp+67,(vlSelf->can_rx_valid));
    bufp->fullIData(oldp+68,(vlSelf->can_rx_id),32);
    bufp->fullIData(oldp+69,(vlSelf->can_rx_dlc),32);
    bufp->fullIData(oldp+70,(vlSelf->can_rx_data_low),32);
    bufp->fullIData(oldp+71,(vlSelf->can_rx_data_high),32);
    bufp->fullBit(oldp+72,(vlSelf->hw_alert_o));
    bufp->fullCData(oldp+73,(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot),4);
}
