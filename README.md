
# Introduction

This repo contains information about the (obsolete) eeColor Color3 board.

See also [here](https://hackaday.io/project/122480-eecolor-color3)

Most of the information here was copied from 
[this blog post](http://www.taylorkillian.com/2013/04/using-fpga-of-eecolor-color3.html) by Taylor Killian.

# Chips

* Altera Cyclone IV EP4CE30F23C6N FPGA
* 128P33BF60 16MByte parallel flash
    This flash is used to configure the FPGA on the board at bootup.
    The bitstream takes up around 9MB, so 7MB can be used for other purposes.
* Micron MT48LC8M16A2-75
    128Mbit DRAM (4M x 16bits). 
* Silicon Image SiI9233ACTU 4-port HDMI Receiver
* Silicon Image SiI9136ACTU HDMI Transmitter

# Silicon Image Chips

One of the really nice features of the Silicon Image chips is that they support HDCP 1.4. This version of
HDCP may be completely broken (with a little bit of googling, everybody could create their own keys if they
wanted to), but it's still pretty much impossible for a hobbyist decode live HDCP 'protected' video content.

With this board, one should be able to work around that.

A big caveat here is that the programming guide for these chips is available only under NDA for HDCP license
holders.

The best we can hope for is that we can get these chips to work by spying transactions on the I2C bus that runs
between the FPGA and the SI chips.

# Resources

* [Micron 48LC8M16A2 datasheet](https://www.micron.com/parts/dram/sdram/mt48lc8m16a2f4-75-it)
* [SiI9233A datasheet](http://www.latticesemi.com/view_document?document_id=51624). 
  [Copy on Arrow Electronics](https://www.arrow.com/en/products/sii9233actu-c/lattice-semiconductor)
* [SiI9136 datasheet](http://www.latticesemi.com/view_document?document_id=51622)
