
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "global.h"
#include "i2c.h"

#if 0
#define SII9136_I2C_ADDR_TPI	0x72
#define SII9136_I2C_ADDR_CONF	0x7A
#define SII9136_I2C_ADDR_CPI	0xC0
#else
#define SII9136_I2C_ADDR_TPI	0x76
#define SII9136_I2C_ADDR_CONF	0x7E
#define SII9136_I2C_ADDR_CPI	0xC4
#endif

i2c_ctx_t sii9136_i2c_ctx;

void sii9136_initialize()
{
	sii9136_i2c_ctx.base_addr = PIO_0_BASE;
	sii9136_i2c_ctx.sda_pin_nr = 6;
	sii9136_i2c_ctx.scl_pin_nr = 7;

	i2c_init(&sii9136_i2c_ctx);
}

int sii9136_i2c_write_reg(byte reg_nr, byte value)
{
	int result = i2c_write_reg(&sii9136_i2c_ctx, SII9136_I2C_ADDR_TPI, reg_nr, value);

	if (!result)
		alt_printf("SII9136 reg write fail: %x, %x = %x\n", SII9136_I2C_ADDR_TPI, reg_nr, value);

	return result;
}

int sii9136_i2c_read_reg(byte reg_nr, byte *value)
{
	return i2c_read_reg(&sii9136_i2c_ctx, SII9136_I2C_ADDR_TPI, reg_nr, value);
}

void sii9136_reset()
{
	int result; 

	IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 0x20);
	i2c_dly();
	IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x20);

	result = i2c_write_reg(&sii9136_i2c_ctx, SII9136_I2C_ADDR_TPI, 0xC7, 0x00);
	if (!result){
		alt_printf("Error TPI Mode Enable\n");
	}
	else{
		alt_printf("TPI Mode Enable Ok\n");
	}

	unsigned char id[3];
	i2c_read_regs(&sii9136_i2c_ctx, SII9136_I2C_ADDR_TPI, 0x1b, id, 3);
	alt_printf("Device ID: %x %x %x\n", id[0], id[1], id[2]);
}

void sii9136_init()
{
	alt_u8 status;

	sii9136_i2c_write_reg(0x1A, 0x11);		// disable TMDS output

	sii9136_i2c_write_reg(0x09, 0x00);		// input 8-bit RGB mode
	sii9136_i2c_write_reg(0x1E, 0x00);		// Power up transmitter----Enter full-operation D0 state


	sii9136_i2c_write_reg(0x09, 0x04);		// input 12-bit RGB mode
	sii9136_i2c_write_reg(0x0A, 0x04);		// output 12-bit RGB

	sii9136_i2c_write_reg(0xBC, 0x01);		// Set source termination
	sii9136_i2c_write_reg(0xBD, 0x80);
	sii9136_i2c_write_reg(0xBE, 0x24);

	sii9136_i2c_write_reg(0x19, 0x01);
	sii9136_i2c_write_reg(0x3C, 0x00);		// disable Interrupt
	sii9136_i2c_write_reg(0x3D, 0xF3);		// clear Interrupt Status

	//audio config
	sii9136_i2c_write_reg(0x26, 0x91);
	sii9136_i2c_write_reg(0x25, 0x03);
	sii9136_i2c_write_reg(0x27, 0x00);
	sii9136_i2c_write_reg(0x1f, 0x80);
	sii9136_i2c_write_reg(0x1f, 0x91);
	sii9136_i2c_write_reg(0x1f, 0xa2);
	sii9136_i2c_write_reg(0x1f, 0xb3);
	sii9136_i2c_write_reg(0x20, 0xF0);
	sii9136_i2c_write_reg(0x26, 0x81);		// I2S
	//audio config end

	sii9136_i2c_write_reg(0xBC, 0x02);
	sii9136_i2c_write_reg(0xBD, 0x1D);

	sii9136_i2c_read_reg(0xBE, &status);
	status=status^0x10;
	sii9136_i2c_write_reg(0xBE, status);

	sii9136_i2c_write_reg(0x1A, 0x01);		// enable TMDS output
	sii9136_i2c_write_reg(0x3C, 0xFB);		// Interrupt Enable

	sii9136_i2c_read_reg(0x3D, &status);
	alt_printf("status=%x\n", status);
}


int main()
{ 
	alt_putstr("\nHello from Nios II!\n");

	sii9136_initialize();
	
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
