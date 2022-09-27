	// this is branch predictor testbench
#include "Vbht_wrapper.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <typeinfo>
#include "utils.h"
#include "bt9_reader.h"

using namespace std;




int main(int argc, char **argv, char **env) {
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
  int sim_time = 20000; // cycle number * 10
  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vbht_wrapper* top = new Vbht_wrapper;
  // init trace dump
  
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("../bht_wrapper.vcd");
  
  //initialize reading trace process
  std::string trace_path;
  trace_path = argv[1];
  bt9::BT9Reader bt9_reader(trace_path);
  UINT64 PC;
  bool branchTaken;
  UINT64 branchTarget;
  
  int update_delay = 40;
  
  int i = 0;
  uint32_t temp = 1;
  float match = 0;
  float total = 0;
  int matchzero = 0;
  int matchone = 0;
  // initialize simulation inputs
  top->clk_i = 0;
  top->rst_ni = 1;
  top->flush_i = 0;
  top->debug_mode_i = 0;
  
  top->vpc_i = 0; // 64
  top->valid_i = 1;
  top->pc_i = 0;
  top->taken_i = 0;
  
  auto it = bt9_reader.begin();
    // time increment 
    while (it != bt9_reader.end()){
    contextp->timeInc(1);
    if (contextp->time() % 10 == 0) top->clk_i = 0;
    else if (contextp->time() % 10 == 5) top->clk_i = 1;
    
    top->rst_ni = (contextp->time() < 5) || (contextp->time() > 20);
    top->vpc_i = it -> getEdge()->brVirtualTarget();
    top->pc_i = it->getEdge()->brVirtualTarget();
    
    if ((contextp->time() % 10 == 0) && top->rst_ni == 1 && contextp ->time() > 10) {
            temp = top -> result_taken_o;
            top->taken_i = it -> getEdge() -> isTakenPath();
    	    if (temp == it -> getEdge() -> isTakenPath()) {
    	    	match ++;
    	    	if (temp == 0){
    	    		matchzero ++;
    	    	}
    	    	else {
    	    		matchone ++;
    	    	}
    	    }
    	    total ++;
    	   	
    	    it++;
    }
    top->eval ();
    tfp->dump (contextp->time());
  }
  cout << "matchzero " << matchzero << endl;
  cout << "matchone " << matchone << endl;
  cout << "accuracy " << match/total << endl;
  tfp->close();
  exit(0);
}

