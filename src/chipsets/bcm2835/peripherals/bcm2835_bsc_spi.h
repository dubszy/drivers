#ifndef _BCM2835_BSC_SPI_H_
#define _BCM2835_BSC_SPI_H_

#include "../bcm2835_mem.h"

/* BSC/SPI (0x7E214000) */

#define BSC_DR      0x00 // Data
#define BSC_RSR     0x04 // Operation status/error clear
#define BSC_SLV     0x08 // I2C SPI Address
#define BSC_CR      0x0C // Control
#define BSC_FR      0x10 // Flag
#define BSC_IFLS    0x14 // Interrupt FIFO Level Select
#define BSC_IMSC    0x18 // Interrupt Mask Set Clear
#define BSC_RIS     0x1C // Raw Interrupt Status
#define BSC_MIS     0x20 // Masked Interrupt Status
#define BSC_ICR     0x24 // Interrupt Clear
#define BSC_DMACR   0x28 // DMA Control
#define BSC_TDR     0x2C // FIFO Test Data
#define BSC_GPUSTAT 0x30 // GPU Status
#define BSC_HCTRL   0x34 // Host Control
#define BSC_DEBUG1  0x38 // I2C Debug
#define BSC_DEBUG2  0x3C // SPI Debug

#endif /* _BCM2835_BSC_SPI_H_ */
