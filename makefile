# verilator makefile

#declare variable
C := verilator
VFLAGS := -Wno-fatal -Wall --cc --trace
CFLAGS := --exe --build

type ?= bht_wrapper
include_ ?= ariane_pkg.sv
verilog ?= $(type).sv
wrapper := $(type)_tb.cpp
waveform := $(type).vcd
LOG_FILE := bht.log
BF   += -LDFLAGS -lboost_iostreams

sim: $(verilog) $(wrapper)
ifneq ("", "$(wildcard $(waveform))")
	rm $(waveform)
else 
	@echo "waveform does not exist"
endif
ifneq ("", "$(wildcard obj_dir)")
	rm -r obj_dir/
else
	@echo "obj_dir does not exist"
endif
	$(C) $(BF) $(VFLAGS) $(include_) --top $(type) $(verilog) $(CFLAGS) $(wrapper)

wave: $(waveform)
	gtkwave $(waveform) &

clean: obj_dir
ifneq ("","$(wildcard $(waveform))")
	rm $(waveform) 
else 
	@echo "waveform does not exist, please execute vcd.sh"
endif
	rm -r obj_dir/


	
