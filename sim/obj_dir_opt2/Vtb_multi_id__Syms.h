// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_MULTI_ID__SYMS_H_
#define VERILATED_VTB_MULTI_ID__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_multi_id.h"

// INCLUDE MODULE CLASSES
#include "Vtb_multi_id___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_multi_id__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_multi_id* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_multi_id___024root         TOP;

    // CONSTRUCTORS
    Vtb_multi_id__Syms(VerilatedContext* contextp, const char* namep, Vtb_multi_id* modelp);
    ~Vtb_multi_id__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
