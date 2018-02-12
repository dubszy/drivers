#ifndef _BCM2835_SPI1_2_H_
#define _BCM2835_SPI1_2_H_

#include "../bcm2835_mem.h"

/* SPI1/2 Auxiliaries (0x7E215080 - 0x7E2150BF & 0x7E2150C0 - 0x7E2150FF) */

#define AUX_SPI_CNTL0   0x00
#define AUX_SPI_CNTL1   0x04
#define AUX_SPI_STAT    0x08
#define AUX_SPI_PEEK_1  0x0C
#define AUX_SPI_IO_1    0x10
#define AUX_SPI_PEEK_2  0x14
#define AUX_SPI_IO_2    0x20
#define AUX_SPI_TXHOLD  0x30

#endif /* _BCM2835_SPI1_2_H_ */
