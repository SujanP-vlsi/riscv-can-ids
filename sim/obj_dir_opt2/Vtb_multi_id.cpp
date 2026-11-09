// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_multi_id__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtb_multi_id::Vtb_multi_id(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_multi_id__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , s_axi_awvalid{vlSymsp->TOP.s_axi_awvalid}
    , s_axi_awready{vlSymsp->TOP.s_axi_awready}
    , s_axi_wstrb{vlSymsp->TOP.s_axi_wstrb}
    , s_axi_wvalid{vlSymsp->TOP.s_axi_wvalid}
    , s_axi_wready{vlSymsp->TOP.s_axi_wready}
    , s_axi_bresp{vlSymsp->TOP.s_axi_bresp}
    , s_axi_bvalid{vlSymsp->TOP.s_axi_bvalid}
    , s_axi_bready{vlSymsp->TOP.s_axi_bready}
    , s_axi_arvalid{vlSymsp->TOP.s_axi_arvalid}
    , s_axi_arready{vlSymsp->TOP.s_axi_arready}
    , s_axi_rresp{vlSymsp->TOP.s_axi_rresp}
    , s_axi_rvalid{vlSymsp->TOP.s_axi_rvalid}
    , s_axi_rready{vlSymsp->TOP.s_axi_rready}
    , can_rx_valid{vlSymsp->TOP.can_rx_valid}
    , hw_alert_o{vlSymsp->TOP.hw_alert_o}
    , s_axi_awaddr{vlSymsp->TOP.s_axi_awaddr}
    , s_axi_wdata{vlSymsp->TOP.s_axi_wdata}
    , s_axi_araddr{vlSymsp->TOP.s_axi_araddr}
    , s_axi_rdata{vlSymsp->TOP.s_axi_rdata}
    , can_rx_id{vlSymsp->TOP.can_rx_id}
    , can_rx_dlc{vlSymsp->TOP.can_rx_dlc}
    , can_rx_data_low{vlSymsp->TOP.can_rx_data_low}
    , can_rx_data_high{vlSymsp->TOP.can_rx_data_high}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_multi_id::Vtb_multi_id(const char* _vcname__)
    : Vtb_multi_id(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_multi_id::~Vtb_multi_id() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_multi_id___024root___eval_debug_assertions(Vtb_multi_id___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_multi_id___024root___eval_static(Vtb_multi_id___024root* vlSelf);
void Vtb_multi_id___024root___eval_initial(Vtb_multi_id___024root* vlSelf);
void Vtb_multi_id___024root___eval_settle(Vtb_multi_id___024root* vlSelf);
void Vtb_multi_id___024root___eval(Vtb_multi_id___024root* vlSelf);

void Vtb_multi_id::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_multi_id::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_multi_id___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_multi_id___024root___eval_static(&(vlSymsp->TOP));
        Vtb_multi_id___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_multi_id___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_multi_id___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_multi_id::eventsPending() { return false; }

uint64_t Vtb_multi_id::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_multi_id::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_multi_id___024root___eval_final(Vtb_multi_id___024root* vlSelf);

VL_ATTR_COLD void Vtb_multi_id::final() {
    Vtb_multi_id___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_multi_id::hierName() const { return vlSymsp->name(); }
const char* Vtb_multi_id::modelName() const { return "Vtb_multi_id"; }
unsigned Vtb_multi_id::threads() const { return 1; }
void Vtb_multi_id::prepareClone() const { contextp()->prepareClone(); }
void Vtb_multi_id::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtb_multi_id::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtb_multi_id___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtb_multi_id___024root__trace_init_top(Vtb_multi_id___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_multi_id___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_multi_id___024root*>(voidSelf);
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_multi_id___024root__trace_decl_types(tracep);
    Vtb_multi_id___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_multi_id___024root__trace_register(Vtb_multi_id___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb_multi_id::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_multi_id::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtb_multi_id___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
