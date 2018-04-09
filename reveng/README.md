This directory contains an Altera Quartus project + RTL that is used to reverse engineer
the color3 board.

As such, the design is fluid: as I'm able to figure out more information about the FPGA IO connections, they'll
be added to top.v and the .qsf file until everything is clear.

Don't use this directory as the start for your own designs. It's not intended for that. For example: almost all FPGAs
IOs are marked ```input``` so that they can be traced on SignalTap. That doesn't mean that they are actually a functional
input!

