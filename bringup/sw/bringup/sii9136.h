#ifndef SII9136_H
#define SII9136_H

void sii9136_initialize();
int sii9136_i2c_write_reg(byte reg_nr, byte value);
int sii9136_i2c_read_reg(byte reg_nr, byte *value);
void sii9136_reset();
void sii9136_init();

#endif
