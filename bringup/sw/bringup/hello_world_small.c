
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "global.h"

#include "sii9136.h"
#include "sii9233.h"

int main()
{ 
	alt_putstr("\nHello from Nios II!\n");

	sii9136_initialize();
	sii9233_initialize();

    sii9233_reset();
    sii9233_init();
	
	sii9136_reset();
	sii9136_init();

	
	int i;
	/* Event loop never exits. */
	while (1){
		for(i=0;i<500000;++i){
			IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x01);
		}
		for(i=0;i<500000;++i){
			IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 0x01);
		}
		alt_printf("%x\n", IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE));
	}

	return 0;
}
