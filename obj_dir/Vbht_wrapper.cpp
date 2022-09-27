// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbht_wrapper.h"
#include "Vbht_wrapper__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vbht_wrapper::Vbht_wrapper(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vbht_wrapper__Syms(_vcontextp__, _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , flush_i{vlSymsp->TOP.flush_i}
    , debug_mode_i{vlSymsp->TOP.debug_mode_i}
    , valid_i{vlSymsp->TOP.valid_i}
    , taken_i{vlSymsp->TOP.taken_i}
    , result_valid_o{vlSymsp->TOP.result_valid_o}
    , result_taken_o{vlSymsp->TOP.result_taken_o}
    , vpc_i{vlSymsp->TOP.vpc_i}
    , pc_i{vlSymsp->TOP.pc_i}
    , rootp{&(vlSymsp->TOP)}
{
}

Vbht_wrapper::Vbht_wrapper(const char* _vcname__)
    : Vbht_wrapper(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vbht_wrapper::~Vbht_wrapper() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vbht_wrapper___024root___eval_initial(Vbht_wrapper___024root* vlSelf);
void Vbht_wrapper___024root___eval_settle(Vbht_wrapper___024root* vlSelf);
void Vbht_wrapper___024root___eval(Vbht_wrapper___024root* vlSelf);
QData Vbht_wrapper___024root___change_request(Vbht_wrapper___024root* vlSelf);
#ifdef VL_DEBUG
void Vbht_wrapper___024root___eval_debug_assertions(Vbht_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
void Vbht_wrapper___024root___final(Vbht_wrapper___024root* vlSelf);

static void _eval_initial_loop(Vbht_wrapper__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vbht_wrapper___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vbht_wrapper___024root___eval_settle(&(vlSymsp->TOP));
        Vbht_wrapper___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vbht_wrapper___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("bht_wrapper.sv", 2, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vbht_wrapper___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbht_wrapper::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbht_wrapper::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbht_wrapper___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vbht_wrapper___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vbht_wrapper___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("bht_wrapper.sv", 2, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vbht_wrapper___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vbht_wrapper::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vbht_wrapper::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vbht_wrapper::final() {
    Vbht_wrapper___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void Vbht_wrapper___024root__trace_init_top(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbht_wrapper___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbht_wrapper___024root*>(voidSelf);
    Vbht_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vbht_wrapper___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vbht_wrapper___024root__trace_register(Vbht_wrapper___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbht_wrapper::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vbht_wrapper___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
