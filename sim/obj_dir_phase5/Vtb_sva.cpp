// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_sva__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtb_sva::Vtb_sva(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vtb_sva{_vcontextp__, _vcname__, true} {}

Vtb_sva::Vtb_sva(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_sva__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , clk{vlSymsp->vlInst.TOP.__VprimaryPorts.clk}
    , rst_n{vlSymsp->vlInst.TOP.__VprimaryPorts.rst_n}
    , s_axi_awaddr{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_awaddr}
    , s_axi_awvalid{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_awvalid}
    , s_axi_awready{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_awready}
    , s_axi_wdata{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_wdata}
    , s_axi_wstrb{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_wstrb}
    , s_axi_wvalid{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_wvalid}
    , s_axi_wready{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_wready}
    , s_axi_bresp{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_bresp}
    , s_axi_bvalid{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_bvalid}
    , s_axi_bready{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_bready}
    , s_axi_araddr{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_araddr}
    , s_axi_arvalid{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_arvalid}
    , s_axi_arready{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_arready}
    , s_axi_rdata{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_rdata}
    , s_axi_rresp{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_rresp}
    , s_axi_rvalid{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_rvalid}
    , s_axi_rready{vlSymsp->vlInst.TOP.__VprimaryPorts.s_axi_rready}
    , can_rx_valid{vlSymsp->vlInst.TOP.__VprimaryPorts.can_rx_valid}
    , can_rx_id{vlSymsp->vlInst.TOP.__VprimaryPorts.can_rx_id}
    , can_rx_dlc{vlSymsp->vlInst.TOP.__VprimaryPorts.can_rx_dlc}
    , can_rx_data_low{vlSymsp->vlInst.TOP.__VprimaryPorts.can_rx_data_low}
    , can_rx_data_high{vlSymsp->vlInst.TOP.__VprimaryPorts.can_rx_data_high}
    , hw_alert_o{vlSymsp->vlInst.TOP.__VprimaryPorts.hw_alert_o}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtb_sva::Vtb_sva(const char* _vcname__)
    : Vtb_sva(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_sva::~Vtb_sva() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_sva___024root___eval_debug_assertions(Vtb_sva___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtb_sva___024root___eval_static(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_initial(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD bool Vtb_sva___024root___eval_stl(Vtb_sva___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vtb_sva___024root___eval_sample(Vtb_sva___024root* vlSelf);
bool Vtb_sva___024root___eval_ico(Vtb_sva___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vtb_sva___024root___eval_act(Vtb_sva___024root* vlSelf);
bool Vtb_sva___024root___eval_inact(Vtb_sva___024root* vlSelf);
bool Vtb_sva___024root___eval_nba(Vtb_sva___024root* vlSelf);
bool Vtb_sva___024root___eval_obs(Vtb_sva___024root* vlSelf);
bool Vtb_sva___024root___eval_react(Vtb_sva___024root* vlSelf);
void Vtb_sva___024root___eval_postponed(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_final(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__stl(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__ico(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__act(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__nba(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__obs(Vtb_sva___024root* vlSelf);
VL_ATTR_COLD void Vtb_sva___024root___eval_dump_triggers__react(Vtb_sva___024root* vlSelf);

void Vtb_sva::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_sva::eval_step\n"); );
    m_evalLoop.eval();
}

void Vtb_sva::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_sva___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vtb_sva::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtb_sva::evalStatic() {
    Vtb_sva___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vtb_sva::evalInitial() {
    Vtb_sva___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vtb_sva::evalStl(bool firstIteration) {
    return Vtb_sva___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vtb_sva::evalSample() {
    Vtb_sva___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vtb_sva::evalIco(bool firstIteration) {
    return Vtb_sva___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vtb_sva::evalAct() {
    return Vtb_sva___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vtb_sva::evalInact() {
    return Vtb_sva___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vtb_sva::evalNba() {
    return Vtb_sva___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vtb_sva::evalObs() {
    return Vtb_sva___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vtb_sva::evalReact() {
    return Vtb_sva___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vtb_sva::evalPostponed() {
    Vtb_sva___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vtb_sva::evalFinal() {
    Vtb_sva___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtb_sva::dumpTriggersStl() {
    Vtb_sva___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtb_sva::dumpTriggersIco() {
    Vtb_sva___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtb_sva::dumpTriggersAct() {
    Vtb_sva___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtb_sva::dumpTriggersNba() {
    Vtb_sva___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtb_sva::dumpTriggersObs() {
    Vtb_sva___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtb_sva::dumpTriggersReact() {
    Vtb_sva___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vtb_sva::eventsPending() { return false; }

uint64_t Vtb_sva::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_sva::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtb_sva::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_sva::hierName() const { return vlSymsp->name(); }
const char* Vtb_sva::modelName() const { return "Vtb_sva"; }
unsigned Vtb_sva::threads() const { return 1; }
void Vtb_sva::prepareClone() const { contextp()->prepareClone(); }
void Vtb_sva::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtb_sva::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vtb_sva___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtb_sva___024root__trace_init_top(Vtb_sva___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_sva___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_sva___024root*>(voidSelf);
    Vtb_sva__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_sva___024root__trace_decl_types(tracep);
    Vtb_sva___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_sva___024root__trace_register(Vtb_sva___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb_sva::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_sva::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 73);
    Vtb_sva___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
