// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sva.h for the primary calling header

#ifndef VERILATED_VTB_SVA___024ROOT_H_
#define VERILATED_VTB_SVA___024ROOT_H_  // guard

#include "verilated.h"


class Vtb_sva__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sva___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(clk,0,0);
            VL_IN8(rst_n,0,0);
            VL_IN(s_axi_awaddr,31,0);
            VL_IN8(s_axi_awvalid,0,0);
            VL_OUT8(s_axi_awready,0,0);
            VL_IN(s_axi_wdata,31,0);
            VL_IN8(s_axi_wstrb,3,0);
            VL_IN8(s_axi_wvalid,0,0);
            VL_OUT8(s_axi_wready,0,0);
            VL_OUT8(s_axi_bresp,1,0);
            VL_OUT8(s_axi_bvalid,0,0);
            VL_IN8(s_axi_bready,0,0);
            VL_IN(s_axi_araddr,31,0);
            VL_IN8(s_axi_arvalid,0,0);
            VL_OUT8(s_axi_arready,0,0);
            VL_OUT(s_axi_rdata,31,0);
            VL_OUT8(s_axi_rresp,1,0);
            VL_OUT8(s_axi_rvalid,0,0);
            VL_IN8(s_axi_rready,0,0);
            VL_IN8(can_rx_valid,0,0);
            VL_IN(can_rx_id,31,0);
            VL_IN(can_rx_dlc,31,0);
            VL_IN(can_rx_data_low,31,0);
            VL_IN(can_rx_data_high,31,0);
            VL_OUT8(hw_alert_o,0,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*3:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot;
    ::CData/*0:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_valid_q;
    ::CData/*0:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rvalid_q;
    ::CData/*0:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_rready_q;
    ::CData/*0:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bvalid_q;
    ::CData/*0:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__s_axi_bready_q;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__s_axi_awvalid__0;
    ::CData/*3:0*/ __Vtrigprevexpr___TOP__s_axi_wstrb__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__s_axi_wvalid__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__s_axi_bready__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__s_axi_arvalid__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__s_axi_rready__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__can_rx_valid__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__1;
    ::SData/*15:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    ::IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_rx_dlc_q;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__s_axi_awaddr__0;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__s_axi_wdata__0;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__s_axi_araddr__0;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__can_rx_id__0;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__can_rx_dlc__0;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__can_rx_data_low__0;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__can_rx_data_high__0;
    ::VlUnpacked<::IData/*31:0*/, 16> tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle;
    ::VlUnpacked<::IData/*31:0*/, 16> tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;
    ::VlUnpacked<::CData/*0:0*/, 2> __VtraceActivity;

    // INTERNAL VARIABLES
    Vtb_sva__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_sva___024root(Vtb_sva__Syms* symsp, const char* namep);
    ~Vtb_sva___024root();
    VL_UNCOPYABLE(Vtb_sva___024root);
    VL_UNMOVABLE(Vtb_sva___024root);

    // INTERNAL METHODS
};


#endif  // guard
