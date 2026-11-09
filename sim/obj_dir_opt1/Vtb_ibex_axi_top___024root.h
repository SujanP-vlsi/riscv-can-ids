// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_ibex_axi_top.h for the primary calling header

#ifndef VERILATED_VTB_IBEX_AXI_TOP___024ROOT_H_
#define VERILATED_VTB_IBEX_AXI_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtb_ibex_axi_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_ibex_axi_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(can_rx_valid,0,0);
    VL_OUT8(hw_alert_o,0,0);
    CData/*0:0*/ tb_ibex_axi_top__DOT__sram_req;
    CData/*0:0*/ tb_ibex_axi_top__DOT__axi_req;
    CData/*3:0*/ tb_ibex_axi_top__DOT__cpu_data_be;
    CData/*0:0*/ tb_ibex_axi_top__DOT__cpu_data_req;
    CData/*0:0*/ tb_ibex_axi_top__DOT__axi_bridge_rvalid;
    CData/*3:0*/ tb_ibex_axi_top__DOT__m_axi_wstrb;
    CData/*1:0*/ tb_ibex_axi_top__DOT__m_axi_bresp;
    CData/*1:0*/ tb_ibex_axi_top__DOT__m_axi_rresp;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_awvalid;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_awready;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_wvalid;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_wready;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_bvalid;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_bready;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_arvalid;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_arready;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_rvalid;
    CData/*0:0*/ tb_ibex_axi_top__DOT__m_axi_rready;
    CData/*1:0*/ tb_ibex_axi_top__DOT__u_axi_bridge__DOT__state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(can_rx_id,31,0);
    VL_IN(can_rx_dlc,31,0);
    VL_IN(can_rx_data_low,31,0);
    VL_IN(can_rx_data_high,31,0);
    IData/*31:0*/ tb_ibex_axi_top__DOT__cpu_data_addr;
    IData/*31:0*/ tb_ibex_axi_top__DOT__axi_bridge_rdata;
    IData/*31:0*/ tb_ibex_axi_top__DOT__m_axi_awaddr;
    IData/*31:0*/ tb_ibex_axi_top__DOT__m_axi_wdata;
    IData/*31:0*/ tb_ibex_axi_top__DOT__m_axi_araddr;
    IData/*31:0*/ tb_ibex_axi_top__DOT__m_axi_rdata;
    IData/*31:0*/ tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_status;
    IData/*31:0*/ tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_id;
    IData/*31:0*/ tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_dlc;
    IData/*31:0*/ tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_low;
    IData/*31:0*/ tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__can_data_high;
    IData/*31:0*/ tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__ids_alert_reg;
    IData/*31:0*/ tb_ibex_axi_top__DOT__u_ids_axi_lite__DOT__cycle_counter;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 4096> tb_ibex_axi_top__DOT__mem;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_ibex_axi_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_ibex_axi_top___024root(Vtb_ibex_axi_top__Syms* symsp, const char* v__name);
    ~Vtb_ibex_axi_top___024root();
    VL_UNCOPYABLE(Vtb_ibex_axi_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
