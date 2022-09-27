//this is bht wrapper 
module bht_wrapper(
    // C++ interface
    input  logic                        clk_i,
    input  logic                        rst_ni,
    input  logic                        flush_i,
    input  logic                        debug_mode_i,
    input  logic [64-1:0]               vpc_i,
    // bht_update
    input  logic     			 valid_i,
    input  logic [64-1:0]               pc_i,
    input  logic                        taken_i,
    
    //bht_prediction
    output logic                   result_valid_o,
    output logic                   result_taken_o
);
    // RTL interface
    ariane_pkg::bht_update_t     bht_update;

    ariane_pkg::bht_prediction_t [2-1:0] bht_prediction;
    
    assign bht_update = {valid_i, pc_i, taken_i};
    
    always_comb begin
    	//for (int i = 0; i < 2; i = i + 1) begin
    		result_valid_o = bht_prediction[0].valid;
    		result_taken_o = bht_prediction[0].taken;
    	//end
    end
        
    bht #(
    	.NR_ENTRIES(1024)
    )bht_ins
    (
    	.clk_i(clk_i),
    	.rst_ni(rst_ni),
    	.flush_i(flush_i),
    	.debug_mode_i(debug_mode_i),
    	.vpc_i(vpc_i),
    	.bht_update_i(bht_update),
    	.bht_prediction_o(bht_prediction)
    ); 
    
endmodule
