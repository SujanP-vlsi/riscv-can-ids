// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_SVA__SYMS_H_
#define VERILATED_VTB_SVA__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_sva.h"

// INCLUDE MODULE CLASSES
#include "Vtb_sva___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_sva__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_sva* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_sva___024root              TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_axi_top__u_ids_axi_lite;

    // CONSTRUCTORS
    Vtb_sva__Syms(VerilatedContext* contextp, const char* namep, Vtb_sva* modelp);
    ~Vtb_sva__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
