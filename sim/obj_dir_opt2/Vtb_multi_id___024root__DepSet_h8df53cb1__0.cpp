// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_multi_id.h for the primary calling header

#include "Vtb_multi_id__pch.h"
#include "Vtb_multi_id___024root.h"

VL_INLINE_OPT void Vtb_multi_id___024root___ico_sequent__TOP__0(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot 
        = (0xfU & (vlSelf->can_rx_id ^ ((vlSelf->can_rx_id 
                                         >> 4U) ^ (vlSelf->can_rx_id 
                                                   >> 8U))));
}

void Vtb_multi_id___024root___eval_ico(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtb_multi_id___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtb_multi_id___024root___eval_triggers__ico(Vtb_multi_id___024root* vlSelf);

bool Vtb_multi_id___024root___eval_phase__ico(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtb_multi_id___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtb_multi_id___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtb_multi_id___024root___eval_act(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_multi_id___024root___nba_sequent__TOP__0(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0;
    __Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0;
    __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v1;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v1 = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0;
    __Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0;
    __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v1;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v1 = 0;
    CData/*0:0*/ __Vdly__s_axi_rvalid;
    __Vdly__s_axi_rvalid = 0;
    CData/*0:0*/ __Vdly__s_axi_bvalid;
    __Vdly__s_axi_bvalid = 0;
    // Body
    __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
        = vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    __Vdly__s_axi_bvalid = vlSelf->s_axi_bvalid;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0 = 0U;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v1 = 0U;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0 = 0U;
    __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v1 = 0U;
    __Vdly__s_axi_rvalid = vlSelf->s_axi_rvalid;
    if ((1U & (~ (IData)(vlSelf->rst_n)))) {
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__unnamedblk1__DOT__i = 0x10U;
    }
    vlSelf->s_axi_wready = ((IData)(vlSelf->rst_n) 
                            && ((IData)(vlSelf->s_axi_wvalid) 
                                & (~ (IData)(vlSelf->s_axi_wready))));
    vlSelf->s_axi_awready = ((IData)(vlSelf->rst_n) 
                             && ((IData)(vlSelf->s_axi_awvalid) 
                                 & (~ (IData)(vlSelf->s_axi_awready))));
    vlSelf->s_axi_arready = ((IData)(vlSelf->rst_n) 
                             && ((IData)(vlSelf->s_axi_arvalid) 
                                 & (~ (IData)(vlSelf->s_axi_arready))));
    if (vlSelf->rst_n) {
        __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
            = ((IData)(1U) + vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter);
        if (((IData)(vlSelf->s_axi_arvalid) & (~ (IData)(vlSelf->s_axi_rvalid)))) {
            __Vdly__s_axi_rvalid = 1U;
            vlSelf->s_axi_rresp = 0U;
            vlSelf->s_axi_rdata = ((0x10000000U == vlSelf->s_axi_araddr)
                                    ? vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status
                                    : ((0x10000004U 
                                        == vlSelf->s_axi_araddr)
                                        ? vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id
                                        : ((0x10000008U 
                                            == vlSelf->s_axi_araddr)
                                            ? vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc
                                            : ((0x1000000cU 
                                                == vlSelf->s_axi_araddr)
                                                ? vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low
                                                : (
                                                   (0x10000010U 
                                                    == vlSelf->s_axi_araddr)
                                                    ? vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high
                                                    : 
                                                   ((0x10000014U 
                                                     == vlSelf->s_axi_araddr)
                                                     ? vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter
                                                     : 
                                                    ((0x20000000U 
                                                      == vlSelf->s_axi_araddr)
                                                      ? vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg
                                                      : 0U)))))));
        } else if (((IData)(vlSelf->s_axi_rvalid) & (IData)(vlSelf->s_axi_rready))) {
            __Vdly__s_axi_rvalid = 0U;
        }
        if ((((IData)(vlSelf->s_axi_awvalid) & (IData)(vlSelf->s_axi_wvalid)) 
             & (~ (IData)(vlSelf->s_axi_bvalid)))) {
            __Vdly__s_axi_bvalid = 1U;
            vlSelf->s_axi_bresp = 0U;
            if ((0x20000000U == vlSelf->s_axi_awaddr)) {
                vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg 
                    = vlSelf->s_axi_wdata;
            }
        } else if (((IData)(vlSelf->s_axi_bvalid) & (IData)(vlSelf->s_axi_bready))) {
            __Vdly__s_axi_bvalid = 0U;
        }
        if (vlSelf->can_rx_valid) {
            __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0 
                = vlSelf->can_rx_id;
            __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0 = 1U;
            __Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0 
                = vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot;
            __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0 
                = vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
            __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0 = 1U;
            __Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0 
                = vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status = 1U;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high 
                = vlSelf->can_rx_data_high;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc 
                = vlSelf->can_rx_dlc;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low 
                = vlSelf->can_rx_data_low;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id 
                = vlSelf->can_rx_id;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg 
                = ((((8U < vlSelf->can_rx_dlc) | (0x7dfU 
                                                  == vlSelf->can_rx_id)) 
                    | (0xdeadbeefU == vlSelf->can_rx_data_low))
                    ? 1U : (((((IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags) 
                               >> (IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot)) 
                              & (vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag
                                 [vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot] 
                                 == vlSelf->can_rx_id)) 
                             & (0xfU > (vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
                                        - vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle
                                        [vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot])))
                             ? 1U : 0U));
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags 
                = ((IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags) 
                   | (0xffffU & ((IData)(1U) << (IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot))));
        }
    } else {
        __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter = 0U;
        __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v1 = 1U;
        __Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v1 = 1U;
        __Vdly__s_axi_rvalid = 0U;
        vlSelf->s_axi_rresp = 0U;
        vlSelf->s_axi_rdata = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id = 0U;
        __Vdly__s_axi_bvalid = 0U;
        vlSelf->s_axi_bresp = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags = 0U;
    }
    vlSelf->s_axi_rvalid = __Vdly__s_axi_rvalid;
    vlSelf->s_axi_bvalid = __Vdly__s_axi_bvalid;
    if (__Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0) {
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[__Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0] 
            = __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v0;
    }
    if (__Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag__v1) {
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[1U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[2U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[3U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[4U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[5U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[6U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[7U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[8U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[9U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0xaU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0xbU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0xcU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0xdU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0xeU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0xfU] = 0U;
    }
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
        = __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    if (__Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0) {
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[__Vdlyvdim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0] 
            = __Vdlyvval__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v0;
    }
    if (__Vdlyvset__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle__v1) {
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[1U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[2U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[3U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[4U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[5U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[6U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[7U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[8U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[9U] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0xaU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0xbU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0xcU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0xdU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0xeU] = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0xfU] = 0U;
    }
    vlSelf->hw_alert_o = (1U & vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg);
}

void Vtb_multi_id___024root___eval_nba(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_multi_id___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtb_multi_id___024root___eval_triggers__act(Vtb_multi_id___024root* vlSelf);

bool Vtb_multi_id___024root___eval_phase__act(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_multi_id___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_multi_id___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_multi_id___024root___eval_phase__nba(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_multi_id___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_multi_id___024root___dump_triggers__ico(Vtb_multi_id___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_multi_id___024root___dump_triggers__nba(Vtb_multi_id___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_multi_id___024root___dump_triggers__act(Vtb_multi_id___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_multi_id___024root___eval(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtb_multi_id___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_axi_top.sv", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtb_multi_id___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_multi_id___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_axi_top.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_multi_id___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_axi_top.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_multi_id___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_multi_id___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_multi_id___024root___eval_debug_assertions(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->s_axi_awvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_awvalid");}
    if (VL_UNLIKELY((vlSelf->s_axi_wstrb & 0xf0U))) {
        Verilated::overWidthError("s_axi_wstrb");}
    if (VL_UNLIKELY((vlSelf->s_axi_wvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_wvalid");}
    if (VL_UNLIKELY((vlSelf->s_axi_bready & 0xfeU))) {
        Verilated::overWidthError("s_axi_bready");}
    if (VL_UNLIKELY((vlSelf->s_axi_arvalid & 0xfeU))) {
        Verilated::overWidthError("s_axi_arvalid");}
    if (VL_UNLIKELY((vlSelf->s_axi_rready & 0xfeU))) {
        Verilated::overWidthError("s_axi_rready");}
    if (VL_UNLIKELY((vlSelf->can_rx_valid & 0xfeU))) {
        Verilated::overWidthError("can_rx_valid");}
}
#endif  // VL_DEBUG
