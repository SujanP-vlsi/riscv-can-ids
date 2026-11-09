// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sva.h for the primary calling header

#include "Vtb_sva__pch.h"

VL_ATTR_COLD void Vtb_sva___024root___eval_static(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_static\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__Vtrigprevexpr___TOP__can_rx_id__0 = vlSelfRef.__VprimaryPorts.can_rx_id;
    vlSelfRef.__Vtrigprevexpr___TOP__can_rx_dlc__0 
        = vlSelfRef.__VprimaryPorts.can_rx_dlc;
    vlSelfRef.__Vtrigprevexpr___TOP__can_rx_data_low__0 
        = vlSelfRef.__VprimaryPorts.can_rx_data_low;
    vlSelfRef.__Vtrigprevexpr___TOP__can_rx_data_high__0 
        = vlSelfRef.__VprimaryPorts.can_rx_data_high;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__1 = vlSelfRef.__VprimaryPorts.rst_n;
}

VL_ATTR_COLD void Vtb_sva___024root___eval_initial(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_initial\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_sva___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vtb_sva___024root___eval_stl(Vtb_sva___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_stl\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sva___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_sva___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
                    vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot 
                        = (0x0000000fU & (vlSelfRef.__VprimaryPorts.can_rx_id 
                                          ^ ((vlSelfRef.__VprimaryPorts.can_rx_id 
                                              >> 4U) 
                                             ^ (vlSelfRef.__VprimaryPorts.can_rx_id 
                                                >> 8U))));
                    vlSelfRef.__VprimaryPorts.hw_alert_o 
                        = (1U & vlSelfRef.tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg);
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__stl(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_dump_triggers__stl\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_sva___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__ico(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_dump_triggers__ico\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_sva___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__act(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_dump_triggers__act\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_sva___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__nba(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_dump_triggers__nba\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_sva___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__obs(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_dump_triggers__obs\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__react(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_dump_triggers__react\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_sva___024root___eval_final(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___eval_final\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtb_sva___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_sva___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___trigger_anySet__stl\n"); );
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

bool Vtb_sva___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtb_sva___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( rst_n)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( s_axi_awaddr)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( s_axi_awvalid)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( s_axi_wdata)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( s_axi_wstrb)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( s_axi_wvalid)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @( s_axi_bready)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @( s_axi_araddr)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @( s_axi_arvalid)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @( s_axi_rready)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @( can_rx_valid)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @( can_rx_id)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @( can_rx_dlc)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @( can_rx_data_low)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @( can_rx_data_high)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_sva___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtb_sva___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sva___024root___ctor_var_reset(Vtb_sva___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sva___024root___ctor_var_reset\n"); );
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__VprimaryPorts.clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__VprimaryPorts.rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->__VprimaryPorts.s_axi_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7303631981020876172ull);
    vlSelf->__VprimaryPorts.s_axi_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13986037914296269070ull);
    vlSelf->__VprimaryPorts.s_axi_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14099717354022636468ull);
    vlSelf->__VprimaryPorts.s_axi_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11311253403970331505ull);
    vlSelf->__VprimaryPorts.s_axi_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18112015138521062007ull);
    vlSelf->__VprimaryPorts.s_axi_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12168530306759773544ull);
    vlSelf->__VprimaryPorts.s_axi_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17608475915581965368ull);
    vlSelf->__VprimaryPorts.s_axi_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15162762900795686431ull);
    vlSelf->__VprimaryPorts.s_axi_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9334582144896637853ull);
    vlSelf->__VprimaryPorts.s_axi_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15653039750784194130ull);
    vlSelf->__VprimaryPorts.s_axi_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8722301305194254610ull);
    vlSelf->__VprimaryPorts.s_axi_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17746383479076595557ull);
    vlSelf->__VprimaryPorts.s_axi_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17791137924766170856ull);
    vlSelf->__VprimaryPorts.s_axi_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12866136205313389248ull);
    vlSelf->__VprimaryPorts.s_axi_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14929039895447920609ull);
    vlSelf->__VprimaryPorts.s_axi_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15026938065200214434ull);
    vlSelf->__VprimaryPorts.s_axi_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1794163653381394343ull);
    vlSelf->__VprimaryPorts.can_rx_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18116719927906456614ull);
    vlSelf->__VprimaryPorts.can_rx_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3785592947014892950ull);
    vlSelf->__VprimaryPorts.can_rx_dlc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1346844656836901896ull);
    vlSelf->__VprimaryPorts.can_rx_data_low = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7281416035132231159ull);
    vlSelf->__VprimaryPorts.can_rx_data_high = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2224737402076827223ull);
    vlSelf->__VprimaryPorts.hw_alert_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11778246946438946969ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6379785754279989087ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5048427976063478192ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3532905105576293205ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17314279037876149741ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13541242514593492805ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9047085775465373862ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7264988462292206268ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14042731338843305725ull);
    VL_UNPACKED_FILL(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle.data(), sizeof(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle[0]), 16);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10394336857146119928ull);
    VL_UNPACKED_FILL(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag.data(), sizeof(vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag[0]), 16);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12824447031799341787ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 150977580358867935ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7140391162454669757ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8903260594895027596ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10212667446279140475ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5083792924630509565ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14774485974561811744ull);
    vlSelf->tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4310380111836130627ull);
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_awaddr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_awvalid__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_wdata__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_wstrb__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_wvalid__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_bready__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_araddr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_arvalid__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__s_axi_rready__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__can_rx_valid__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__can_rx_id__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__can_rx_dlc__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__can_rx_data_low__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__can_rx_data_high__0 = 0;
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__1 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
    vlSelf->__VtraceActivity[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VtraceActivity.data(), sizeof(vlSelf->__VtraceActivity[0]), 2);
}
