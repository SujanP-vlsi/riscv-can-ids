// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ibex_axi_top.h for the primary calling header

#include "Vtb_ibex_axi_top__pch.h"
#include "Vtb_ibex_axi_top___024root.h"

void Vtb_ibex_axi_top___024root___eval_act(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_ibex_axi_top___024root___nba_sequent__TOP__0(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state;
    __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = 0;
    CData/*0:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_bready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_bready = 0;
    CData/*0:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_rready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_rready = 0;
    IData/*31:0*/ __Vdly__tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    __Vdly__tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter = 0;
    CData/*0:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_bvalid;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_bvalid = 0;
    CData/*0:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_awready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_awready = 0;
    CData/*0:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_wready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_wready = 0;
    CData/*0:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_arready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_arready = 0;
    CData/*0:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_rvalid;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_rvalid = 0;
    IData/*31:0*/ __Vdly__tb_ibex_axi_top__DOT__m_axi_rdata;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_rdata = 0;
    // Body
    __Vdly__tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
        = vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_rready = vlSelf->tb_ibex_axi_top__DOT__m_axi_rready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_bready = vlSelf->tb_ibex_axi_top__DOT__m_axi_bready;
    __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state 
        = vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_arready = vlSelf->tb_ibex_axi_top__DOT__m_axi_arready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_wready = vlSelf->tb_ibex_axi_top__DOT__m_axi_wready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_awready = vlSelf->tb_ibex_axi_top__DOT__m_axi_awready;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_bvalid = vlSelf->tb_ibex_axi_top__DOT__m_axi_bvalid;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_rdata = vlSelf->tb_ibex_axi_top__DOT__m_axi_rdata;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_rvalid = vlSelf->tb_ibex_axi_top__DOT__m_axi_rvalid;
    __Vdly__tb_ibex_axi_top__DOT__m_axi_arready = ((IData)(vlSelf->rst_n) 
                                                   && ((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_arvalid) 
                                                       & (~ (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_arready))));
    __Vdly__tb_ibex_axi_top__DOT__m_axi_wready = ((IData)(vlSelf->rst_n) 
                                                  && ((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_wvalid) 
                                                      & (~ (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_wready))));
    __Vdly__tb_ibex_axi_top__DOT__m_axi_awready = ((IData)(vlSelf->rst_n) 
                                                   && ((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_awvalid) 
                                                       & (~ (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_awready))));
    if (vlSelf->rst_n) {
        __Vdly__tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
            = ((IData)(1U) + vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter);
        if (((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_arvalid) 
             & (~ (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_rvalid)))) {
            __Vdly__tb_ibex_axi_top__DOT__m_axi_rvalid = 1U;
            vlSelf->tb_ibex_axi_top__DOT__m_axi_rresp = 0U;
            __Vdly__tb_ibex_axi_top__DOT__m_axi_rdata 
                = ((0x10000000U == vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr)
                    ? vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_status
                    : ((0x10000004U == vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr)
                        ? vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_id
                        : ((0x10000008U == vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr)
                            ? vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc
                            : ((0x1000000cU == vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr)
                                ? vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low
                                : ((0x10000010U == vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr)
                                    ? vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high
                                    : ((0x10000014U 
                                        == vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr)
                                        ? vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter
                                        : ((0x20000000U 
                                            == vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr)
                                            ? vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg
                                            : 0U)))))));
        } else if (((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_rvalid) 
                    & (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_rready))) {
            __Vdly__tb_ibex_axi_top__DOT__m_axi_rvalid = 0U;
        }
        if (vlSelf->can_rx_valid) {
            vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high 
                = vlSelf->can_rx_data_high;
            vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_id 
                = vlSelf->can_rx_id;
            vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc 
                = vlSelf->can_rx_dlc;
            vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low 
                = vlSelf->can_rx_data_low;
            vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_status = 1U;
            if ((((8U < vlSelf->can_rx_dlc) | (0x7dfU 
                                               == vlSelf->can_rx_id)) 
                 | (0xdeadbeefU == vlSelf->can_rx_data_low))) {
                vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = 1U;
            }
        }
        if ((((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_awvalid) 
              & (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_wvalid)) 
             & (~ (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_bvalid)))) {
            __Vdly__tb_ibex_axi_top__DOT__m_axi_bvalid = 1U;
            vlSelf->tb_ibex_axi_top__DOT__m_axi_bresp = 0U;
            if ((0x10000000U == vlSelf->tb_ibex_axi_top__DOT__m_axi_awaddr)) {
                vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_status 
                    = vlSelf->tb_ibex_axi_top__DOT__m_axi_wdata;
            } else if ((0x20000000U == vlSelf->tb_ibex_axi_top__DOT__m_axi_awaddr)) {
                vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg 
                    = vlSelf->tb_ibex_axi_top__DOT__m_axi_wdata;
            }
        } else if (((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_bvalid) 
                    & (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_bready))) {
            __Vdly__tb_ibex_axi_top__DOT__m_axi_bvalid = 0U;
        }
        if ((0U == (IData)(vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state))) {
            vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rvalid = 0U;
            if (vlSelf->tb_ibex_axi_top__DOT__axi_req) {
                if (vlSelf->tb_ibex_axi_top__DOT__cpu_data_req) {
                    __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = 1U;
                    vlSelf->tb_ibex_axi_top__DOT__m_axi_awaddr 
                        = vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr;
                    vlSelf->tb_ibex_axi_top__DOT__m_axi_awvalid = 1U;
                    vlSelf->tb_ibex_axi_top__DOT__m_axi_wdata 
                        = vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr;
                    vlSelf->tb_ibex_axi_top__DOT__m_axi_wstrb 
                        = vlSelf->tb_ibex_axi_top__DOT__cpu_data_be;
                    vlSelf->tb_ibex_axi_top__DOT__m_axi_wvalid = 1U;
                    __Vdly__tb_ibex_axi_top__DOT__m_axi_bready = 1U;
                } else {
                    __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = 2U;
                    vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr 
                        = vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr;
                    vlSelf->tb_ibex_axi_top__DOT__m_axi_arvalid = 1U;
                    __Vdly__tb_ibex_axi_top__DOT__m_axi_rready = 1U;
                }
            }
        } else if ((1U == (IData)(vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state))) {
            if (vlSelf->tb_ibex_axi_top__DOT__m_axi_awready) {
                vlSelf->tb_ibex_axi_top__DOT__m_axi_awvalid = 0U;
            }
            if (vlSelf->tb_ibex_axi_top__DOT__m_axi_wready) {
                vlSelf->tb_ibex_axi_top__DOT__m_axi_wvalid = 0U;
            }
            if (((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_bvalid) 
                 & (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_bready))) {
                __Vdly__tb_ibex_axi_top__DOT__m_axi_bready = 0U;
                vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rvalid = 1U;
                __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = 0U;
            }
        } else if ((2U == (IData)(vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state))) {
            if (vlSelf->tb_ibex_axi_top__DOT__m_axi_arready) {
                vlSelf->tb_ibex_axi_top__DOT__m_axi_arvalid = 0U;
            }
            if (((IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_rvalid) 
                 & (IData)(vlSelf->tb_ibex_axi_top__DOT__m_axi_rready))) {
                __Vdly__tb_ibex_axi_top__DOT__m_axi_rready = 0U;
                vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rdata 
                    = vlSelf->tb_ibex_axi_top__DOT__m_axi_rdata;
                vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rvalid = 1U;
                __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = 0U;
            }
        } else {
            __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = 0U;
        }
    } else {
        __Vdly__tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter = 0U;
        __Vdly__tb_ibex_axi_top__DOT__m_axi_rvalid = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_rresp = 0U;
        __Vdly__tb_ibex_axi_top__DOT__m_axi_rdata = 0U;
        vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high = 0U;
        vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_id = 0U;
        vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc = 0U;
        vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low = 0U;
        __Vdly__tb_ibex_axi_top__DOT__m_axi_bvalid = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_bresp = 0U;
        vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_status = 0U;
        vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = 0U;
        __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_awvalid = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_wvalid = 0U;
        __Vdly__tb_ibex_axi_top__DOT__m_axi_bready = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_arvalid = 0U;
        __Vdly__tb_ibex_axi_top__DOT__m_axi_rready = 0U;
        vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rvalid = 0U;
        vlSelf->tb_ibex_axi_top__DOT__axi_bridge_rdata = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_awaddr = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_wdata = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_wstrb = 0U;
        vlSelf->tb_ibex_axi_top__DOT__m_axi_araddr = 0U;
    }
    vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
        = __Vdly__tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    vlSelf->hw_alert_o = (1U & vlSelf->tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg);
    vlSelf->tb_ibex_axi_top__DOT__m_axi_rdata = __Vdly__tb_ibex_axi_top__DOT__m_axi_rdata;
    vlSelf->tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state 
        = __Vdly__tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state;
    vlSelf->tb_ibex_axi_top__DOT__m_axi_awready = __Vdly__tb_ibex_axi_top__DOT__m_axi_awready;
    vlSelf->tb_ibex_axi_top__DOT__m_axi_wready = __Vdly__tb_ibex_axi_top__DOT__m_axi_wready;
    vlSelf->tb_ibex_axi_top__DOT__m_axi_bvalid = __Vdly__tb_ibex_axi_top__DOT__m_axi_bvalid;
    vlSelf->tb_ibex_axi_top__DOT__m_axi_bready = __Vdly__tb_ibex_axi_top__DOT__m_axi_bready;
    vlSelf->tb_ibex_axi_top__DOT__m_axi_arready = __Vdly__tb_ibex_axi_top__DOT__m_axi_arready;
    vlSelf->tb_ibex_axi_top__DOT__m_axi_rvalid = __Vdly__tb_ibex_axi_top__DOT__m_axi_rvalid;
    vlSelf->tb_ibex_axi_top__DOT__m_axi_rready = __Vdly__tb_ibex_axi_top__DOT__m_axi_rready;
}

VL_INLINE_OPT void Vtb_ibex_axi_top___024root___nba_sequent__TOP__1(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*11:0*/ __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v0;
    __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v0;
    __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_ibex_axi_top__DOT__mem__v0;
    __Vdlyvval__tb_ibex_axi_top__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_ibex_axi_top__DOT__mem__v0;
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v0 = 0;
    SData/*11:0*/ __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v1;
    __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v1 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v1;
    __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_ibex_axi_top__DOT__mem__v1;
    __Vdlyvval__tb_ibex_axi_top__DOT__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_ibex_axi_top__DOT__mem__v1;
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v1 = 0;
    SData/*11:0*/ __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v2;
    __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v2;
    __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_ibex_axi_top__DOT__mem__v2;
    __Vdlyvval__tb_ibex_axi_top__DOT__mem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_ibex_axi_top__DOT__mem__v2;
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v2 = 0;
    SData/*11:0*/ __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v3;
    __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v3 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v3;
    __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_ibex_axi_top__DOT__mem__v3;
    __Vdlyvval__tb_ibex_axi_top__DOT__mem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_ibex_axi_top__DOT__mem__v3;
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v3 = 0;
    // Body
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v0 = 0U;
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v1 = 0U;
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v2 = 0U;
    __Vdlyvset__tb_ibex_axi_top__DOT__mem__v3 = 0U;
    if (((IData)(vlSelf->tb_ibex_axi_top__DOT__sram_req) 
         & (IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_req))) {
        if ((1U & (IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_be))) {
            __Vdlyvval__tb_ibex_axi_top__DOT__mem__v0 
                = (0xffU & vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr);
            __Vdlyvset__tb_ibex_axi_top__DOT__mem__v0 = 1U;
            __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v0 = 0U;
            __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v0 
                = (0xfffU & (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                             >> 2U));
        }
        if ((2U & (IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_be))) {
            __Vdlyvval__tb_ibex_axi_top__DOT__mem__v1 
                = (0xffU & (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                            >> 8U));
            __Vdlyvset__tb_ibex_axi_top__DOT__mem__v1 = 1U;
            __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v1 = 8U;
            __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v1 
                = (0xfffU & (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                             >> 2U));
        }
        if ((4U & (IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_be))) {
            __Vdlyvval__tb_ibex_axi_top__DOT__mem__v2 
                = (0xffU & (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                            >> 0x10U));
            __Vdlyvset__tb_ibex_axi_top__DOT__mem__v2 = 1U;
            __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v2 = 0x10U;
            __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v2 
                = (0xfffU & (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                             >> 2U));
        }
        if ((8U & (IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_be))) {
            __Vdlyvval__tb_ibex_axi_top__DOT__mem__v3 
                = (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                   >> 0x18U);
            __Vdlyvset__tb_ibex_axi_top__DOT__mem__v3 = 1U;
            __Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v3 = 0x18U;
            __Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v3 
                = (0xfffU & (vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr 
                             >> 2U));
        }
    }
    if (__Vdlyvset__tb_ibex_axi_top__DOT__mem__v0) {
        vlSelf->tb_ibex_axi_top__DOT__mem[__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v0))) 
                & vlSelf->tb_ibex_axi_top__DOT__mem
                [__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_ibex_axi_top__DOT__mem__v0) 
                                   << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v0))));
    }
    if (__Vdlyvset__tb_ibex_axi_top__DOT__mem__v1) {
        vlSelf->tb_ibex_axi_top__DOT__mem[__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v1))) 
                & vlSelf->tb_ibex_axi_top__DOT__mem
                [__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_ibex_axi_top__DOT__mem__v1) 
                                   << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v1))));
    }
    if (__Vdlyvset__tb_ibex_axi_top__DOT__mem__v2) {
        vlSelf->tb_ibex_axi_top__DOT__mem[__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v2))) 
                & vlSelf->tb_ibex_axi_top__DOT__mem
                [__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_ibex_axi_top__DOT__mem__v2) 
                                   << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v2))));
    }
    if (__Vdlyvset__tb_ibex_axi_top__DOT__mem__v3) {
        vlSelf->tb_ibex_axi_top__DOT__mem[__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v3))) 
                & vlSelf->tb_ibex_axi_top__DOT__mem
                [__Vdlyvdim0__tb_ibex_axi_top__DOT__mem__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_ibex_axi_top__DOT__mem__v3) 
                                   << (IData)(__Vdlyvlsb__tb_ibex_axi_top__DOT__mem__v3))));
    }
}

VL_INLINE_OPT void Vtb_ibex_axi_top___024root___nba_sequent__TOP__2(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->rst_n)))) {
        vlSelf->tb_ibex_axi_top__DOT__cpu_data_be = 0U;
        vlSelf->tb_ibex_axi_top__DOT__cpu_data_req = 0U;
        vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr = 0U;
    }
    vlSelf->tb_ibex_axi_top__DOT__sram_req = ((IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_req) 
                                              & (0x10000000U 
                                                 > vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr));
    vlSelf->tb_ibex_axi_top__DOT__axi_req = ((IData)(vlSelf->tb_ibex_axi_top__DOT__cpu_data_req) 
                                             & (0x10000000U 
                                                <= vlSelf->tb_ibex_axi_top__DOT__cpu_data_addr));
}

void Vtb_ibex_axi_top___024root___eval_nba(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_ibex_axi_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_ibex_axi_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_ibex_axi_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vtb_ibex_axi_top___024root___eval_triggers__act(Vtb_ibex_axi_top___024root* vlSelf);

bool Vtb_ibex_axi_top___024root___eval_phase__act(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_ibex_axi_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_ibex_axi_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_ibex_axi_top___024root___eval_phase__nba(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_ibex_axi_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ibex_axi_top___024root___dump_triggers__nba(Vtb_ibex_axi_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ibex_axi_top___024root___dump_triggers__act(Vtb_ibex_axi_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_ibex_axi_top___024root___eval(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_ibex_axi_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_ibex_axi_top.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_ibex_axi_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/sujan/riscv-can-ids/sim/tb_ibex_axi_top.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_ibex_axi_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_ibex_axi_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_ibex_axi_top___024root___eval_debug_assertions(Vtb_ibex_axi_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ibex_axi_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->can_rx_valid & 0xfeU))) {
        Verilated::overWidthError("can_rx_valid");}
}
#endif  // VL_DEBUG
