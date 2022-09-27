// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbht_wrapper.h for the primary calling header

#include "verilated.h"

#include "Vbht_wrapper__Syms.h"
#include "Vbht_wrapper___024root.h"

void Vbht_wrapper___024root___ctor_var_reset(Vbht_wrapper___024root* vlSelf);

Vbht_wrapper___024root::Vbht_wrapper___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vbht_wrapper___024root___ctor_var_reset(this);
}

void Vbht_wrapper___024root::__Vconfigure(Vbht_wrapper__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vbht_wrapper___024root::~Vbht_wrapper___024root() {
}
