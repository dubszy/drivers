#ifndef _BCM2835_AUX_H_
#define _BCM2835_AUX_H_

#include "../bcm2835_mem.h"

/* Auxiliaries (0x7E215000 - 0x7E215007) */
/* The actual auxiliaries registers are in
 * bcm2835_uart1.h
 * bcm2835_spi1.h
 * bcm2835_spi2.h
 */

#define AUX_IRQ     0x00 // Auxiliary Interrupt status
#define AUX_ENABLES 0x04 // Auxiliary enables

#endif /* _BCM2835_AUX_H_ */
