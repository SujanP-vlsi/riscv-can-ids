// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sva.h for the primary calling header

#include "Vtb_sva__pch.h"

void Vtb_sva___024root___eval_sample(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_sample\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool Vtb_sva___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

bool Vtb_sva___024root___eval_ico(Vtb_sva___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_ico\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            (((((((vlSelfRef.__VprimaryPorts.can_rx_data_high 
                                                                   != vlSelfRef.__Vtrigprevexpr___TOP__can_rx_data_high__0) 
                                                                  << 3U) 
                                                                 | ((vlSelfRef.__VprimaryPorts.can_rx_data_low 
                                                                     != vlSelfRef.__Vtrigprevexpr___TOP__can_rx_data_low__0) 
                                                                    << 2U)) 
                                                                | (((vlSelfRef.__VprimaryPorts.can_rx_dlc 
                                                                     != vlSelfRef.__Vtrigprevexpr___TOP__can_rx_dlc__0) 
                                                                    << 1U) 
                                                                   | (vlSelfRef.__VprimaryPorts.can_rx_id 
                                                                      != vlSelfRef.__Vtrigprevexpr___TOP__can_rx_id__0))) 
                                                               << 0x0000000cU) 
                                                              | ((((((::IData)(vlSelfRef.__VprimaryPorts.can_rx_valid) 
                                                                     != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__can_rx_valid__0)) 
                                                                    << 3U) 
                                                                   | (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_rready) 
                                                                       != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__s_axi_rready__0)) 
                                                                      << 2U)) 
                                                                  | ((((::IData)(vlSelfRef.__VprimaryPorts.s_axi_arvalid) 
                                                                       != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__s_axi_arvalid__0)) 
                                                                      << 1U) 
                                                                     | (vlSelfRef.__VprimaryPorts.s_axi_araddr 
                                                                        != vlSelfRef.__Vtrigprevexpr___TOP__s_axi_araddr__0))) 
                                                                 << 8U)) 
                                                             | (((((((::IData)(vlSelfRef.__VprimaryPorts.s_axi_bready) 
                                                                     != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__s_axi_bready__0)) 
                                                                    << 3U) 
                                                                   | (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_wvalid) 
                                                                       != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__s_axi_wvalid__0)) 
                                                                      << 2U)) 
                                                                  | ((((::IData)(vlSelfRef.__VprimaryPorts.s_axi_wstrb) 
                                                                       != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__s_axi_wstrb__0)) 
                                                                      << 1U) 
                                                                     | (vlSelfRef.__VprimaryPorts.s_axi_wdata 
                                                                        != vlSelfRef.__Vtrigprevexpr___TOP__s_axi_wdata__0))) 
                                                                 << 4U) 
                                                                | (((((::IData)(vlSelfRef.__VprimaryPorts.s_axi_awvalid) 
                                                                      != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__s_axi_awvalid__0)) 
                                                                     << 3U) 
                                                                    | ((vlSelfRef.__VprimaryPorts.s_axi_awaddr 
                                                                        != vlSelfRef.__Vtrigprevexpr___TOP__s_axi_awaddr__0) 
                                                                       << 2U)) 
                                                                   | ((((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
                                                                        != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                                       << 1U) 
                                                                      | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                         != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.__VprimaryPorts.rst_n;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_awaddr__0 
            = vlSelfRef.__VprimaryPorts.s_axi_awaddr;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_awvalid__0 
            = vlSelfRef.__VprimaryPorts.s_axi_awvalid;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_wdata__0 
            = vlSelfRef.__VprimaryPorts.s_axi_wdata;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_wstrb__0 
            = vlSelfRef.__VprimaryPorts.s_axi_wstrb;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_wvalid__0 
            = vlSelfRef.__VprimaryPorts.s_axi_wvalid;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_bready__0 
            = vlSelfRef.__VprimaryPorts.s_axi_bready;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_araddr__0 
            = vlSelfRef.__VprimaryPorts.s_axi_araddr;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_arvalid__0 
            = vlSelfRef.__VprimaryPorts.s_axi_arvalid;
        vlSelfRef.__Vtrigprevexpr___TOP__s_axi_rready__0 
            = vlSelfRef.__VprimaryPorts.s_axi_rready;
        vlSelfRef.__Vtrigprevexpr___TOP__can_rx_valid__0 
            = vlSelfRef.__VprimaryPorts.can_rx_valid;
        vlSelfRef.__Vtrigprevexpr___TOP__can_rx_id__0 
            = vlSelfRef.__VprimaryPorts.can_rx_id;
        vlSelfRef.__Vtrigprevexpr___TOP__can_rx_dlc__0 
            = vlSelfRef.__VprimaryPorts.can_rx_dlc;
        vlSelfRef.__Vtrigprevexpr___TOP__can_rx_data_low__0 
            = vlSelfRef.__VprimaryPorts.can_rx_data_low;
        vlSelfRef.__Vtrigprevexpr___TOP__can_rx_data_high__0 
            = vlSelfRef.__VprimaryPorts.can_rx_data_high;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sva___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtb_sva___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((0x0000000000001000ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot 
                        = (0x0000000fU & (vlSelfRef.__VprimaryPorts.can_rx_id 
                                          ^ ((vlSelfRef.__VprimaryPorts.can_rx_id 
                                              >> 4U) 
                                             ^ (vlSelfRef.__VprimaryPorts.can_rx_id 
                                                >> 8U))));
                }
            }
        }
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void Vtb_sva___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool Vtb_sva___024root___eval_act(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_act\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((((~ (::IData)(vlSelfRef.__VprimaryPorts.rst_n)) 
                                                               & (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__1)) 
                                                              << 1U) 
                                                             | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst_n__1 = vlSelfRef.__VprimaryPorts.rst_n;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sva___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_sva___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vtb_sva___024root___eval_inact(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_inact\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb_sva___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void Vtb_sva___024root___nba_sequent__TOP__0(Vtb_sva___024root* vlSelf);
void Vtb_sva___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vtb_sva___024root___eval_nba(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_nba\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_sva___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vtb_sva___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__VtraceActivity[1U] = 1U;
            }
        }
        Vtb_sva___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtb_sva___024root___eval_obs(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_obs\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb_sva___024root___eval_react(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_react\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtb_sva___024root___eval_postponed(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_postponed\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtb_sva___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

bool Vtb_sva___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___trigger_anySet__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const ::VlUnpacked<::CData/*0:0*/, 128> Vtb_sva__ConstPool__CONSARRAY_1;
extern const ::VlUnpacked<::CData/*0:0*/, 128> Vtb_sva__ConstPool__CONSARRAY_2;
extern const ::VlUnpacked<::CData/*3:0*/, 128> Vtb_sva__ConstPool__CONSARRAY_0;
extern const ::VlUnpacked<::CData/*0:0*/, 128> Vtb_sva__ConstPool__CONSARRAY_3;
extern const ::VlUnpacked<::CData/*1:0*/, 128> Vtb_sva__ConstPool__CONSARRAY_4;

void Vtb_sva___024root___nba_sequent__TOP__0(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___nba_sequent__TOP__0\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*6:0*/ __Vtableidx_0;
    ::IData/*31:0*/ __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter_0;
    ::CData/*0:0*/ __Vdly__s_axi_rvalid_9;
    ::CData/*0:0*/ __Vdly__s_axi_bvalid_14;
    ::IData/*31:0*/ __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_22;
    ::CData/*3:0*/ __Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_23;
    ::CData/*0:0*/ __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_24;
    ::CData/*0:0*/ __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_25;
    ::IData/*31:0*/ __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_26;
    ::CData/*3:0*/ __Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_27;
    ::CData/*0:0*/ __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_28;
    ::CData/*0:0*/ __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_29;
    // Body
    __Vtableidx_0 = 0;
    __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter_0 = 0;
    __Vdly__s_axi_rvalid_9 = 0;
    __Vdly__s_axi_bvalid_14 = 0;
    __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_22 = 0;
    __Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_23 = 0;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_24 = 0;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_25 = 0;
    __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_26 = 0;
    __Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_27 = 0;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_28 = 0;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_29 = 0;
    __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter_0 
        = vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    __Vdly__s_axi_rvalid_9 = vlSelfRef.__VprimaryPorts.s_axi_rvalid;
    __Vdly__s_axi_bvalid_14 = vlSelfRef.__VprimaryPorts.s_axi_bvalid;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_28 = 0U;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_29 = 0U;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_24 = 0U;
    __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_25 = 0U;
    if (vlSymsp->_vm_contextp__->assertCtlGet<2, 1>(VerilatedAssertCtlQuery::ASSERT_CTL_ON)) {
        if (vlSymsp->_vm_contextp__->assertCtlGet<2, 1>(VerilatedAssertCtlQuery::ASSERT_CTL_FAIL_ON)) {
            if ((((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
                  & (::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q)) 
                 & (~ (::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q)))) {
                if (VL_UNLIKELY(((1U & (~ (::IData)(vlSelfRef.__VprimaryPorts.s_axi_bvalid)))))) {
                    VL_WRITEF_NX("[%0t] %%Error: ids_axi_lite.sv:219: Assertion failed in %m: [SVA VIOLATION] s_axi_bvalid dropped before s_axi_bready was asserted!\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"u_ids_axi_lite", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000));
                    VL_STOP_MT("/home/sujan/riscv-can-ids/rtl/ids_axi_lite.sv", 219, "");
                }
            }
            if ((((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
                  & (::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q)) 
                 & (~ (::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q)))) {
                if (VL_UNLIKELY(((1U & (~ (::IData)(vlSelfRef.__VprimaryPorts.s_axi_rvalid)))))) {
                    VL_WRITEF_NX("[%0t] %%Error: ids_axi_lite.sv:212: Assertion failed in %m: [SVA VIOLATION] s_axi_rvalid dropped before s_axi_rready was asserted!\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"u_ids_axi_lite", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000));
                    VL_STOP_MT("/home/sujan/riscv-can-ids/rtl/ids_axi_lite.sv", 212, "");
                }
            }
            if ((((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
                  & (::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q)) 
                 & (8U < vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q))) {
                if (VL_UNLIKELY(((1U & (~ (::IData)(vlSelfRef.__VprimaryPorts.hw_alert_o)))))) {
                    VL_WRITEF_NX("[%0t] %%Error: ids_axi_lite.sv:205: Assertion failed in %m: [SVA VIOLATION] Protocol anomaly failed to assert hw_alert_o on next cycle!\n",3, 'M',vlSymsp->__Vm_topNames[1].c_str(),"u_ids_axi_lite", 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000));
                    VL_STOP_MT("/home/sujan/riscv-can-ids/rtl/ids_axi_lite.sv", 205, "");
                }
            }
        }
    }
    if (vlSelfRef.__VprimaryPorts.rst_n) {
        __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter_0 
            = ((::IData)(1U) + vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter);
        if (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_arvalid) 
             & (~ (::IData)(vlSelfRef.__VprimaryPorts.s_axi_rvalid)))) {
            __Vdly__s_axi_rvalid_9 = 1U;
            vlSelfRef.__VprimaryPorts.s_axi_rresp = 0U;
            vlSelfRef.__VprimaryPorts.s_axi_rdata = 
                ((0x10000000U == vlSelfRef.__VprimaryPorts.s_axi_araddr)
                  ? vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status
                  : ((0x10000004U == vlSelfRef.__VprimaryPorts.s_axi_araddr)
                      ? vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id
                      : ((0x10000008U == vlSelfRef.__VprimaryPorts.s_axi_araddr)
                          ? vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc
                          : ((0x1000000cU == vlSelfRef.__VprimaryPorts.s_axi_araddr)
                              ? vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low
                              : ((0x10000010U == vlSelfRef.__VprimaryPorts.s_axi_araddr)
                                  ? vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high
                                  : ((0x10000014U == vlSelfRef.__VprimaryPorts.s_axi_araddr)
                                      ? vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter
                                      : ((0x20000000U 
                                          == vlSelfRef.__VprimaryPorts.s_axi_araddr)
                                          ? vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg
                                          : 0U)))))));
        } else if (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_rvalid) 
                    & (::IData)(vlSelfRef.__VprimaryPorts.s_axi_rready))) {
            __Vdly__s_axi_rvalid_9 = 0U;
        }
        if (vlSelfRef.__VprimaryPorts.can_rx_valid) {
            __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_26 
                = vlSelfRef.__VprimaryPorts.can_rx_id;
            __Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_27 
                = vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot;
            __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_28 = 1U;
            __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_22 
                = vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
            __Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_23 
                = vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot;
            __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_24 = 1U;
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status = 1U;
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high 
                = vlSelfRef.__VprimaryPorts.can_rx_data_high;
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low 
                = vlSelfRef.__VprimaryPorts.can_rx_data_low;
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id 
                = vlSelfRef.__VprimaryPorts.can_rx_id;
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc 
                = vlSelfRef.__VprimaryPorts.can_rx_dlc;
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg 
                = ((((8U < vlSelfRef.__VprimaryPorts.can_rx_dlc) 
                     | (0x000007dfU == vlSelfRef.__VprimaryPorts.can_rx_id)) 
                    | (0xdeadbeefU == vlSelfRef.__VprimaryPorts.can_rx_data_low))
                    ? 1U : (((((::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags) 
                               >> (::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot)) 
                              & (vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag
                                 [vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot] 
                                 == vlSelfRef.__VprimaryPorts.can_rx_id)) 
                             & (0x0000000fU > (vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
                                               - vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle
                                               [vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot])))
                             ? 1U : 0U));
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags 
                = ((::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags) 
                   | (0x0000ffffU & ((::IData)(1U) 
                                     << (::IData)(vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot))));
        } else if (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_awvalid) 
                    & ((::IData)(vlSelfRef.__VprimaryPorts.s_axi_wvalid) 
                       & ((~ (::IData)(vlSelfRef.__VprimaryPorts.s_axi_bvalid)) 
                          & (0x20000000U == vlSelfRef.__VprimaryPorts.s_axi_awaddr))))) {
            vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg 
                = vlSelfRef.__VprimaryPorts.s_axi_wdata;
        }
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q 
            = vlSelfRef.__VprimaryPorts.can_rx_dlc;
    } else {
        __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter_0 = 0U;
        __Vdly__s_axi_rvalid_9 = 0U;
        __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_29 = 1U;
        __Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_25 = 1U;
        vlSelfRef.__VprimaryPorts.s_axi_rresp = 0U;
        vlSelfRef.__VprimaryPorts.s_axi_rdata = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags = 0U;
    }
    vlSelfRef.__VprimaryPorts.s_axi_arready = ((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
                                               && ((::IData)(vlSelfRef.__VprimaryPorts.s_axi_arvalid) 
                                                   & (~ (::IData)(vlSelfRef.__VprimaryPorts.s_axi_arready))));
    __Vtableidx_0 = ((((((::IData)(vlSelfRef.__VprimaryPorts.s_axi_bready) 
                         << 3U) | ((::IData)(vlSelfRef.__VprimaryPorts.s_axi_bvalid) 
                                   << 2U)) | (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_wready) 
                                               << 1U) 
                                              | (::IData)(vlSelfRef.__VprimaryPorts.s_axi_wvalid))) 
                      << 3U) | (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_awready) 
                                 << 2U) | (((::IData)(vlSelfRef.__VprimaryPorts.s_axi_awvalid) 
                                            << 1U) 
                                           | (::IData)(vlSelfRef.__VprimaryPorts.rst_n))));
    vlSelfRef.__VprimaryPorts.s_axi_awready = Vtb_sva__ConstPool__CONSARRAY_1
        [__Vtableidx_0];
    vlSelfRef.__VprimaryPorts.s_axi_wready = Vtb_sva__ConstPool__CONSARRAY_2
        [__Vtableidx_0];
    if ((0U != (4U & Vtb_sva__ConstPool__CONSARRAY_0
                [__Vtableidx_0]))) {
        __Vdly__s_axi_bvalid_14 = Vtb_sva__ConstPool__CONSARRAY_3
            [__Vtableidx_0];
    }
    if ((0U != (8U & Vtb_sva__ConstPool__CONSARRAY_0
                [__Vtableidx_0]))) {
        vlSelfRef.__VprimaryPorts.s_axi_bresp = Vtb_sva__ConstPool__CONSARRAY_4
            [__Vtableidx_0];
    }
    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q 
        = ((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
           && (::IData)(vlSelfRef.__VprimaryPorts.s_axi_bready));
    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q 
        = ((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
           && (::IData)(vlSelfRef.__VprimaryPorts.s_axi_bvalid));
    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q 
        = ((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
           && (::IData)(vlSelfRef.__VprimaryPorts.s_axi_rready));
    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q 
        = ((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
           && (::IData)(vlSelfRef.__VprimaryPorts.s_axi_rvalid));
    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q 
        = ((::IData)(vlSelfRef.__VprimaryPorts.rst_n) 
           && (::IData)(vlSelfRef.__VprimaryPorts.can_rx_valid));
    vlSelfRef.__VprimaryPorts.s_axi_rvalid = __Vdly__s_axi_rvalid_9;
    if (__Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_28) {
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[__Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_27] 
            = __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_26;
    }
    if (__Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag_29) {
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[1U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[2U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[3U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[4U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[5U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[6U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[7U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[8U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[9U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[10U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[11U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[12U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[13U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[14U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[15U] = 0U;
    }
    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter 
        = __Vdly__tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter_0;
    if (__Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_24) {
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[__Vdly_Dim0__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_23] 
            = __Vdly_Val__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_22;
    }
    if (__Vdly_Set__tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle_25) {
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[1U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[2U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[3U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[4U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[5U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[6U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[7U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[8U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[9U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[10U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[11U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[12U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[13U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[14U] = 0U;
        vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[15U] = 0U;
    }
    vlSelfRef.__VprimaryPorts.s_axi_bvalid = __Vdly__s_axi_bvalid_14;
    vlSelfRef.__VprimaryPorts.hw_alert_o = (1U & vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg);
}

void Vtb_sva___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vtb_sva___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vtb_sva___024root___eval_debug_assertions(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_debug_assertions\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.clk 
                      & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.rst_n 
                      & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.s_axi_awvalid 
                      & 0xfeU)))) {
        Verilated::overWidthError("s_axi_awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.s_axi_wstrb 
                      & 0xf0U)))) {
        Verilated::overWidthError("s_axi_wstrb");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.s_axi_wvalid 
                      & 0xfeU)))) {
        Verilated::overWidthError("s_axi_wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.s_axi_bready 
                      & 0xfeU)))) {
        Verilated::overWidthError("s_axi_bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.s_axi_arvalid 
                      & 0xfeU)))) {
        Verilated::overWidthError("s_axi_arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.s_axi_rready 
                      & 0xfeU)))) {
        Verilated::overWidthError("s_axi_rready");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.can_rx_valid 
                      & 0xfeU)))) {
        Verilated::overWidthError("can_rx_valid");
    }
}
#endif  // VL_DEBUG
