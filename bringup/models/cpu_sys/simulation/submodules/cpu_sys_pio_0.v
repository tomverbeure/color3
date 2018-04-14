//Legal Notice: (C)2018 Altera Corporation. All rights reserved.  Your
//use of Altera Corporation's design tools, logic functions and other
//software and tools, and its AMPP partner logic functions, and any
//output files any of the foregoing (including device programming or
//simulation files), and any associated documentation or information are
//expressly subject to the terms and conditions of the Altera Program
//License Subscription Agreement or other applicable license agreement,
//including, without limitation, that your use is for the sole purpose
//of programming logic devices manufactured by Altera and sold by Altera
//or its authorized distributors.  Please refer to the applicable
//agreement for further details.

// synthesis translate_off
`timescale 1ns / 1ps
// synthesis translate_on

// turn off superfluous verilog processor warnings 
// altera message_level Level1 
// altera message_off 10034 10035 10036 10037 10230 10240 10030 

module cpu_sys_pio_0 (
                       // inputs:
                        address,
                        chipselect,
                        clk,
                        in_port,
                        reset_n,
                        write_n,
                        writedata,

                       // outputs:
                        out_port,
                        readdata
                     )
;

  output  [  7: 0] out_port;
  output  [ 31: 0] readdata;
  input   [  2: 0] address;
  input            chipselect;
  input            clk;
  input   [  7: 0] in_port;
  input            reset_n;
  input            write_n;
  input   [ 31: 0] writedata;

  wire             clk_en;
  reg     [  7: 0] d1_data_in;
  reg     [  7: 0] d2_data_in;
  wire    [  7: 0] data_in;
  reg     [  7: 0] data_out;
  reg     [  7: 0] edge_capture;
  wire             edge_capture_wr_strobe;
  wire    [  7: 0] edge_detect;
  wire    [  7: 0] out_port;
  wire    [  7: 0] read_mux_out;
  reg     [ 31: 0] readdata;
  wire             wr_strobe;
  assign clk_en = 1;
  //s1, which is an e_avalon_slave
  assign read_mux_out = ({8 {(address == 0)}} & data_in) |
    ({8 {(address == 3)}} & edge_capture);

  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          readdata <= 0;
      else if (clk_en)
          readdata <= {32'b0 | read_mux_out};
    end


  assign wr_strobe = chipselect && ~write_n;
  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          data_out <= 0;
      else if (clk_en)
          if (wr_strobe)
              data_out <= (address == 5)? data_out & ~writedata[7 : 0]: (address == 4)? data_out | writedata[7 : 0]: (address == 0)? writedata[7 : 0]: data_out;
    end


  assign out_port = data_out;
  assign data_in = in_port;
  assign edge_capture_wr_strobe = chipselect && ~write_n && (address == 3);
  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[0] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[0] <= 0;
          else if (edge_detect[0])
              edge_capture[0] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[1] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[1] <= 0;
          else if (edge_detect[1])
              edge_capture[1] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[2] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[2] <= 0;
          else if (edge_detect[2])
              edge_capture[2] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[3] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[3] <= 0;
          else if (edge_detect[3])
              edge_capture[3] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[4] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[4] <= 0;
          else if (edge_detect[4])
              edge_capture[4] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[5] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[5] <= 0;
          else if (edge_detect[5])
              edge_capture[5] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[6] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[6] <= 0;
          else if (edge_detect[6])
              edge_capture[6] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
          edge_capture[7] <= 0;
      else if (clk_en)
          if (edge_capture_wr_strobe)
              edge_capture[7] <= 0;
          else if (edge_detect[7])
              edge_capture[7] <= -1;
    end


  always @(posedge clk or negedge reset_n)
    begin
      if (reset_n == 0)
        begin
          d1_data_in <= 0;
          d2_data_in <= 0;
        end
      else if (clk_en)
        begin
          d1_data_in <= data_in;
          d2_data_in <= d1_data_in;
        end
    end


  assign edge_detect = d1_data_in & ~d2_data_in;

endmodule

