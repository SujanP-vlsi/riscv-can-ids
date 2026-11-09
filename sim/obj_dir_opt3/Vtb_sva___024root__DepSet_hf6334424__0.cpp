// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sva.h for the primary calling header

#include "Vtb_sva__pch.h"
#include "Vtb_sva__Syms.h"
#include "Vtb_sva___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__ico(Vtb_sva___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sva___024root___eval_triggers__ico(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sva___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__act(Vtb_sva___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sva___024root___eval_triggers__act(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__rst_n__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sva___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_sva___024root___nba_sequent__TOP__0(Vtb_sva___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___nba_sequent__TOP__0\n"); );
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
    if ((((IData)(vlSelf->rst_n) & (IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q)) 
         & (~ (IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q)))) {
        if (vlSymsp->_vm_contextp__->assertOn()) {
            if (VL_LIKELY((1U & (~ (IData)(vlSelf->s_axi_rvalid))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ids_axi_lite.sv:208: Assertion failed in %Ntb_axi_top.u_ids_axi_lite: [SVA VIOLATION] s_axi_rvalid dropped before s_axi_rready was asserted!\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("/home/sujan/riscv-can-ids/rtl/ids_axi_lite.sv", 208, "");
                }
            }
        }
    }
    if ((((IData)(vlSelf->rst_n) & (IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q)) 
         & (~ (IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q)))) {
        if (vlSymsp->_vm_contextp__->assertOn()) {
            if (VL_LIKELY((1U & (~ (IData)(vlSelf->s_axi_bvalid))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ids_axi_lite.sv:216: Assertion failed in %Ntb_axi_top.u_ids_axi_lite: [SVA VIOLATION] s_axi_bvalid dropped before s_axi_bready was asserted!\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("/home/sujan/riscv-can-ids/rtl/ids_axi_lite.sv", 216, "");
                }
            }
        }
    }
    if ((((IData)(vlSelf->rst_n) & (IData)(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q)) 
         & (8U < vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q))) {
        if (vlSymsp->_vm_contextp__->assertOn()) {
            if (VL_LIKELY((1U & (~ (IData)(vlSelf->hw_alert_o))))) {
                if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                    VL_WRITEF_NX("[%0t] %%Error: ids_axi_lite.sv:200: Assertion failed in %Ntb_axi_top.u_ids_axi_lite: [SVA VIOLATION] Protocol anomaly failed to assert hw_alert_o on next cycle!\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name());
                    VL_STOP_MT("/home/sujan/riscv-can-ids/rtl/ids_axi_lite.sv", 200, "");
                }
            }
        }
    }
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
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q 
            = vlSelf->can_rx_dlc;
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
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low 
                = vlSelf->can_rx_data_low;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id 
                = vlSelf->can_rx_id;
            vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc 
                = vlSelf->can_rx_dlc;
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
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc = 0U;
        __Vdly__s_axi_bvalid = 0U;
        vlSelf->s_axi_bresp = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = 0U;
        vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags = 0U;
    }
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->s_axi_rready));
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->s_axi_rvalid));
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->s_axi_bready));
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->s_axi_bvalid));
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->can_rx_valid));
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
