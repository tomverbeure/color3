

synth:
	~/altera/13.0sp1/quartus/bin/quartus_map --read_settings_files=on --write_settings_files=off color3_reveng -c color3_reveng
	~/altera/13.0sp1/quartus/bin/quartus_fit --read_settings_files=off --write_settings_files=off color3_reveng -c color3_reveng
	~/altera/13.0sp1/quartus/bin/quartus_asm --read_settings_files=off --write_settings_files=off color3_reveng -c color3_reveng
check:
	~/altera/13.0sp1/quartus/bin/quartus_pgm -c "USB-Blaster [1-1]" -a

pgm:
	~/altera/13.0sp1/quartus/bin/quartus_pgm --64bit -c "USB-Blaster [1-1]" pgm_sof.cdf

