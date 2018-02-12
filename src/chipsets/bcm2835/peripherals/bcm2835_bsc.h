#ifndef _BCM2835_BSC_H_
#define _BCM2835_BSC_H_

#include "../bcm2835_mem.h"

/*
 * BSC0 (0x7E205000 - 0x7E205FFF)
 * BSC1 (0x7E804000 - 0x7E804FFF)
 * BSC2 (0x7E805000 - 0x7E805FFF)
 */

#define BSC_C       0x00 // Control
#define BSC_S       0x04 // Status
#define BSC_DLEN    0x08 // Data Length
#define BSC_A       0x0C // Slave Address
#define BSC_FIFO    0x10 // Data FIFO
#define BSC_DIV     0x14 // Clock Divider
#define BSC_DEL     0x18 // Data Delay
#define BSC_CLKT    0x1C // Clock Stretch Timeout

#endif /* _BCM2835_BSC_H_ */
