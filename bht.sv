// Copyright 2018 - 2019 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 2.0 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-2.0. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//
// Author: Florian Zaruba, ETH Zurich
// Date: 08.02.2018
// Migrated: Luis Vitorio Cargnini, IEEE
// Date: 09.06.2018


// branch history table - 2 bit saturation counter
module bht #(
    parameter int unsigned NR_ENTRIES = 1024
)(
    input  logic                        clk_i,
    input  logic                        rst_ni,
    input  logic                        flush_i,
    input  logic                        debug_mode_i,
    input  logic [64-1:0]      vpc_i,
    input  ariane_pkg::bht_update_t     bht_update_i,
    // we potentially need INSTR_PER_FETCH predictions/cycle
    output ariane_pkg::bht_prediction_t [2-1:0] bht_prediction_o
);
    // the last bit is always zero, we don't need it for indexing
    localparam OFFSET = 1;
    // re-shape the branch history table
    localparam NR_ROWS = NR_ENTRIES / 2;
    // number of bits needed to index the row
    localparam ROW_ADDR_BITS = $clog2(2);
    // number of bits we should use for prediction
    localparam PREDICTION_BITS = $clog2(NR_ROWS) + OFFSET + ROW_ADDR_BITS;
    // we are not interested in all bits of the address
    //unread i_unread (.d_i(|vpc_i));
    int i;




    struct packed {
        logic                   valid;
        logic [64-1:0] pc;
    } bht_d[NR_ROWS-1:0][2-1:0], bht_q[NR_ROWS-1:0][2-1:0];

    logic [$clog2(NR_ROWS)-1:0]  index, update_pc;
    logic [ROW_ADDR_BITS-1:0]    update_row_index;

    assign index     = vpc_i[PREDICTION_BITS - 1:ROW_ADDR_BITS + OFFSET];
    assign update_pc = bht_update_i.pc[PREDICTION_BITS - 1:ROW_ADDR_BITS + OFFSET];
    assign update_row_index = bht_update_i.pc[ROW_ADDR_BITS + OFFSET - 1:OFFSET];

    logic [64-1:0]instruction_pc [2-1:0];
    always_comb begin
    	for (i = 0; i < 2; i++) begin : assign_instruction_pcs
        	instruction_pc[i] = vpc_i + (i<<OFFSET);
    	end
    end


    // prediction assignment
    for (genvar i = 0; i < 2; i++) begin : gen_bht_output
        assign bht_prediction_o[i].valid = bht_q[index][i].valid;
        // don't take if valid and pc exists in table
        assign bht_prediction_o[i].taken = ~( (bht_prediction_o[i].valid) && (instruction_pc[i] == bht_q[index][i].pc) );
    end

    always_comb begin : update_bht
        bht_d = bht_q;

        // if taken, if in table, set valid bit to 0
        // if not taken, if not in table, add to table
        if (bht_update_i.valid && !debug_mode_i) begin
            if (!bht_update_i.taken) begin
                // if conflict, just overwrite with most recent
                bht_d[update_pc][update_row_index].pc = bht_update_i.pc;
                bht_d[update_pc][update_row_index].valid = 1'b1;
            end else if (bht_update_i.taken) begin
                // make invalid
                if (bht_d[update_pc][update_row_index].pc == bht_update_i.pc)
                    bht_d[update_pc][update_row_index].valid = 1'b0;
            end

        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            for (int unsigned i = 0; i < NR_ROWS; i++) begin
                for (int j = 0; j < 2; j++) begin
                    bht_q[i][j] = '0;
                end
            end
        end else begin
            // evict all entries
            if (flush_i) begin
                for (int i = 0; i < NR_ROWS; i++) begin
                    for (int j = 0; j < 2; j++) begin
                        bht_q[i][j] = '0;
                    end
                end
            end else begin
                bht_q <= bht_d;
            end
        end
    end
endmodule



// Copyright 2018 - 2019 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 2.0 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-2.0. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//
// Author: Florian Zaruba, ETH Zurich
// Date: 08.02.2018
// Migrated: Luis Vitorio Cargnini, IEEE
// Date: 09.06.2018

// branch history table - 2 bit saturation counter
/*module bht #(
    parameter int unsigned NR_ENTRIES = 1024
)(
    input  logic                        clk_i,
    input  logic                        rst_ni,
    input  logic                        flush_i,
    input  logic                        debug_mode_i,
    input  logic [64-1:0]      vpc_i,
    input  ariane_pkg::bht_update_t     bht_update_i,
    // we potentially need INSTR_PER_FETCH predictions/cycle
    output ariane_pkg::bht_prediction_t [2-1:0] bht_prediction_o
);
    // the last bit is always zero, we don't need it for indexing
    localparam OFFSET = 1;
    // re-shape the branch history table
    localparam NR_ROWS = NR_ENTRIES / 2;
    // number of bits needed to index the row
    localparam ROW_ADDR_BITS = $clog2(2);
    // number of bits we should use for prediction
    localparam PREDICTION_BITS = $clog2(NR_ROWS) + OFFSET + ROW_ADDR_BITS;
    // we are not interested in all bits of the address
    //unread i_unread (.d_i(|vpc_i));

    struct packed {
        logic       valid;
        logic [1:0] saturation_counter;
    } bht_d[NR_ROWS-1:0][2-1:0], bht_q[NR_ROWS-1:0][2-1:0];

    logic [$clog2(NR_ROWS)-1:0]  index, update_pc;
    logic [ROW_ADDR_BITS-1:0]    update_row_index;
    logic [1:0]                  saturation_counter;

    assign index     = vpc_i[PREDICTION_BITS - 1:ROW_ADDR_BITS + OFFSET];
    assign update_pc = bht_update_i.pc[PREDICTION_BITS - 1:ROW_ADDR_BITS + OFFSET];
    assign update_row_index = bht_update_i.pc[ROW_ADDR_BITS + OFFSET - 1:OFFSET];

    // prediction assignment
    for (genvar i = 0; i < 2; i++) begin : gen_bht_output
        assign bht_prediction_o[i].valid = bht_q[update_pc][i].valid;
        assign bht_prediction_o[i].taken = bht_q[update_pc][i].saturation_counter[1] == 1'b1;
    end

    always_comb begin : update_bht
        bht_d = bht_q;
        saturation_counter = bht_q[update_pc][update_row_index].saturation_counter;

        if (bht_update_i.valid && !debug_mode_i) begin
            bht_d[update_pc][update_row_index].valid = 1'b1;

            if (saturation_counter == 2'b11) begin
                // we can safely decrease it
                if (!bht_update_i.taken)
                    bht_d[update_pc][update_row_index].saturation_counter = saturation_counter - 1;
            // then check if it saturated in the negative regime e.g.: branch not taken
            end else if (saturation_counter == 2'b00) begin
                // we can safely increase it
                if (bht_update_i.taken)
                    bht_d[update_pc][update_row_index].saturation_counter = saturation_counter + 1;
            end else begin // otherwise we are not in any boundaries and can decrease or increase it
                if (bht_update_i.taken)
                    bht_d[update_pc][update_row_index].saturation_counter = saturation_counter + 1;
                else
                    bht_d[update_pc][update_row_index].saturation_counter = saturation_counter - 1;
            end
        end
    end

    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            for (int unsigned i = 0; i < NR_ROWS; i++) begin
                for (int j = 0; j < 2; j++) begin
                    bht_q[i][j] = '0;
                end
            end
        end else begin
            // evict all entries
            if (flush_i) begin
                for (int i = 0; i < NR_ROWS; i++) begin
                    for (int j = 0; j < 2; j++) begin
                        bht_q[i][j].valid =  1'b0;
                        bht_q[i][j].saturation_counter = 2'b10;
                    end
                end
            end else begin
                bht_q <= bht_d;
            end
        end
    end
endmodule*/


