// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sva.h for the primary calling header

#include "Vtb_sva__pch.h"
#include "Vtb_sva___024root.h"

VL_ATTR_COLD void Vtb_sva___024root___eval_static(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_sva___024root___eval_initial(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vtb_sva___024root___eval_final(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__stl(Vtb_sva___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_sva___024root___eval_phase__stl(Vtb_sva___024root* vlSelf);

VL_ATTR_COLD void Vtb_sva___024root___eval_settle(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_settle\n"); );
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
            Vtb_sva___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_axi_top.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_sva___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__stl(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sva___024root___stl_sequent__TOP__0(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot 
        = (0xfU & (vlSelf->can_rx_id ^ ((vlSelf->can_rx_id 
                                         >> 4U) ^ (vlSelf->can_rx_id 
                                                   >> 8U))));
    vlSelf->hw_alert_o = (1U & vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg);
}

VL_ATTR_COLD void Vtb_sva___024root___eval_stl(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_sva___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_sva___024root___eval_triggers__stl(Vtb_sva___024root* vlSelf);

VL_ATTR_COLD bool Vtb_sva___024root___eval_phase__stl(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_sva___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_sva___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__ico(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__act(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__nba(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sva___024root___ctor_var_reset(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->s_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->s_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->s_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->s_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->s_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->s_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->s_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->s_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->can_rx_valid = VL_RAND_RESET_I(1);
    vlSelf->can_rx_id = VL_RAND_RESET_I(32);
    vlSelf->can_rx_dlc = VL_RAND_RESET_I(32);
    vlSelf->can_rx_data_low = VL_RAND_RESET_I(32);
    vlSelf->can_rx_data_high = VL_RAND_RESET_I(32);
    vlSelf->hw_alert_o = VL_RAND_RESET_I(1);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status = VL_RAND_RESET_I(32);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id = VL_RAND_RESET_I(32);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc = VL_RAND_RESET_I(32);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low = VL_RAND_RESET_I(32);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high = VL_RAND_RESET_I(32);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = VL_RAND_RESET_I(32);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags = VL_RAND_RESET_I(16);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot = VL_RAND_RESET_I(4);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q = VL_RAND_RESET_I(1);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q = VL_RAND_RESET_I(32);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q = VL_RAND_RESET_I(1);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q = VL_RAND_RESET_I(1);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q = VL_RAND_RESET_I(1);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q = VL_RAND_RESET_I(1);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
