#ifndef SII9233_H
#define SII9233_H

void sii9233_initialize();
int sii9233_i2c_write_reg(byte reg_nr, byte value);
int sii9233_i2c_read_reg(byte reg_nr, byte *value);
void sii9233_reset();
void sii9233_init();

#endif
