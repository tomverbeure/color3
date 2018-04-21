

synth:
	~/altera/13.0sp1/quartus/bin/quartus_map --read_settings_files=on --write_settings_files=off bringup -c bringup
	~/altera/13.0sp1/quartus/bin/quartus_fit --read_settings_files=off --write_settings_files=off bringup -c bringup
	~/altera/13.0sp1/quartus/bin/quartus_asm --read_settings_files=off --write_settings_files=off bringup -c bringup
check:
	~/altera/13.0sp1/quartus/bin/quartus_pgm -c "USB-Blaster [1-1]" -a

pgm:
	~/altera/13.0sp1/quartus/bin/quartus_pgm -c "USB-Blaster [1-1]" bringup.cdf

