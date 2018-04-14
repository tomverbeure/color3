
module top(
	input 		osc25_pad_in,

	// MISC
	output		led_r_pad_out,
	output		led_g_pad_out,
	output		led_b_pad_out,

	input 		ir_rx /* synthesis keep */,
	input 		button /* synthesis keep */,

	// Flash
	output		 flash_dclk,
	output		 flash_nreset,
	output		 flash_nce,
	output		 flash_noe,
	output		 flash_navd,
	output		 flash_nwe,
//	input		 flash_wait,
	output [23:0]	 flash_padd,
	inout [15:0]	 flash_data,

	// SDRAM
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

	// SII9233
	output		sii9233_reset_,
	input		sii9233_int		/* synthesis keep */,
	inout		sii9233_cscl,
	inout		sii9233_csda,

	input 		sii9233_de		/* synthesis keep */,
	input 		sii9233_hsync		/* synthesis keep */,
	input 		sii9233_vsync		/* synthesis keep */,
	input 		sii9233_odck		/* synthesis keep */,

	input [35:0]	sii9233_q		/* synthesis keep */,


	// SII9136
	output 		sii9136_reset_,
	input 		sii9136_int		/* synthesis keep */,
	inout 		sii9136_cscl,
	inout 		sii9136_csda,

	output 		sii9136_de,
	output 		sii9136_hsync,
	output 		sii9136_vsync,
	output 		sii9136_idck,

	output [35:0]	sii9136_d
	);


	reg [25:0] cntr;
	always @(posedge osc25_pad_in) begin
		cntr <= cntr + 1;
	end

	assign led_g_pad_out = cntr[24];
	assign led_b_pad_out = cntr[23];

	assign	sii9136_reset_ = 1'b0;
	assign 	sii9136_cscl = 1'bz;
	assign 	sii9136_csda = 1'bz;

	assign 	sii9136_de = 1'b0;
	assign 	sii9136_hsync = 1'b0;
	assign 	sii9136_vsync = 1'b0;
	assign 	sii9136_idck = 1'b0;

	assign sii9136_d = 36'd0;

	assign	sii9233_reset_ = 1'b0;
	assign 	sii9233_cscl = 1'bz;
	assign 	sii9233_csda = 1'bz;

	assign flash_dclk = 1'b0;
	assign flash_nreset = 1'b0;
	assign flash_nce = 1'b1;
	assign flash_noe = 1'b1;
	assign flash_navd = 1'b1;
	assign flash_nwe = 1'b1;
	assign flash_padd = 24'd0;
	assign flash_data = {16{1'bz}}; 

	reg global_reset_n;
	always @(posedge osc25_pad_in) begin
		global_reset_n 	<= 1'b1;
	end

	assign pll_areset = 1'b0;

	wire [7:0] pio_in, pio_out;

	cpu_sys u_cpu_sys(
		.pll_areset_export	(pll_areset),
		.pll_ref_clk_clk	(osc25_pad_in),

		.pll_sdram_clk_clk	(sdram_clk),
		.vid_clk_clk		(vid_clk), 
		.pll_cpu_clk_clk	(cpu_clk),

		.pll_phasedone_export	(pll_phase_done),
		.pll_locked_export	(pll_locked),

//		.cpu_clk_clk		(cpu_clk),
//		.cpu_reset_reset_n	(!pll_locked),

		.cpu_clk_clk		(osc25_pad_in),
		.cpu_reset_reset_n	(global_reset_n),

		.pio_in_port		(pio_in),
		.pio_out_port		(pio_out)
	);

	assign pio_in = { 7'd0, ir_rx, button };
	assign led_r_pad_out = pio_out[0];

endmodule
