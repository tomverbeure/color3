
# (C) 2001-2018 Altera Corporation. All rights reserved.
# Your use of Altera Corporation's design tools, logic functions and 
# other software and tools, and its AMPP partner logic functions, and 
# any output files any of the foregoing (including device programming 
# or simulation files), and any associated documentation or information 
# are expressly subject to the terms and conditions of the Altera 
# Program License Subscription Agreement, Altera MegaCore Function 
# License Agreement, or other applicable license agreement, including, 
# without limitation, that your use is for the sole purpose of 
# programming logic devices manufactured by Altera and sold by Altera 
# or its authorized distributors. Please refer to the applicable 
# agreement for further details.

# ACDS 13.0sp1 232 linux 2018.04.23.00:43:17

# ----------------------------------------
# vcs - auto-generated simulation script

# ----------------------------------------
# initialize variables
TOP_LEVEL_NAME="cpu_sys"
QSYS_SIMDIR="./../../"
QUARTUS_INSTALL_DIR="/home/vagrant/altera/13.0sp1/quartus/"
SKIP_FILE_COPY=0
SKIP_ELAB=0
SKIP_SIM=0
USER_DEFINED_ELAB_OPTIONS=""
USER_DEFINED_SIM_OPTIONS="+vcs+finish+100"
# ----------------------------------------
# overwrite variables - DO NOT MODIFY!
# This block evaluates each command line argument, typically used for 
# overwriting variables. An example usage:
#   sh <simulator>_setup.sh SKIP_ELAB=1 SKIP_SIM=1
for expression in "$@"; do
  eval $expression
  if [ $? -ne 0 ]; then
    echo "Error: This command line argument, \"$expression\", is/has an invalid expression." >&2
    exit $?
  fi
done

# ----------------------------------------
# copy RAM/ROM files to simulation directory
if [ $SKIP_FILE_COPY -eq 0 ]; then
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_ociram_default_contents.mif ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_rf_ram_b.hex ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_rf_ram_b.mif ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_rf_ram_a.dat ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_ociram_default_contents.dat ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_rf_ram_b.dat ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_ociram_default_contents.hex ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_rf_ram_a.hex ./
  cp -f $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_rf_ram_a.mif ./
fi

vcs -lca -timescale=1ps/1ps -sverilog +verilog2001ext+.v -ntb_opts dtm $USER_DEFINED_ELAB_OPTIONS \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/altera_primitives.v \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/220model.v \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/sgate.v \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/altera_mf.v \
  $QUARTUS_INSTALL_DIR/eda/sim_lib/altera_lnsim.sv \
  -v $QUARTUS_INSTALL_DIR/eda/sim_lib/cycloneive_atoms.v \
  $QSYS_SIMDIR/submodules/cpu_sys_irq_mapper.sv \
  $QSYS_SIMDIR/submodules/altera_merlin_arbitrator.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_rsp_xbar_mux_001.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_rsp_xbar_mux.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_rsp_xbar_demux_001.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_cmd_xbar_mux.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_cmd_xbar_demux_001.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_cmd_xbar_demux.sv \
  $QSYS_SIMDIR/submodules/altera_reset_controller.v \
  $QSYS_SIMDIR/submodules/altera_reset_synchronizer.v \
  $QSYS_SIMDIR/submodules/cpu_sys_id_router_001.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_id_router.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_addr_router_001.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_addr_router.sv \
  $QSYS_SIMDIR/submodules/altera_avalon_sc_fifo.v \
  $QSYS_SIMDIR/submodules/altera_merlin_slave_agent.sv \
  $QSYS_SIMDIR/submodules/altera_merlin_burst_uncompressor.sv \
  $QSYS_SIMDIR/submodules/altera_merlin_master_agent.sv \
  $QSYS_SIMDIR/submodules/altera_merlin_slave_translator.sv \
  $QSYS_SIMDIR/submodules/altera_merlin_master_translator.sv \
  $QSYS_SIMDIR/submodules/cpu_sys_jtag_uart_0.v \
  $QSYS_SIMDIR/submodules/cpu_sys_pio_0.v \
  $QSYS_SIMDIR/submodules/cpu_sys_cpu_mem.v \
  $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_jtag_debug_module_tck.v \
  $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_oci_test_bench.v \
  $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0.v \
  $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_jtag_debug_module_sysclk.v \
  $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_test_bench.v \
  $QSYS_SIMDIR/submodules/cpu_sys_nios2_qsys_0_jtag_debug_module_wrapper.v \
  $QSYS_SIMDIR/submodules/cpu_sys_altpll_0.vo \
  $QSYS_SIMDIR/cpu_sys.v \
  -top $TOP_LEVEL_NAME
# ----------------------------------------
# simulate
if [ $SKIP_SIM -eq 0 ]; then
  ./simv $USER_DEFINED_SIM_OPTIONS
fi
