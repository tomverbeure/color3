#ifndef SII9233_H
#define SII9233_H

#define SII9233_REG_DEV_ID		0x02

#define SII9233_REG_SRST		0x05
#define SII9233_REG_SRST_SW_AUTO	0x10

void sii9233_initialize();
int sii9233_i2c_write_reg(byte reg_nr, byte value);
int sii9233_i2c_read_reg(byte reg_nr, byte *value);

void sii9233_dev_id(unsigned int *dev_id, unsigned int *rev);
void sii9233_reset();
void sii9233_init();

#endif
