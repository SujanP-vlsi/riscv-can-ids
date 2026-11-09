// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

void Vtb_top___024root___eval_act(Vtb_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__tb_top__DOT__cycle_counter;
    __Vdly__tb_top__DOT__cycle_counter = 0;
    // Body
    __Vdly__tb_top__DOT__cycle_counter = vlSelf->tb_top__DOT__cycle_counter;
    if (vlSelf->rst_n) {
        if (vlSelf->can_rx_valid) {
            vlSelf->tb_top__DOT__can_status = 1U;
            vlSelf->tb_top__DOT__can_data_high = vlSelf->can_rx_data_high;
            vlSelf->tb_top__DOT__can_id = vlSelf->can_rx_id;
            vlSelf->tb_top__DOT__can_data_low = vlSelf->can_rx_data_low;
            vlSelf->tb_top__DOT__ids_alert_reg = ((
                                                   ((8U 
                                                     < vlSelf->tb_top__DOT__can_dlc) 
                                                    | (0x7dfU 
                                                       == vlSelf->can_rx_id)) 
                                                   | (0xdeadbeefU 
                                                      == vlSelf->can_rx_data_low))
                                                   ? 1U
                                                   : 
                                                  (((0U 
                                                     != vlSelf->tb_top__DOT__last_frame_cycle) 
                                                    & (0xfU 
                                                       > 
                                                       (vlSelf->tb_top__DOT__cycle_counter 
                                                        - vlSelf->tb_top__DOT__last_frame_cycle)))
                                                    ? 1U
                                                    : 0U));
            vlSelf->tb_top__DOT__last_frame_cycle = vlSelf->tb_top__DOT__cycle_counter;
            vlSelf->tb_top__DOT__can_dlc = vlSelf->can_rx_dlc;
        }
        __Vdly__tb_top__DOT__cycle_counter = ((IData)(1U) 
                                              + vlSelf->tb_top__DOT__cycle_counter);
    } else {
        vlSelf->tb_top__DOT__can_status = 0U;
        vlSelf->tb_top__DOT__can_data_high = 0U;
        vlSelf->tb_top__DOT__can_id = 0U;
        vlSelf->tb_top__DOT__can_data_low = 0U;
        __Vdly__tb_top__DOT__cycle_counter = 0U;
        vlSelf->tb_top__DOT__ids_alert_reg = 0U;
        vlSelf->tb_top__DOT__last_frame_cycle = 0U;
        vlSelf->tb_top__DOT__can_dlc = 0U;
    }
    vlSelf->tb_top__DOT__cycle_counter = __Vdly__tb_top__DOT__cycle_counter;
    vlSelf->alert_val = vlSelf->tb_top__DOT__ids_alert_reg;
}

void Vtb_top___024root___eval_nba(Vtb_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtb_top___024root___eval_triggers__act(Vtb_top___024root* vlSelf);

bool Vtb_top___024root___eval_phase__act(Vtb_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_top___024root___eval_phase__nba(Vtb_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_top___024root___eval(Vtb_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_top.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_top.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_top___024root___eval_debug_assertions(Vtb_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->can_rx_valid & 0xfeU))) {
        Verilated::overWidthError("can_rx_valid");}
}
#endif  // VL_DEBUG
