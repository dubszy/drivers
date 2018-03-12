#ifdef _CHIPSET_BCM2835_

#ifndef _BCM2835_EMMC_H_
#define _BCM2835_EMMC_H_

#include "../bcm2835_mem.h"

/* EMMC (SD) (0x7E300000 - 0x7E3000FF) */

#define EMMC_ARG2           0x00 // ACMD23 Argument
#define EMMC_BLKSIZECNT     0x04 // Block Size and Count
#define EMMC_ARG1           0x08 // Argument
#define EMMC_CMDTM          0x0C // Command and Transfer Mode
#define EMMC_RESP0          0x10 // Response Bits 31 : 0
#define EMMC_RESP1          0x14 // Response Bits 63 : 32
#define EMMC_RESP2          0x18 // Response Bits 95 : 64
#define EMMC_RESP3          0x1C // Response Bit 127 : 96
#define EMMC_DATA           0x20 // Data
#define EMMC_STATUS         0x24 // Status
#define EMMC_CONTROL0       0x28 // Host Configuration Bits
#define EMMC_CONTROL1       0x2C // Host Configuration Bits
#define EMMC_INTERRUPT      0x30 // Interrupt Flags
#define EMMC_IRPT_MASK      0x34 // Interrupt Flag Enable
#define EMMC_IRPT_EN        0x38 // Interrupt Generation Enable
#define EMMC_CONTROL2       0x3C // Host Configuration Bits
#define EMMC_FORCE_IRPT     0x50 // Force Interrupt Event
#define EMMC_BOOT_TIMEOUT   0x70 // Timeout in boot mode
#define EMMC_DBG_SEL        0x74 // Debug Bus Configuration
#define EMMC_EXRDFIFO_CFG   0x80 // Extension FIFO Configuration
#define EMMC_EXRDFIFO_EN    0x84 // Extension FIFO Enable
#define EMMC_TUNE_STEP      0x88 // Delay per card clock tuning step
#define EMMC_TUNE_STEPS_STD 0x8C // Card clock tuning steps for SDR
#define EMMC_TUNE_STEPS_DDR 0x90 // Card clock tuning steps for DDR
#define EMMC_SPI_INT_SPT    0xF0 // SPI Interrupt Support
#define EMMC_SLOTISR_VER    0xFC // Slot Interrupt Status and Version

#endif /* _BCM2835_EMMC_H_ */

#endif /* _CHIPSET_BCM2835_ */
