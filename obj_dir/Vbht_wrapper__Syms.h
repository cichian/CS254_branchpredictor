// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBHT_WRAPPER__SYMS_H_
#define VERILATED_VBHT_WRAPPER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vbht_wrapper.h"

// INCLUDE MODULE CLASSES
#include "Vbht_wrapper___024root.h"

// SYMS CLASS (contains all model state)
class Vbht_wrapper__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vbht_wrapper* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vbht_wrapper___024root         TOP;

    // CONSTRUCTORS
    Vbht_wrapper__Syms(VerilatedContext* contextp, const char* namep, Vbht_wrapper* modelp);
    ~Vbht_wrapper__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
