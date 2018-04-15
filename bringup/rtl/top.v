
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

	output wire 	sii9136_idck,
	output reg 	sii9136_de,
	output reg 	sii9136_hsync,
	output reg 	sii9136_vsync,

	output reg [35:0] sii9136_d
	);

	localparam h_front  = 16;
	localparam h_sync   = 96;
	localparam h_back   = 48;
	localparam h_active = 640;
	localparam h_blank  = h_front + h_sync + h_back;
	localparam h_total  = h_front + h_sync + h_back + h_active;

	localparam v_front  = 10;
	localparam v_sync   = 2;
	localparam v_back   = 33;
	localparam v_active = 480;
	localparam v_blank  = v_front + v_sync + v_back;
	localparam v_total  = v_front + v_sync + v_back + v_active;

	reg [25:0] cntr;
	always @(posedge osc25_pad_in) begin
		cntr <= cntr + 1;
	end

	assign led_g_pad_out = cntr[25] ^ cpu_cntr[25] ^ vid_cntr[25] ^ sdram_cntr[25];
	assign led_b_pad_out = cntr[23];

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

	assign pio_in = { sii9136_cscl, sii9136_csda, sii9136_int, 3'd0, ir_rx, button };

	assign led_r_pad_out = pio_out[0];

	assign pll_areset     = pio_out[4];
	assign sii9136_reset_ = pio_out[5];
	assign sii9136_csda   = pio_out[6] ? 1'bz : 1'b0;
	assign sii9136_cscl   = pio_out[7] ? 1'bz : 1'b0;

	reg [25:0] sdram_cntr /* synthesis keep */;
	always @(posedge sdram_clk) begin
		sdram_cntr <= sdram_cntr + 1;
	end

	reg [25:0] vid_cntr /* synthesis keep */;
	always @(posedge vid_clk) begin
		vid_cntr <= vid_cntr + 1;
	end

	reg [25:0] cpu_cntr /* synthesis keep */;
	always @(posedge cpu_clk) begin
		cpu_cntr <= cpu_cntr + 1;
	end

	reg [11:0] col_cntr;
	reg [11:0] line_cntr;
	reg [11:0] offset_cntr;

	always @(posedge vid_clk) begin
		if (col_cntr < h_total-1) begin
			col_cntr <= col_cntr + 1;
		end
		else if (line_cntr < v_total-1) begin
			line_cntr <= line_cntr + 1;
			col_cntr <= 0;
		end
		else begin
			line_cntr <= 0;
			col_cntr <= 0;

			if (offset_cntr < v_active-1) begin
				offset_cntr <= offset_cntr + 1;
			end
			else begin
				offset_cntr <= 0;
			end
		end
	end

	assign 	sii9136_idck = vid_clk;

	always @(posedge vid_clk) begin
		sii9136_de    <= (line_cntr >= v_blank) && (col_cntr >= h_blank);
		sii9136_hsync <= col_cntr >= h_front && col_cntr < h_front + h_sync;
		sii9136_vsync <= line_cntr >= v_front && line_cntr < v_front + v_sync;

		if (line_cntr < offset_cntr + v_blank) begin
			sii9136_d[35:24] <= {12{1'b1}};
			sii9136_d[23:12] <= line_cntr << 3;
			sii9136_d[11: 0] <= col_cntr << 3;
		end
		else begin
			sii9136_d[35:24] <= line_cntr << 3;
			sii9136_d[23:12] <= {12{1'b1}};
			sii9136_d[11: 0] <= col_cntr << 3;
		end
	end

endmodule
