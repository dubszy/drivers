#ifndef _BCM2835_PWM_H_
#define _BCM2835_PWM_H_

#include "../bcm2835_mem.h"

/* PWM (0x7E20C000 - 0x7E20C027) */

#define PWM_CTL     0x00 // Control
#define PWM_STA     0x04 // Status
#define PWM_DMAC    0x08 // DMA Configuration
#define PWM_RNG1    0x10 // Channel 1 Range
#define PWM_DAT1    0x14 // Channel 1 Data
#define PWM_FIF1    0x18 // FIFO Input
#define PWM_RNG2    0x20 // Channel 2 Range
#define PWM_DAT2    0x24 // Channel 2 Data

#endif
