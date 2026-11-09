// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_multi_id.h for the primary calling header

#include "Vtb_multi_id__pch.h"
#include "Vtb_multi_id__Syms.h"
#include "Vtb_multi_id___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_multi_id___024root___dump_triggers__stl(Vtb_multi_id___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_multi_id___024root___eval_triggers__stl(Vtb_multi_id___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_multi_id__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_multi_id___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_multi_id___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
