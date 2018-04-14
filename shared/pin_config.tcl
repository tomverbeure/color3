

set_location_assignment PIN_A12 -to osc25_pad_in

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to osc25_pad_in

#============================================================
# Miscellaneous
#============================================================

set_location_assignment PIN_D6   -to led_b_pad_out
set_location_assignment PIN_AB18 -to led_g_pad_out
set_location_assignment PIN_AB19 -to led_r_pad_out

set_location_assignment PIN_E7 -to button
set_location_assignment PIN_E9 -to ir_rx

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to led_b_pad_out
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to led_g_pad_out
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to led_r_pad_out

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to button
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to ir_rx

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to altera_reserved_tck
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to altera_reserved_tdi
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to altera_reserved_tdo
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to altera_reserved_tms

#============================================================
# Flash
#============================================================

set_location_assignment PIN_K2  -to flash_dclk
set_location_assignment PIN_E4  -to flash_nreset
set_location_assignment PIN_E2  -to flash_nce
set_location_assignment PIN_E21 -to flash_noe
set_location_assignment PIN_F20 -to flash_navd
set_location_assignment PIN_E22 -to flash_nwe
#set_location_assignment PIN_ -to flash_wait
set_location_assignment PIN_G18 -to flash_padd[23]
set_location_assignment PIN_B22 -to flash_padd[22]
set_location_assignment PIN_B21 -to flash_padd[21]
set_location_assignment PIN_C20 -to flash_padd[20]
set_location_assignment PIN_A6  -to flash_padd[19]
set_location_assignment PIN_A7  -to flash_padd[18]
set_location_assignment PIN_B9  -to flash_padd[17]
set_location_assignment PIN_A9  -to flash_padd[16]
set_location_assignment PIN_B10 -to flash_padd[15]
set_location_assignment PIN_F11 -to flash_padd[14]
set_location_assignment PIN_E11 -to flash_padd[13]
set_location_assignment PIN_B13 -to flash_padd[12]
set_location_assignment PIN_A13 -to flash_padd[11]
set_location_assignment PIN_B14 -to flash_padd[10]
set_location_assignment PIN_A14 -to flash_padd[9]
set_location_assignment PIN_D13 -to flash_padd[8]
set_location_assignment PIN_C13 -to flash_padd[7]
set_location_assignment PIN_B15 -to flash_padd[6]
set_location_assignment PIN_A15 -to flash_padd[5]
set_location_assignment PIN_F13 -to flash_padd[4]
set_location_assignment PIN_E14 -to flash_padd[3]
set_location_assignment PIN_B17 -to flash_padd[2]
set_location_assignment PIN_A17 -to flash_padd[1]
set_location_assignment PIN_B18 -to flash_padd[0]

set_location_assignment PIN_B6  -to flash_data[15]
set_location_assignment PIN_C8  -to flash_data[14]
set_location_assignment PIN_C7  -to flash_data[13]
set_location_assignment PIN_C4  -to flash_data[12]
set_location_assignment PIN_B3  -to flash_data[11]
set_location_assignment PIN_A3  -to flash_data[10]
set_location_assignment PIN_F8  -to flash_data[9]
set_location_assignment PIN_B4  -to flash_data[8]
set_location_assignment PIN_C6  -to flash_data[7]
set_location_assignment PIN_F10 -to flash_data[6]
set_location_assignment PIN_A5  -to flash_data[5]
set_location_assignment PIN_B7  -to flash_data[4]
set_location_assignment PIN_B8  -to flash_data[3]
set_location_assignment PIN_A8  -to flash_data[2]
set_location_assignment PIN_D1  -to flash_data[1]
set_location_assignment PIN_K1  -to flash_data[0]

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_dclk
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_navd
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_nce
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_noe
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_nreset
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_nwe
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[15]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[14]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[13]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_data[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[23]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[22]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[21]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[20]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[19]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[18]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[17]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[16]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[15]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[14]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[13]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to flash_padd[0]

#============================================================
# SDRAM
#============================================================

set_location_assignment PIN_F14 -to dram_a_pad_out[11]
set_location_assignment PIN_E13 -to dram_a_pad_out[10]
set_location_assignment PIN_G13 -to dram_a_pad_out[9]
set_location_assignment PIN_H11 -to dram_a_pad_out[8]
set_location_assignment PIN_G11 -to dram_a_pad_out[7]
set_location_assignment PIN_H10 -to dram_a_pad_out[6]
set_location_assignment PIN_G10 -to dram_a_pad_out[5]
set_location_assignment PIN_E10 -to dram_a_pad_out[4]
set_location_assignment PIN_A10 -to dram_a_pad_out[3]
set_location_assignment PIN_C10 -to dram_a_pad_out[2]
set_location_assignment PIN_D10 -to dram_a_pad_out[1]
set_location_assignment PIN_E12 -to dram_a_pad_out[0]
set_location_assignment PIN_C15 -to dram_ba_pad_out[1]
set_location_assignment PIN_D15 -to dram_ba_pad_out[0]
set_location_assignment PIN_B16 -to dram_cas_n_pad_out
set_location_assignment PIN_H14 -to dram_cke_pad_out
set_location_assignment PIN_A20 -to dram_clk_pad_out
set_location_assignment PIN_E15 -to dram_cs_n_pad_out
set_location_assignment PIN_H17 -to dram_dq_pad_inout[15]
set_location_assignment PIN_G17 -to dram_dq_pad_inout[14]
set_location_assignment PIN_F17 -to dram_dq_pad_inout[13]
set_location_assignment PIN_H16 -to dram_dq_pad_inout[12]
set_location_assignment PIN_G16 -to dram_dq_pad_inout[11]
set_location_assignment PIN_F16 -to dram_dq_pad_inout[10]
set_location_assignment PIN_H15 -to dram_dq_pad_inout[9]
set_location_assignment PIN_G15 -to dram_dq_pad_inout[8]
set_location_assignment PIN_D17 -to dram_dq_pad_inout[7]
set_location_assignment PIN_A18 -to dram_dq_pad_inout[6]
set_location_assignment PIN_A19 -to dram_dq_pad_inout[5]
set_location_assignment PIN_B19 -to dram_dq_pad_inout[4]
set_location_assignment PIN_C19 -to dram_dq_pad_inout[3]
set_location_assignment PIN_D19 -to dram_dq_pad_inout[2]
set_location_assignment PIN_B20 -to dram_dq_pad_inout[1]
set_location_assignment PIN_D20 -to dram_dq_pad_inout[0]
set_location_assignment PIN_F15 -to dram_dqm_pad_inout[1]
set_location_assignment PIN_C17 -to dram_dqm_pad_inout[0]
set_location_assignment PIN_A16 -to dram_ras_n_pad_out
set_location_assignment PIN_E16 -to dram_we_n_pad_out

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_cas_n_pad_out
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_cke_pad_out
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_clk_pad_out
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_cs_n_pad_out
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_a_pad_out[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_ba_pad_out[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_ba_pad_out[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[15]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[14]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[13]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dq_pad_inout[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dqm_pad_inout[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_dqm_pad_inout[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_ras_n_pad_out
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dram_we_n_pad_out


#============================================================
# SII9136
#============================================================
set_location_assignment PIN_AB20 -to sii9136_reset_
set_location_assignment PIN_AA20 -to sii9136_int

set_location_assignment PIN_W20 -to sii9136_cscl
set_location_assignment PIN_U20 -to sii9136_csda

set_location_assignment PIN_R16 -to sii9136_idck
set_location_assignment PIN_H19 -to sii9136_vsync
set_location_assignment PIN_F19 -to sii9136_hsync
set_location_assignment PIN_H18 -to sii9136_de

set_location_assignment PIN_AA21 -to sii9136_d[35]
set_location_assignment PIN_Y21 -to sii9136_d[34]
set_location_assignment PIN_Y22 -to sii9136_d[33]
set_location_assignment PIN_W21 -to sii9136_d[32]
set_location_assignment PIN_W22 -to sii9136_d[31]
set_location_assignment PIN_V21 -to sii9136_d[30]
set_location_assignment PIN_V22 -to sii9136_d[29]
set_location_assignment PIN_U21 -to sii9136_d[28]
set_location_assignment PIN_U22 -to sii9136_d[27]
set_location_assignment PIN_R20 -to sii9136_d[26]
set_location_assignment PIN_R21 -to sii9136_d[25]
set_location_assignment PIN_R22 -to sii9136_d[24]
set_location_assignment PIN_P20 -to sii9136_d[23]
set_location_assignment PIN_P21 -to sii9136_d[22]
set_location_assignment PIN_P22 -to sii9136_d[21]
set_location_assignment PIN_N20 -to sii9136_d[20]
set_location_assignment PIN_N21 -to sii9136_d[19]
set_location_assignment PIN_N22 -to sii9136_d[18]
set_location_assignment PIN_M20 -to sii9136_d[17]
set_location_assignment PIN_M21 -to sii9136_d[16]
set_location_assignment PIN_M22 -to sii9136_d[15]
set_location_assignment PIN_L21 -to sii9136_d[14]
set_location_assignment PIN_L22 -to sii9136_d[13]
set_location_assignment PIN_K21 -to sii9136_d[12]
set_location_assignment PIN_J21 -to sii9136_d[10]
set_location_assignment PIN_J22 -to sii9136_d[9]
set_location_assignment PIN_H20 -to sii9136_d[8]
set_location_assignment PIN_H21 -to sii9136_d[7]
set_location_assignment PIN_H22 -to sii9136_d[6]
set_location_assignment PIN_F21 -to sii9136_d[5]
set_location_assignment PIN_F22 -to sii9136_d[4]
set_location_assignment PIN_D21 -to sii9136_d[3]
set_location_assignment PIN_D22 -to sii9136_d[2]
set_location_assignment PIN_C21 -to sii9136_d[1]
set_location_assignment PIN_C22 -to sii9136_d[0]

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_vsync
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_cscl
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_csda
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_de
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_hsync
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_idck
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_int
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_reset_

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[35]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[34]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[33]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[32]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[31]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[30]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[29]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[28]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[27]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[26]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[25]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[24]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[23]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[22]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[21]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[20]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[19]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[18]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[17]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[16]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[15]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[14]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[13]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9136_d[0]


#============================================================
# SII9233
#============================================================
set_location_assignment PIN_Y3 -to sii9233_reset_
set_location_assignment PIN_Y4 -to sii9233_int

set_location_assignment PIN_V4 -to sii9233_cscl
set_location_assignment PIN_V5 -to sii9233_csda

set_location_assignment PIN_AB11 -to sii9233_odck
set_location_assignment PIN_J4 -to sii9233_vsync
set_location_assignment PIN_M4 -to sii9233_hsync
set_location_assignment PIN_E3 -to sii9233_de

set_location_assignment PIN_M3 -to sii9233_q[35]
set_location_assignment PIN_M2 -to sii9233_q[34]
set_location_assignment PIN_M1 -to sii9233_q[33]
set_location_assignment PIN_J3 -to sii9233_q[32]
set_location_assignment PIN_J2 -to sii9233_q[31]
set_location_assignment PIN_J1 -to sii9233_q[30]
set_location_assignment PIN_H2 -to sii9233_q[29]
set_location_assignment PIN_H1 -to sii9233_q[28]
set_location_assignment PIN_G4 -to sii9233_q[27]
set_location_assignment PIN_G3 -to sii9233_q[26]
set_location_assignment PIN_F2 -to sii9233_q[25]
set_location_assignment PIN_F1 -to sii9233_q[24]
set_location_assignment PIN_E1 -to sii9233_q[23]
set_location_assignment PIN_D2 -to sii9233_q[22]
set_location_assignment PIN_C2 -to sii9233_q[21]
set_location_assignment PIN_C1 -to sii9233_q[20]
set_location_assignment PIN_B2 -to sii9233_q[19]
set_location_assignment PIN_B1 -to sii9233_q[18]

set_location_assignment PIN_N1 -to sii9233_q[17]
set_location_assignment PIN_N2 -to sii9233_q[16]
set_location_assignment PIN_P1 -to sii9233_q[15]
set_location_assignment PIN_P2 -to sii9233_q[14]
set_location_assignment PIN_P3 -to sii9233_q[13]
set_location_assignment PIN_R1 -to sii9233_q[12]
set_location_assignment PIN_R2 -to sii9233_q[11]
set_location_assignment PIN_T3 -to sii9233_q[10]
set_location_assignment PIN_U1 -to sii9233_q[9]
set_location_assignment PIN_U2 -to sii9233_q[8]
set_location_assignment PIN_V1 -to sii9233_q[7]
set_location_assignment PIN_V2 -to sii9233_q[6]
set_location_assignment PIN_V3 -to sii9233_q[5]
set_location_assignment PIN_W1 -to sii9233_q[4]
set_location_assignment PIN_W2 -to sii9233_q[3]
set_location_assignment PIN_Y1 -to sii9233_q[2]
set_location_assignment PIN_Y2 -to sii9233_q[1]
set_location_assignment PIN_AA1 -to sii9233_q[0]

set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_reset_
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_vsync
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_odck
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_cscl
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_csda
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_de
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_hsync
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_int
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[35]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[34]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[33]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[32]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[31]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[30]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[29]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[28]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[27]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[26]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[25]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[24]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[23]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[22]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[21]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[20]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[19]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[18]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[17]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[16]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[15]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[14]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[13]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to sii9233_q[0]

#============================================================
# IOBANK Voltages
#============================================================
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 6
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 5
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 7
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 8
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 1
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 2
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 3
set_global_assignment -name IOBANK_VCCIO 3.3V -section_id 4

