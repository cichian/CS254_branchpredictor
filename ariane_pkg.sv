package ariane_pkg;
    typedef struct packed {
        logic                   valid;
        logic [64-1:0] pc;          // update at PC
        logic                   taken;
    } bht_update_t;
    	
    typedef struct packed {
        logic       valid;
        logic       taken;
    } bht_prediction_t;
endpackage
