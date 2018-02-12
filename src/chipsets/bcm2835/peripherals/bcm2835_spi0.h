#ifndef _BCM2835_SPI0_H_
#define _BCM2835_SPI0_H_

#include "../bcm2835_mem.h"

/* SPI (0x7E204000 - 0x7E204FFF) */

#define SPI_CS      0x00 // Master Control and Status
#define SPI_FIFO    0x04 // Master TX and RX FIFOs
#define SPI_CLK     0x08 // Master Clock Divider
#define SPI_DLEN    0x0C // Master Data Length
#define SPI_LTOH    0x10 // LOSSI mode TOH
#define SPI_DC      0x14 // DMA DREQ Controls

#endif /* _BCM2835_SPI0_H_ */
