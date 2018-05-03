#ifdef _CHIPSET_BCM2835_

#ifndef _BCM2835_UART1_H_
#define _BCM2835_UART1_H_

#include "../bcm2835_mem.h"

/* Mini-UART Auxiliary (0x7E215040 - 0x7E21507F) */

#define MU_IO       0x00
#define MU_IER      0x04
#define MU_IIR      0x08
#define MU_LCR      0x0C
#define MU_MCR      0x10
#define MU_LSR      0x14
#define MU_MSR      0x18
#define MU_SCRATCH  0x1C
#define MU_CNTL     0x20
#define MU_STAT     0x24
#define MU_BAUD     0x28

#endif /* _BCM2835_UART1_H_ */

#endif /* _CHIPSET_BCM2835_ */
