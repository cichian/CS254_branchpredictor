// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbht_wrapper__Syms.h"


VL_ATTR_COLD void Vbht_wrapper___024root__trace_init_sub_0(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbht_wrapper___024root__trace_init_top(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_init_top\n"); );
    // Body
    Vbht_wrapper___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void Vbht_wrapper___024root__trace_init_sub_0(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+15,"clk_i", false,-1);
    tracep->declBit(c+16,"rst_ni", false,-1);
    tracep->declBit(c+17,"flush_i", false,-1);
    tracep->declBit(c+18,"debug_mode_i", false,-1);
    tracep->declQuad(c+19,"vpc_i", false,-1, 63,0);
    tracep->declBit(c+21,"valid_i", false,-1);
    tracep->declQuad(c+22,"pc_i", false,-1, 63,0);
    tracep->declBit(c+24,"taken_i", false,-1);
    tracep->declBit(c+25,"result_valid_o", false,-1);
    tracep->declBit(c+26,"result_taken_o", false,-1);
    tracep->declBit(c+15,"bht_wrapper clk_i", false,-1);
    tracep->declBit(c+16,"bht_wrapper rst_ni", false,-1);
    tracep->declBit(c+17,"bht_wrapper flush_i", false,-1);
    tracep->declBit(c+18,"bht_wrapper debug_mode_i", false,-1);
    tracep->declQuad(c+19,"bht_wrapper vpc_i", false,-1, 63,0);
    tracep->declBit(c+21,"bht_wrapper valid_i", false,-1);
    tracep->declQuad(c+22,"bht_wrapper pc_i", false,-1, 63,0);
    tracep->declBit(c+24,"bht_wrapper taken_i", false,-1);
    tracep->declBit(c+25,"bht_wrapper result_valid_o", false,-1);
    tracep->declBit(c+26,"bht_wrapper result_taken_o", false,-1);
    tracep->declArray(c+1,"bht_wrapper bht_update", false,-1, 65,0);
    tracep->declBus(c+4,"bht_wrapper bht_prediction", false,-1, 3,0);
    tracep->declBus(c+28,"bht_wrapper bht_ins NR_ENTRIES", false,-1, 31,0);
    tracep->declBit(c+15,"bht_wrapper bht_ins clk_i", false,-1);
    tracep->declBit(c+16,"bht_wrapper bht_ins rst_ni", false,-1);
    tracep->declBit(c+17,"bht_wrapper bht_ins flush_i", false,-1);
    tracep->declBit(c+18,"bht_wrapper bht_ins debug_mode_i", false,-1);
    tracep->declQuad(c+19,"bht_wrapper bht_ins vpc_i", false,-1, 63,0);
    tracep->declArray(c+1,"bht_wrapper bht_ins bht_update_i", false,-1, 65,0);
    tracep->declBus(c+4,"bht_wrapper bht_ins bht_prediction_o", false,-1, 3,0);
    tracep->declBus(c+29,"bht_wrapper bht_ins OFFSET", false,-1, 31,0);
    tracep->declBus(c+30,"bht_wrapper bht_ins NR_ROWS", false,-1, 31,0);
    tracep->declBus(c+29,"bht_wrapper bht_ins ROW_ADDR_BITS", false,-1, 31,0);
    tracep->declBus(c+31,"bht_wrapper bht_ins PREDICTION_BITS", false,-1, 31,0);
    tracep->declBus(c+32,"bht_wrapper bht_ins i", false,-1, 31,0);
    tracep->declBus(c+27,"bht_wrapper bht_ins index", false,-1, 8,0);
    tracep->declBus(c+5,"bht_wrapper bht_ins update_pc", false,-1, 8,0);
    tracep->declBus(c+6,"bht_wrapper bht_ins update_row_index", false,-1, 0,0);
    {int i; for (i=0; i<2; i++) {
            tracep->declQuad(c+7+i*2,"bht_wrapper bht_ins instruction_pc", true,(i+0), 63,0);}}
    tracep->declBus(c+11,"bht_wrapper bht_ins unnamedblk3 i", false,-1, 31,0);
    tracep->declBus(c+12,"bht_wrapper bht_ins unnamedblk3 unnamedblk4 j", false,-1, 31,0);
    tracep->declBus(c+13,"bht_wrapper bht_ins unnamedblk1 i", false,-1, 31,0);
    tracep->declBus(c+14,"bht_wrapper bht_ins unnamedblk1 unnamedblk2 j", false,-1, 31,0);
}

VL_ATTR_COLD void Vbht_wrapper___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vbht_wrapper___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vbht_wrapper___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vbht_wrapper___024root__trace_register(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vbht_wrapper___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vbht_wrapper___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vbht_wrapper___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vbht_wrapper___024root__trace_full_sub_0(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbht_wrapper___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_full_top_0\n"); );
    // Init
    Vbht_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbht_wrapper___024root*>(voidSelf);
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vbht_wrapper___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vbht_wrapper___024root__trace_full_sub_0(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbht_wrapper___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullWData(oldp+1,(vlSelf->bht_wrapper__DOT__bht_update),66);
    tracep->fullCData(oldp+4,(vlSelf->bht_wrapper__DOT____Vcellout__bht_ins__bht_prediction_o),4);
    tracep->fullSData(oldp+5,((0x1ffU & (vlSelf->bht_wrapper__DOT__bht_update[0U] 
                                         >> 3U))),9);
    tracep->fullBit(oldp+6,((1U & (vlSelf->bht_wrapper__DOT__bht_update[0U] 
                                   >> 2U))));
    tracep->fullQData(oldp+7,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__instruction_pc[0]),64);
    tracep->fullQData(oldp+9,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__instruction_pc[1]),64);
    tracep->fullIData(oldp+11,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk3__DOT__i),32);
    tracep->fullIData(oldp+12,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk3__DOT__unnamedblk4__DOT__j),32);
    tracep->fullIData(oldp+13,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk1__DOT__i),32);
    tracep->fullIData(oldp+14,(vlSelf->bht_wrapper__DOT__bht_ins__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j),32);
    tracep->fullBit(oldp+15,(vlSelf->clk_i));
    tracep->fullBit(oldp+16,(vlSelf->rst_ni));
    tracep->fullBit(oldp+17,(vlSelf->flush_i));
    tracep->fullBit(oldp+18,(vlSelf->debug_mode_i));
    tracep->fullQData(oldp+19,(vlSelf->vpc_i),64);
    tracep->fullBit(oldp+21,(vlSelf->valid_i));
    tracep->fullQData(oldp+22,(vlSelf->pc_i),64);
    tracep->fullBit(oldp+24,(vlSelf->taken_i));
    tracep->fullBit(oldp+25,(vlSelf->result_valid_o));
    tracep->fullBit(oldp+26,(vlSelf->result_taken_o));
    tracep->fullSData(oldp+27,((0x1ffU & (IData)((vlSelf->vpc_i 
                                                  >> 2U)))),9);
    tracep->fullIData(oldp+28,(0x400U),32);
    tracep->fullIData(oldp+29,(1U),32);
    tracep->fullIData(oldp+30,(0x200U),32);
    tracep->fullIData(oldp+31,(0xbU),32);
    tracep->fullIData(oldp+32,(2U),32);
}
