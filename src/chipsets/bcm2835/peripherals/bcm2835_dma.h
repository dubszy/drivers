#ifndef _BCM2835_DMA_H_
#define _BCM2835_DMA_H_

#include "../bcm2835_mem.h"

/*
 * DMA   (0x7E007000 - 0x7E007EFF)
 * DMA15 (0x7EE05000)
 */

#define DMA_CH0         0x000 // DMA Channel 0
#define DMA_CH1         0x100 // DMA Channel 1
#define DMA_CH2         0x200 // DMA Channel 2
#define DMA_CH3         0x300 // DMA Channel 3
#define DMA_CH4         0x400 // DMA Channel 4
#define DMA_CH5         0x500 // DMA Channel 5
#define DMA_CH6         0x600 // DMA Channel 6
#define DMA_CH7         0x700 // DMA Channel 7
#define DMA_CH8         0x800 // DMA Channel 8
#define DMA_CH9         0x900 // DMA Channel 9
#define DMA_CH10        0xA00 // DMA Channel 10
#define DMA_CH11        0xB00 // DMA Channel 11
#define DMA_CH12        0xC00 // DMA Channel 12
#define DMA_CH13        0xD00 // DMA Channel 13
#define DMA_CH14        0xE00 // DMA Channel 14

#define DMA_INT_STATUS  0xFE0 // Interrupt Status
#define DMA_ENABLE      0xFF0 // DMA Enable

#define DMA_CS          0x00 // Control and Status
#define DMA_CONBLK_AD   0x04 // Control Block Address
#define DMA_TI          0x08 // Transfer Information (CB Word 0)
#define DMA_SOURCE_AD   0x0C // Source Address (CB Word 1)
#define DMA_DEST_AD     0x10 // Destination Address (CB Word 2)
#define DMA_TXFR_LEN    0x14 // Transfer Length (CB Word 3)
#define DMA_STRIDE      0x18 // 2D Stride (CB Word 4)
#define DMA_NEXTCONBK   0x1C // Next CB Address (CB Word 5)
#define DMA_DEBUG       0x20 // Debug

#endif /* _BCM2835_DMA_H_ */
