#ifdef _CHIPSET_BCM2835_

#ifndef _BCM2835_PCM_H_
#define _BCM2835_PCM_H_

#include "../bcm2835_mem.h"

/* PCM (0x7E101098 - 0x7E101099) */

/* PCM (0x7E203000 - 0x7E20301F) */
#define PCM_CS_A                    0x00 // Control and Status
#define PCM_FIFO_A                  0x04 // FIFO Data
#define PCM_MODE_A                  0x08 // Mode
#define PCM_RXC_A                   0x0C // Receive Configuration
#define PCM_TXC_A                   0x10 // Transmit Configuration
#define PCM_DREQ_A                  0x14 // DMA Request Level
#define PCM_INTEN_A                 0x18 // Interrupt Enables
#define PCM_INTSTC_A                0x1C // Interrupt Status & Clear
#define PCM_GRAY                    0x20 // Gray Mode Control

#endif /* _BCM2835_PCM_H_ */

#endif /* _CHIPSET_BCM2835_ */
