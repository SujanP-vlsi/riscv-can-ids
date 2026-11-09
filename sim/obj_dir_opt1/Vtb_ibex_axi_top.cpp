// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_ibex_axi_top__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtb_ibex_axi_top::Vtb_ibex_axi_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_ibex_axi_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , can_rx_valid{vlSymsp->TOP.can_rx_valid}
    , hw_alert_o{vlSymsp->TOP.hw_alert_o}
    , can_rx_id{vlSymsp->TOP.can_rx_id}
    , can_rx_dlc{vlSymsp->TOP.can_rx_dlc}
    , can_rx_data_low{vlSymsp->TOP.can_rx_data_low}
    , can_rx_data_high{vlSymsp->TOP.can_rx_data_high}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_ibex_axi_top::Vtb_ibex_axi_top(const char* _vcname__)
    : Vtb_ibex_axi_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_ibex_axi_top::~Vtb_ibex_axi_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_ibex_axi_top___024root___eval_debug_assertions(Vtb_ibex_axi_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_ibex_axi_top___024root___eval_static(Vtb_ibex_axi_top___024root* vlSelf);
void Vtb_ibex_axi_top___024root___eval_initial(Vtb_ibex_axi_top___024root* vlSelf);
void Vtb_ibex_axi_top___024root___eval_settle(Vtb_ibex_axi_top___024root* vlSelf);
void Vtb_ibex_axi_top___024root___eval(Vtb_ibex_axi_top___024root* vlSelf);

void Vtb_ibex_axi_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_ibex_axi_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_ibex_axi_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_ibex_axi_top___024root___eval_static(&(vlSymsp->TOP));
        Vtb_ibex_axi_top___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_ibex_axi_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_ibex_axi_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_ibex_axi_top::eventsPending() { return false; }

uint64_t Vtb_ibex_axi_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_ibex_axi_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_ibex_axi_top___024root___eval_final(Vtb_ibex_axi_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_ibex_axi_top::final() {
    Vtb_ibex_axi_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_ibex_axi_top::hierName() const { return vlSymsp->name(); }
const char* Vtb_ibex_axi_top::modelName() const { return "Vtb_ibex_axi_top"; }
unsigned Vtb_ibex_axi_top::threads() const { return 1; }
void Vtb_ibex_axi_top::prepareClone() const { contextp()->prepareClone(); }
void Vtb_ibex_axi_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtb_ibex_axi_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtb_ibex_axi_top___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtb_ibex_axi_top___024root__trace_init_top(Vtb_ibex_axi_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_ibex_axi_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_ibex_axi_top___024root*>(voidSelf);
    Vtb_ibex_axi_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_ibex_axi_top___024root__trace_decl_types(tracep);
    Vtb_ibex_axi_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_ibex_axi_top___024root__trace_register(Vtb_ibex_axi_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb_ibex_axi_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_ibex_axi_top::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtb_ibex_axi_top___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
