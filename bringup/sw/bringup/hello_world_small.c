/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

#if 0
#define I2C_ADDR_TPI	0x72
#define I2C_ADDR_CONF	0x7A
#define I2C_ADDR_CPI	0xC0
#else
#define I2C_ADDR_TPI	0x76
#define I2C_ADDR_CONF	0x7E
#define I2C_ADDR_CPI	0xC4
#endif

typedef unsigned char byte;

void SCL(int bit)
{
	if (bit)
		IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x80);
	else
		IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 0x80);
}

void SDA(int bit)
{
	if (bit)
		IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x40);
	else
		IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 0x40);
}

int SCL_IN()
{
	return (IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE) >> 7) & 1;
}

int SDA_IN()
{
	return (IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE) >> 6) & 1;
}


void i2c_dly(void)
{
	int i;
	for(i=0;i<10000;++i){
		IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x01);
	}
}

void i2c_start(void)
{
	SDA(1);             // i2c start bit sequence
	i2c_dly();
	SCL(1);
	i2c_dly();
	SDA(0);
	i2c_dly();
	SCL(0);
	i2c_dly();
}

void i2c_stop(void)
{
	SDA(0);             // i2c stop bit sequence
	i2c_dly();
	SCL(1);
	i2c_dly();
	SDA(1);
	i2c_dly();
}

unsigned char i2c_rx(char ack)
{
	char x, d=0;
	SDA(1); 
	for(x=0; x<8; x++) {
		d <<= 1;
		do {
			SCL(1);
    		}
    		while(SCL_IN()==0);    // wait for any SCL clock stretching

    		i2c_dly();
		d |= SDA_IN();
    		SCL(0);
	} 
	if(ack) 
		SDA(0);
	else 
		SDA(1);

	SCL(1);
	i2c_dly();             // send (N)ACK bit
	SCL(0);
	SDA(1);
	return d;
}

// return 1: ACK, 0: NACK
int i2c_tx(unsigned char d)
{
	char x;
	static int b;
	for(x=8; x; x--) {
		if(d&0x80) SDA(1);
		else SDA(0);
		SCL(1);
		d <<= 1;
		SCL(0);
	}
	SDA(1);
	SCL(1);
	i2c_dly();
	b = !SDA_IN();          // possible ACK bit
	SCL(0);
	return b;
}

int i2c_write_buf(byte addr, byte* data, int len)
{
	int ack;

	i2c_start();
	ack = i2c_tx(addr);
	if (!ack)
		return 0;

	int i;
	for(i=0;i<len;++i){
		ack = i2c_tx(data[i]);
		if (!ack)
			return 0;
	}

	i2c_stop();

	return 1;
}

int i2c_read_buf(byte addr, byte *data, int len)
{
	int ack;

	i2c_start();            

	ack = i2c_tx(addr | 1);          
	if (!ack)
		return 0;

	int i;
	for(i=0;i<len;++i){
		data[i] = i2c_rx(i!=len-1);
	}
	i2c_stop();               

	return 1;
}

int i2c_write_reg(byte addr, byte reg_nr, byte value)
{
	byte data[2] = { reg_nr, value };

	return i2c_write_buf(addr, data, 2);
}

int i2c_read_reg(byte addr, byte reg_nr, byte *value)
{
	int result;

	// Set address to read
	result = i2c_write_buf(addr, &reg_nr, 1);
	if (!result)
		return 0;

	result = i2c_read_buf(addr, value, 1);
	if (!result)
		return 0;

	return 1;
}

int i2c_read_regs(byte addr, byte reg_nr, byte *values, int len)
{
	int result;

	// Set address to read
	result = i2c_write_buf(addr, &reg_nr, 1);
	if (!result)
		return 0;

	result = i2c_read_buf(addr, values, len);
	if (!result)
		return 0;

	return 1;
}

int sii9136_i2c_write_reg(byte reg_nr, byte value)
{
	int result = i2c_write_reg(I2C_ADDR_TPI, reg_nr, value);

	if (!result)
		alt_printf("SII9136 reg write fail: %x, %x = %x\n", I2C_ADDR_TPI, reg_nr, value);

	return result;
}

int sii9136_i2c_read_reg(byte reg_nr, byte *value)
{
	return i2c_read_reg(I2C_ADDR_TPI, reg_nr, value);
}

void sii9136_reset()
{
	int result; 

	IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 0x20);
	i2c_dly();
	IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x20);

	result = i2c_write_reg(I2C_ADDR_TPI, 0xC7, 0x00);
	if (!result){
		alt_printf("Error TPI Mode Enable\n");
	}
	else{
		alt_printf("TPI Mode Enable Ok\n");
	}

	unsigned char id[3];
	i2c_read_regs(I2C_ADDR_TPI, 0x1b, id, 3);
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

	SDA(1);
	SCL(1);

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
		sii9136_reset();
	}

	return 0;
}
