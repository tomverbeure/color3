
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "global.h"
#include "i2c.h"
#include "sii9233.h"

#if 0
#define SII9233_I2C_ADDR_RPI	0x60
#define SII9233_I2C_ADDR_CONF	0x68
#else
#define SII9233_I2C_ADDR_RPI	0x62
#define SII9233_I2C_ADDR_CONF	0x6A
#endif

i2c_ctx_t sii9233_i2c_ctx;

void sii9233_initialize()
{
	sii9233_i2c_ctx.base_addr = PIO_0_BASE;
	sii9233_i2c_ctx.sda_pin_nr = 14;
	sii9233_i2c_ctx.scl_pin_nr = 15;

	i2c_init(&sii9233_i2c_ctx);
}

int sii9233_i2c_write_reg(byte reg_nr, byte value)
{
	int result = i2c_write_reg(&sii9233_i2c_ctx, SII9233_I2C_ADDR_RPI, reg_nr, value);

	if (!result)
		alt_printf("SII9233 reg write fail: %x, %x = %x\n", SII9233_I2C_ADDR_RPI, reg_nr, value);

	return result;
}

int sii9233_i2c_read_reg(byte reg_nr, byte *value)
{
	return i2c_read_reg(&sii9233_i2c_ctx, SII9233_I2C_ADDR_RPI, reg_nr, value);
}

void sii9233_reset()
{
	int result; 

	// Toggle reset pin
	IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 1<<13);
	i2c_dly();
	IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 1<<13);

	// I2C address-only transaction to check if there's an ACK.
	i2c_start(&sii9233_i2c_ctx);
	int ack = i2c_tx(&sii9233_i2c_ctx, SII9233_I2C_ADDR_RPI);
	i2c_stop(&sii9233_i2c_ctx);

	if (!ack){
		alt_printf("SII9233 not responding!\n");
	}
	else{
		alt_printf("SII9233 present!\n");
	}

	unsigned char id[3];
	i2c_read_regs(&sii9233_i2c_ctx, SII9233_I2C_ADDR_RPI, 0x1b, id, 3);
	alt_printf("Device ID: %x %x %x\n", id[0], id[1], id[2]);
}

void sii9233_init()
{
	alt_u8 status;

	sii9233_i2c_write_reg(0x1A, 0x11);		// disable TMDS output

	sii9233_i2c_write_reg(0x09, 0x00);		// input 8-bit RGB mode
	sii9233_i2c_write_reg(0x1E, 0x00);		// Power up transmitter----Enter full-operation D0 state


	sii9233_i2c_write_reg(0x09, 0x04);		// input 12-bit RGB mode
	sii9233_i2c_write_reg(0x0A, 0x04);		// output 12-bit RGB

	sii9233_i2c_write_reg(0xBC, 0x01);		// Set source termination
	sii9233_i2c_write_reg(0xBD, 0x80);
	sii9233_i2c_write_reg(0xBE, 0x24);

	sii9233_i2c_write_reg(0x19, 0x01);
	sii9233_i2c_write_reg(0x3C, 0x00);		// disable Interrupt
	sii9233_i2c_write_reg(0x3D, 0xF3);		// clear Interrupt Status

	//audio config
	sii9233_i2c_write_reg(0x26, 0x91);
	sii9233_i2c_write_reg(0x25, 0x03);
	sii9233_i2c_write_reg(0x27, 0x00);
	sii9233_i2c_write_reg(0x1f, 0x80);
	sii9233_i2c_write_reg(0x1f, 0x91);
	sii9233_i2c_write_reg(0x1f, 0xa2);
	sii9233_i2c_write_reg(0x1f, 0xb3);
	sii9233_i2c_write_reg(0x20, 0xF0);
	sii9233_i2c_write_reg(0x26, 0x81);		// I2S
	//audio config end

	sii9233_i2c_write_reg(0xBC, 0x02);
	sii9233_i2c_write_reg(0xBD, 0x1D);

	sii9233_i2c_read_reg(0xBE, &status);
	status=status^0x10;
	sii9233_i2c_write_reg(0xBE, status);

	sii9233_i2c_write_reg(0x1A, 0x01);		// enable TMDS output
	sii9233_i2c_write_reg(0x3C, 0xFB);		// Interrupt Enable

	sii9233_i2c_read_reg(0x3D, &status);
	alt_printf("status=%x\n", status);
}

