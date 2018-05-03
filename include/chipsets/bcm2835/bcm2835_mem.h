#ifdef _CHIPSET_BCM2835_

#ifndef _BCM2835_MEM_H_
#define _BCM2835_MEM_H_

#include <stdint.h>
#include <stdio.h>

#define PERIPHERAL_BLOCK_SIZE 1024

/*
 * Check for ARMv7 because:
 * 1. Some physical base addresses are different than on ARMv6 or below
 * 2. BCM2835s with ARMv7 or greater have a memory barrier DMB instruction,
 *    ARMv6 models require a co-processor instruction.
 */
#if __ARM_ARCH >= 7
// System RAM runs from 0x00000000 to 0x3AFFFFFF
#define PHY_PERIPHERAL_BASE 0x3F000000 // to 0x3FFFFFFF
#define HAS_DMB
#else
#define PHY_PERIPHERAL_BASE 0x20000000 // to 0x20FFFFFF
#endif

#define PHY_RAM0_BASE       0x00000000 // to 0x0FFFFFFF
#define BUS_RAM1_BASE       0x40000000 // to 0x4FFFFFFF
#define BUS_PERIPHERAL_BASE 0x7E000000 // to 0x7EFFFFFF
#define BUS_RAM2_BASE       0x80000000 // to 0x8FFFFFFF
#define BUS_RAM0_BASE       0xC0000000 // to 0xCFFFFFFF
#define VRT_PERIPHERAL_BASE 0xF2000000 // to 0xF2FFFFFF

/* Kernel: 0x00000000 + Kernel Address */
#define KERNEL_CODE_BASE    0x008000 // to 0x78959F
#define KERNEL_DATA_BASE    0x7FA000 // to 0x93F79B

/* Peripherals: *_PERIPHERAL_BASE + Peripheral Address */
#define TIMER_BASE          0x003000 // to 0x003FFF  System Timer
#define USB0_BASE           0x006000 // to 0x006FFF  USB
#define DMA0_BASE           0x007000 // to 0x0070FF  DMA Controller (Channel 0)
#define DMA1_BASE           0x007100 // to 0x0071FF  DMA Controller (Channel 1)
#define DMA2_BASE           0x007200 // to 0x0072FF  DMA Controller (Channel 2)
#define DMA3_BASE           0x007300 // to 0x0073FF  DMA Controller (Channel 3)
#define DMA4_BASE           0x007400 // to 0x0074FF  DMA Controller (Channel 4)
#define DMA5_BASE           0x007500 // to 0x0075FF  DMA Controller (Channel 5)
#define DMA6_BASE           0x007600 // to 0x0076FF  DMA Controller (Channel 6)
#define DMA7_BASE           0x007700 // to 0x0077FF  DMA Controller (Channel 7)
#define DMA8_BASE           0x007800 // to 0x0078FF  DMA Controller (Channel 8)
#define DMA9_BASE           0x007900 // to 0x0079FF  DMA Controller (Channel 9)
#define DMA10_BASE          0x007A00 // to 0x007AFF  DMA Controller (Channel 10)
#define DMA11_BASE          0x007B00 // to 0x007BFF  DMA Controller (Channel 11)
#define DMA12_BASE          0x007C00 // to 0x007CFF  DMA Controller (Channel 12)
#define DMA13_BASE          0x007D00 // to 0x007DFF  DMA Controller (Channel 13)
#define DMA14_BASE          0x007E00 // to 0x007EFF  DMA Controller (Channel 14)
#define AXI_PERF0_BASE      0x009800 //              Advanced eXtensible Interface Performance
#define ARM_INT_BASE        0x00B000 //              ARM Interrupts
#define INT_CNTRLR_BASE     0x00B200 // to 0x00B3FF  Interrupt Controller
#define VCHIQ_BASE          0x00B840 // to 0x00B84E  VideoCore Host Interface Queue
#define MAILBOX_BASE        0x00B880 // to 0x00B8BF
#define WATCHDOG_BASE       0x100000 // to 0x100027
#define GPCLOCK_BASE        0x101000 // to 0x102FFF  General Purpose Clock
#define PCM0_BASE           0x101098 // to 0x101099  PCM/I2S Audio
#define RNG_BASE            0x104000 // to 0x10400F  Random Number Generator
#define GPIO_BASE           0x200000 // to 0x2000B3  GPIO
#define UART0_BASE          0x201000 // to 0x201FFF  PL011 UART
#define SDHOST_BASE         0x202000 // to 0x2020FF  SD Host
#define PCM_BASE            0x203000 // to 0x20301F  PCM/I2S Audio
#define SPI0_BASE           0x204000 // to 0x204FFF  Serial Peripheral Interface
#define BSC0_BASE           0x205000 // to 0x205FFF  Broadcom Serial Controller (I2C)
#define PXVALVE0_BASE       0x206000 // to 0x2060FF  Pixel Valve
#define PXVALVE1_BASE       0x207000 // to 0x2070FF  Pixel Valve
#define DPI_BASE            0x208000 //
#define DSI0_BASE           0x209000 // to 0x209077  Direct Slave Interface
#define PWM_BASE            0x20C000 // to 0x20C027  Pulse Width Modulator
#define SPI_BSC_SL_BASE     0x214000 //              SPI/BSC Slave
#define AUX_BASE            0x215000 // to 0x215007  Auxiliaries (UART1, SPI1, SPI2)
#define UART1_BASE          0x215040 // to 0x21507F  UART 1 (Mini-UART; Auxiliary)
#define SPI1_BASE           0x215080 // to 0x2150BF  SPI 1 (Auxiliary)
#define SPI2_BASE           0x2150C0 // to 0x2150FF  SPI 2 (Auxiliary)
#define EMMC_BASE           0x300000 // to 0x3000FF  External Mass Media Controller
#define HVS_BASE            0x400000 // to 0x405FFF  Hardware Video Scaler
#define SMI_BASE            0x600000 //              Secondary Memory Interface
#define DSI1_BASE           0x700000 // to 0x70008B  DSI 1
#define BSC1_BASE           0x804000 // to 0x804FFF  BSC 1
#define BSC2_BASE           0x805000 // to 0x805FFF  BSC 2
#define VEC_BASE            0x806000 // to 0x806FFF
#define PXVALVE2_BASE       0x807000 // to 0x8070FF  Pixel Valve
#define HDMI0_BASE          0x808000 // to 0x8080FF  HDMI
#define HDMI1_BASE          0x902000 // to 0x9025FF  HDMI
#define USB1_BASE           0x980000 // to 0x98FFFF  USB
#define V3D_BASE            0xC00000 // to 0xC00FFF  VideoCore 3D
#define DMA15_BASE          0xE05000 //              DMA Controller (Channel 15)
#define AXI_PERF1_BASE      0xE08000 //              AXI Performance

/* Paddings */
#define DMA_PAD             0x100

#endif /* _BCM2835_MEM_H_ */

#endif /* _CHIPSET_BCM2835_ */
