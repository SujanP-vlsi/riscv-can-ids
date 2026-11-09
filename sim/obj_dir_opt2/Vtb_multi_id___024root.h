// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_multi_id.h for the primary calling header

#ifndef VERILATED_VTB_MULTI_ID___024ROOT_H_
#define VERILATED_VTB_MULTI_ID___024ROOT_H_  // guard

#include "verilated.h"


class Vtb_multi_id__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_multi_id___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(s_axi_awvalid,0,0);
    VL_OUT8(s_axi_awready,0,0);
    VL_IN8(s_axi_wstrb,3,0);
    VL_IN8(s_axi_wvalid,0,0);
    VL_OUT8(s_axi_wready,0,0);
    VL_OUT8(s_axi_bresp,1,0);
    VL_OUT8(s_axi_bvalid,0,0);
    VL_IN8(s_axi_bready,0,0);
    VL_IN8(s_axi_arvalid,0,0);
    VL_OUT8(s_axi_arready,0,0);
    VL_OUT8(s_axi_rresp,1,0);
    VL_OUT8(s_axi_rvalid,0,0);
    VL_IN8(s_axi_rready,0,0);
    VL_IN8(can_rx_valid,0,0);
    VL_OUT8(hw_alert_o,0,0);
    CData/*3:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__id_slot;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_valid_flags;
    VL_IN(s_axi_awaddr,31,0);
    VL_IN(s_axi_wdata,31,0);
    VL_IN(s_axi_araddr,31,0);
    VL_OUT(s_axi_rdata,31,0);
    VL_IN(can_rx_id,31,0);
    VL_IN(can_rx_dlc,31,0);
    VL_IN(can_rx_data_low,31,0);
    VL_IN(can_rx_data_high,31,0);
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_status;
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_id;
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc;
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low;
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high;
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg;
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    IData/*31:0*/ tb_axi_top__DOT__u_ids_axi_lite__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 16> tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_last_cycle;
    VlUnpacked<IData/*31:0*/, 16> tb_axi_top__DOT__u_ids_axi_lite__DOT__lut_tag;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_multi_id__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_multi_id___024root(Vtb_multi_id__Syms* symsp, const char* v__name);
    ~Vtb_multi_id___024root();
    VL_UNCOPYABLE(Vtb_multi_id___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
