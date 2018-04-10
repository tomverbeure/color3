
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

	input 		sii9136_reset_,
	input 		sii9136_int,
	input 		sii9136_cscl,
	input 		sii9136_csda,

	input 		sii9136_de,
	input 		sii9136_hsync,
	input 		sii9136_vsync,
	input 		sii9136_idck,

	input 		sii9136_d0,
	input 		sii9136_d1,
	input 		sii9136_d2,
	input 		sii9136_d3,
	input 		sii9136_d4,
	input 		sii9136_d5,
	input 		sii9136_d6,
	input 		sii9136_d7,
	input 		sii9136_d8,
	input 		sii9136_d9,
	input 		sii9136_d10,
	input 		sii9136_d11,
	input 		sii9136_d12,
	input 		sii9136_d13,
	input 		sii9136_d14,
	input 		sii9136_d15,
	input 		sii9136_d16,
	input 		sii9136_d17,
	input 		sii9136_d18,
	input 		sii9136_d19,
	input 		sii9136_d20,
	input 		sii9136_d21,
	input 		sii9136_d22,
	input 		sii9136_d23,
	input 		sii9136_d24,
	input 		sii9136_d25,
	input 		sii9136_d26,
	input 		sii9136_d27,
	input 		sii9136_d28,
	input 		sii9136_d29,
	input 		sii9136_d30,
	input 		sii9136_d31,
	input 		sii9136_d32,
	input 		sii9136_d33,
	input 		sii9136_d34,
	input 		sii9136_d35,

	input [200:0]	misc_input /* synthesis keep */
	);


	reg [25:0] cntr;
	always @(posedge osc25_pad_in) begin
		cntr <= cntr + 1;
	end

	assign led_r_pad_out = cntr[25];
	assign led_g_pad_out = cntr[24];
	assign led_b_pad_out = cntr[23];

endmodule
