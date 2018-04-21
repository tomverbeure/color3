
Usage:
`./process.rb sii9233/power_up_to_image.csv > dec.txt`

The `./sii9233` directory contains .csv files with I2C traces that were recorded from 
a working `color3` board. The traces were captured with a Saleae Logic board and decoded
into I2C transactions with its protocol analyzer.

The `process.rb` script reads in the .csv files and tries to annotate all I2C transcations
with known register addresses etc.

