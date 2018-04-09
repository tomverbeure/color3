
module top(
	input 		osc25_pad_in,

	output		led_r_pad_out,
	output		led_g_pad_out,
	output		led_b_pad_out,

	input 		ir_rx,
	input 		button,

	input 		dram_clk_pad_out,
	input 		dram_cs_n_pad_out,
	input 		dram_we_n_pad_out,
	input 		dram_cas_n_pad_out,
	input 		dram_ras_n_pad_out,
	input [11:0]	dram_a_pad_out,
	input 		dram_cke_pad_out,
	input [1:0]	dram_ba_pad_out,
	input [15:0]	dram_dq_pad_inout,
	input [1:0]	dram_dqm_pad_inout,

/*
	input 		sii9233_clk,
	input 		sii9233_vsync,
	input 		sii9233_hsync,
	input 		sii9233_de,
	input [35:0]	sii9233_q,
	input 		sii9233_evnodd,

	input 		sii9233_int,
	input 		sii9233_reset_,
	input 		sii9233_cscl,
	input 		sii9233_csda,
	input 		sii9233_ci2ca,
	input 		sii9233_scdt
*/

	input [47:0]	misc_input /* synthesis keep */
	);


	reg [25:0] cntr;
	always @(posedge osc25_pad_in) begin
		cntr <= cntr + 1;
	end

	assign led_r_pad_out = cntr[25];
	assign led_g_pad_out = cntr[24];
	assign led_b_pad_out = cntr[23];

endmodule
