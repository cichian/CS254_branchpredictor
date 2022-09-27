// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbht_wrapper.h for the primary calling header

#include "verilated.h"

#include "Vbht_wrapper___024root.h"

void Vbht_wrapper___024root___combo__TOP__1(Vbht_wrapper___024root* vlSelf);
void Vbht_wrapper___024root___sequent__TOP__3(Vbht_wrapper___024root* vlSelf);
void Vbht_wrapper___024root___sequent__TOP__4(Vbht_wrapper___024root* vlSelf);
void Vbht_wrapper___024root___combo__TOP__5(Vbht_wrapper___024root* vlSelf);

void Vbht_wrapper___024root___eval(Vbht_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root___eval\n"); );
    // Body
    Vbht_wrapper___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if ((((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlSelf->rst_ni)) & (IData)(vlSelf->__Vclklast__TOP__rst_ni)))) {
        Vbht_wrapper___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vbht_wrapper___024root___sequent__TOP__4(vlSelf);
    }
    Vbht_wrapper___024root___combo__TOP__5(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_ni = vlSelf->rst_ni;
}

QData Vbht_wrapper___024root___change_request_1(Vbht_wrapper___024root* vlSelf);

VL_INLINE_OPT QData Vbht_wrapper___024root___change_request(Vbht_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root___change_request\n"); );
    // Body
    return (Vbht_wrapper___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vbht_wrapper___024root___change_request_1(Vbht_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o ^ vlSelf->__Vchglast__TOP__bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o));
    VL_DEBUG_IF( if(__req && ((vlSelf->bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o ^ vlSelf->__Vchglast__TOP__bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o))) VL_DBG_MSGF("        CHANGE: bht.sv:28: bht_wrapper.__Vcellout__bht_ins__bht_prediction_o\n"); );
    // Final
    vlSelf->__Vchglast__TOP__bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o 
        = vlSelf->bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o;
    return __req;
}

#ifdef VL_DEBUG
void Vbht_wrapper___024root___eval_debug_assertions(Vbht_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->flush_i & 0xfeU))) {
        Verilated::overWidthError("flush_i");}
    if (VL_UNLIKELY((vlSelf->debug_mode_i & 0xfeU))) {
        Verilated::overWidthError("debug_mode_i");}
    if (VL_UNLIKELY((vlSelf->valid_i & 0xfeU))) {
        Verilated::overWidthError("valid_i");}
    if (VL_UNLIKELY((vlSelf->taken_i & 0xfeU))) {
        Verilated::overWidthError("taken_i");}
}
#endif  // VL_DEBUG
