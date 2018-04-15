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
    		if(SDA_IN()) d |= 1;
    		SCL(0);
	} 
	if(ack) SDA(0);
	else SDA(1);

	SCL(1);
	i2c_dly();             // send (N)ACK bit
	SCL(0);
	SDA(1);
	return d;
}

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
	b = SDA_IN();          // possible ACK bit
	SCL(0);
	return b;
}

#if 0
void test()
{
	i2c_start();              // send start sequence
	i2c_tx(0xE0);             // SRF08 I2C address with R/W bit clear
	i2c_tx(0x00);             // SRF08 command register address
	i2c_tx(0x51);             // command to start ranging in cm
	i2c_stop();               // send stop sequence

	i2c_start();              // send start sequence
	i2c_tx(0xE0);             // SRF08 I2C address with R/W bit clear
	i2c_tx(0x01);             // SRF08 light sensor register address
	i2c_start();              // send a restart sequence
	i2c_tx(0xE1);             // SRF08 I2C address with R/W bit set
	lightsensor = i2c_rx(1);  // get light sensor and send acknowledge. Internal register address will increment automatically.
	rangehigh = i2c_rx(1);    // get the high byte of the range and send acknowledge.
	rangelow = i2c_rx(0);     // get low byte of the range - note we don't acknowledge the last byte.
	i2c_stop();               // send stop sequence
}
#endif

void sii9136_reset()
{
	IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 0x20);
	i2c_dly();
	IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x20);

	i2c_start();
	i2c_tx(I2C_ADDR_TPI);
	i2c_tx(0xC7);
	i2c_tx(0x00);
	i2c_stop();

	unsigned char id[3];

	i2c_start();              // send start sequence
	i2c_tx(I2C_ADDR_TPI);
	i2c_tx(0x1B);             
	i2c_start();            
	i2c_tx(I2C_ADDR_TPI | 1);          
	id[0] = i2c_rx(1);  
	id[1] = i2c_rx(1);  
	id[2] = i2c_rx(0);  
	i2c_stop();               

	alt_printf("\nDevice ID: %x %x %x\n", id[0], id[1], id[2]);
}

int main()
{ 
	alt_putstr("Hello from Nios II!\n");

	SDA(1);
	SCL(1);

	sii9136_reset();
	
	int i;
	/* Event loop never exits. */
	while (1){
		for(i=0;i<500000;++i){
			IOWR_ALTERA_AVALON_PIO_SET_BITS(PIO_0_BASE, 0x01);
		}
		for(i=0;i<500000;++i){
			IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(PIO_0_BASE, 0x01);
		}
		alt_printf("%x ", IORD_ALTERA_AVALON_PIO_DATA(PIO_0_BASE));
		sii9136_reset();
	}

	return 0;
}
