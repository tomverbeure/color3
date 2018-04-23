
#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "global.h"
#include "i2c.h"
#include "sii9233.h"

#if 1
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

void sii9233_dev_id(unsigned int *dev_id, unsigned int *rev)
{
	unsigned char id[3];
	i2c_read_regs(&sii9233_i2c_ctx, SII9233_I2C_ADDR_RPI, SII9233_REG_DEV_ID, id, 3);

	*dev_id = id[0] | (id[1]<<8);
	*rev = id[2];
}

void sii9233_reset()
{
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

	// Soft reset
	i2c_write_reg(&sii9233_i2c_ctx, SII9233_I2C_ADDR_RPI, SII9233_REG_SRST, SII9233_REG_SRST_SW_AUTO);

	unsigned int dev_id, rev;
	sii9233_dev_id(&dev_id, &rev);

	alt_printf("Device ID: %x, rev: %x\n", dev_id, rev);
}

void sii9233_init()
{
#include "../../../reveng/recordings/sii9233_init.h"
}

