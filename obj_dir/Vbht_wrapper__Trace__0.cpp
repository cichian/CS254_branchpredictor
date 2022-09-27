// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbht_wrapper__Syms.h"


void Vbht_wrapper___024root__trace_chg_sub_0(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep);

void Vbht_wrapper___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_chg_top_0\n"); );
    // Init
    Vbht_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbht_wrapper___024root*>(voidSelf);
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vbht_wrapper___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vbht_wrapper___024root__trace_chg_sub_0(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgWData(oldp+0,(vlSelf->bht_wrapper__DOT__bht_update),66);
        tracep->chgCData(oldp+3,(vlSelf->bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o),4);
        tracep->chgSData(oldp+4,((0x1ffU & (vlSelf->bht_wrapper__DOT__bht_update[0U] 
                                            >> 3U))),9);
        tracep->chgBit(oldp+5,((1U & (vlSelf->bht_wrapper__DOT__bht_update[0U] 
                                      >> 2U))));
        tracep->chgQData(oldp+6,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__instruction_pc[0]),64);
        tracep->chgQData(oldp+8,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__instruction_pc[1]),64);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        tracep->chgIData(oldp+10,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk3__DOT__i),32);
        tracep->chgIData(oldp+11,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk3__DOT__unnamedblk4__DOT__j),32);
        tracep->chgIData(oldp+12,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk1__DOT__i),32);
        tracep->chgIData(oldp+13,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j),32);
    }
    tracep->chgBit(oldp+14,(vlSelf->clk_i));
    tracep->chgBit(oldp+15,(vlSelf->rst_ni));
    tracep->chgBit(oldp+16,(vlSelf->flush_i));
    tracep->chgBit(oldp+17,(vlSelf->debug_mode_i));
    tracep->chgQData(oldp+18,(vlSelf->vpc_i),64);
    tracep->chgBit(oldp+20,(vlSelf->valid_i));
    tracep->chgQData(oldp+21,(vlSelf->pc_i),64);
    tracep->chgBit(oldp+23,(vlSelf->taken_i));
    tracep->chgBit(oldp+24,(vlSelf->result_valid_o));
    tracep->chgBit(oldp+25,(vlSelf->result_taken_o));
    tracep->chgSData(oldp+26,((0x1ffU & (IData)((vlSelf->vpc_i 
                                                 >> 2U)))),9);
}

void Vbht_wrapper___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_cleanup\n"); );
    // Init
    Vbht_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbht_wrapper___024root*>(voidSelf);
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
