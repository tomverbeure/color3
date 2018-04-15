## Generated SDC file "bringup.out.sdc"

## Copyright (C) 1991-2013 Altera Corporation
## Your use of Altera Corporation's design tools, logic functions 
## and other software and tools, and its AMPP partner logic 
## functions, and any output files from any of the foregoing 
## (including device programming or simulation files), and any 
## associated documentation or information are expressly subject 
## to the terms and conditions of the Altera Program License 
## Subscription Agreement, Altera MegaCore Function License 
## Agreement, or other applicable license agreement, including, 
## without limitation, that your use is for the sole purpose of 
## programming logic devices manufactured by Altera and sold by 
## Altera or its authorized distributors.  Please refer to the 
## applicable agreement for further details.


## VENDOR  "Altera"
## PROGRAM "Quartus II"
## VERSION "Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"

## DATE    "Sat Apr 14 04:26:10 2018"

##
## DEVICE  "EP4CE30F23C6"
##


#**************************************************************
# Time Information
#**************************************************************

set_time_format -unit ns -decimal_places 3



#**************************************************************
# Create Clock
#**************************************************************

create_clock -name {altera_reserved_tck} -period 10.000 -waveform { 0.000 5.000 } [get_ports { altera_reserved_tck }]
create_clock -name {osc25_pad_in} -period 40.000 -waveform { 0.000 20.000 } [get_ports { osc25_pad_in }]

#**************************************************************
# Create Generated Clock
#**************************************************************

create_generated_clock -name cpu_clk   -source [get_pins {u_cpu_sys|altpll_0|sd1|pll7|inclk[0]}] -duty_cycle 50.000 -multiply_by 4 -divide_by 5 -master_clock {osc25_pad_in} [get_pins {u_cpu_sys|altpll_0|sd1|pll7|clk[0]}] 
create_generated_clock -name sdram_clk -source [get_pins {u_cpu_sys|altpll_0|sd1|pll7|inclk[0]}] -duty_cycle 50.000 -multiply_by 4 -divide_by 1 -master_clock {osc25_pad_in} [get_pins {u_cpu_sys|altpll_0|sd1|pll7|clk[1]}] 
create_generated_clock -name vid_clk   -source [get_pins {u_cpu_sys|altpll_0|sd1|pll7|inclk[0]}] -duty_cycle 50.000 -multiply_by 1 -divide_by 1 -master_clock {osc25_pad_in} [get_pins {u_cpu_sys|altpll_0|sd1|pll7|clk[2]}] 

#**************************************************************
# Set Clock Latency
#**************************************************************



#**************************************************************
# Set Clock Uncertainty
#**************************************************************

set_clock_uncertainty -rise_from [get_clocks {osc25_pad_in}] -rise_to [get_clocks {osc25_pad_in}]  0.020  
set_clock_uncertainty -rise_from [get_clocks {osc25_pad_in}] -fall_to [get_clocks {osc25_pad_in}]  0.020  
set_clock_uncertainty -rise_from [get_clocks {osc25_pad_in}] -rise_to [get_clocks {altera_reserved_tck}]  0.040  
set_clock_uncertainty -rise_from [get_clocks {osc25_pad_in}] -fall_to [get_clocks {altera_reserved_tck}]  0.040  
set_clock_uncertainty -fall_from [get_clocks {osc25_pad_in}] -rise_to [get_clocks {osc25_pad_in}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {osc25_pad_in}] -fall_to [get_clocks {osc25_pad_in}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {osc25_pad_in}] -rise_to [get_clocks {altera_reserved_tck}]  0.040  
set_clock_uncertainty -fall_from [get_clocks {osc25_pad_in}] -fall_to [get_clocks {altera_reserved_tck}]  0.040  
set_clock_uncertainty -rise_from [get_clocks {altera_reserved_tck}] -rise_to [get_clocks {osc25_pad_in}]  0.040  
set_clock_uncertainty -rise_from [get_clocks {altera_reserved_tck}] -fall_to [get_clocks {osc25_pad_in}]  0.040  
set_clock_uncertainty -rise_from [get_clocks {altera_reserved_tck}] -rise_to [get_clocks {altera_reserved_tck}]  0.020  
set_clock_uncertainty -rise_from [get_clocks {altera_reserved_tck}] -fall_to [get_clocks {altera_reserved_tck}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {altera_reserved_tck}] -rise_to [get_clocks {osc25_pad_in}]  0.040  
set_clock_uncertainty -fall_from [get_clocks {altera_reserved_tck}] -fall_to [get_clocks {osc25_pad_in}]  0.040  
set_clock_uncertainty -fall_from [get_clocks {altera_reserved_tck}] -rise_to [get_clocks {altera_reserved_tck}]  0.020  
set_clock_uncertainty -fall_from [get_clocks {altera_reserved_tck}] -fall_to [get_clocks {altera_reserved_tck}]  0.020  


#**************************************************************
# Set Input Delay
#**************************************************************



#**************************************************************
# Set Output Delay
#**************************************************************



#**************************************************************
# Set Clock Groups
#**************************************************************

set_clock_groups -asynchronous -group [get_clocks {altera_reserved_tck}] 


#**************************************************************
# Set False Path
#**************************************************************

set_false_path -to [get_keepers {*altera_std_synchronizer:*|din_s1}]


#**************************************************************
# Set Multicycle Path
#**************************************************************



#**************************************************************
# Set Maximum Delay
#**************************************************************



#**************************************************************
# Set Minimum Delay
#**************************************************************



#**************************************************************
# Set Input Transition
#**************************************************************

