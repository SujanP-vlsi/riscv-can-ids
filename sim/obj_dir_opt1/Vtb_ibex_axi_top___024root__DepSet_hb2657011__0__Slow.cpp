// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ibex_axi_top.h for the primary calling header

#include "Vtb_ibex_axi_top__pch.h"
#include "Vtb_ibex_axi_top___024root.h"

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_static(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_initial__TOP(Vtb_ibex_axi_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_initial(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_initial\n"); );
    // Body
    Vtb_ibex_axi_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_initial__TOP(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x77617265U;
    __Vtemp_1[2U] = 0x6669726dU;
    __Vtemp_1[3U] = 0x73772fU;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_1)
                 ,  &(vlSelf->tb_ibex_axi_top__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_final(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ibex_axi_top___024root___dump_triggers__stl(Vtb_ibex_axi_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_ibex_axi_top___024root___eval_phase__stl(Vtb_ibex_axi_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_settle(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_ibex_axi_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_ibex_axi_top.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_ibex_axi_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ibex_axi_top___024root___dump_triggers__stl(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___stl_sequent__TOP__0(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->hw_alert_o = (1U & vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg);
    vlSelf->tb_ibex_axi_top__DOT__sram_req = ((IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_req) 
                                              & (0x10000000U 
                                                 > vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr));
    vlSelf->tb_ibex_axi_top__DOT__axi_req = ((IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_req) 
                                             & (0x10000000U 
                                                <= vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr));
}

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_stl(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_ibex_axi_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___eval_triggers__stl(Vtb_ibex_axi_top___024root* vlSelf);

VL_ATTR_COLD bool Vtb_ibex_axi_top___024root___eval_phase__stl(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_ibex_axi_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_ibex_axi_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ibex_axi_top___024root___dump_triggers__act(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ibex_axi_top___024root___dump_triggers__nba(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_ibex_axi_top___024root___ctor_var_reset(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->can_rx_valid = VL_RAND_RESET_I(1);
    vlSelf->can_rx_id = VL_RAND_RESET_I(32);
    vlSelf->can_rx_dlc = VL_RAND_RESET_I(32);
    vlSelf->can_rx_data_low = VL_RAND_RESET_I(32);
    vlSelf->can_rx_data_high = VL_RAND_RESET_I(32);
    vlSelf->hw_alert_o = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_ibex_axi_top__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_ibex_axi_top__DOT__sram_req = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__axi_req = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__cpu_data_be = VL_RAND_RESET_I(4);
    vlSelf->tb_ibex_axi_top__DOT__cpu_data_req = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_status = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_id = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = VL_RAND_RESET_I(32);
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
