#ifndef _BCM2835_ARM_INT_H_
#define _BCM2835_ARM_INT_H_

#include "../bcm2835_mem.h"

/* ARM INT (0x7E00B000) */

#define IRQ_BPEN                0x200 // IRQ basic pending
#define IRQ_PEN1                0x204 // IRQ pending 1
#define IRQ_PEN2                0x208 // IRQ pending 2
#define FIQ_CNTL                0x20C // FIQ control
#define IRQ_ENB1                0x210 // Enable IRQs 1
#define IRQ_ENB2                0x214 // Enable IRQs 2
#define IRQ_BENB                0x218 // Enable Basic IRQs
#define IRQ_DIS1                0x21C // Disable IRQs 1
#define IRQ_DIS2                0x220 // Disable IRQs 2
#define IRQ_BDIS                0x224 // Disable Basic IRQs
#define TMR_LOAD                0x400 // Timer Load
#define TMR_VAL                 0x404 // Timer Value
#define TMR_CNTL                0x408 // Timer Control
#define IRQ_CLR_ACK             0x40C // IRQ Clear/Ack
#define IRQ_RAW                 0x410 // RAW IRQ
#define IRQ_MASKED              0x414 // Masked IRQ
#define TMR_RELOAD              0x418 // Reload
#define TMR_PRE_DIV             0x41C // Pre-divider
#define TMR_FRC                 0x420 // Free running counter

#define ARM_TIMER_IRQ_PEND      0x00 // ARM Timer IRQ pending
#define ARM_MAILBOX_IRQ_PEND    0x01 // ARM Mailbox IRQ pending
#define ARM_DOORBELL0_IRQ_PEND  0x02 // ARM Doorbell 0 IRQ pending
#define ARM_DOORBELL1_IRQ_PEND  0x03 // ARM Doorbell 1 IRQ pending
#define GPU0_HALT_IRQ_PEND      0x04 // GPU0 halted IRQ pending (or GPU1 halted if bit 10 of control register 1 is set)
#define GPU1_HALT_IRQ_PEND      0x05 // GPU1 halted IRQ pending
#define ILL_ACC_1_IRQ_PEND      0x06 // Illegal access type 1 IRQ pending
#define ILL_ACC_0_IRQ_PEND      0x07 // Illegal access type 0 IRQ pending
#define BS_PEND_REG_1           0x08 // One or more bits set in pending register 1
#define BS_PEND_REG_2           0x09 // One or more bits set in pending register 2
#define GPU_IRQ_7               0x0A // GPU IRQ 7
#define GPU_IRQ_9               0x0B // GPU IRQ 9
#define GPU_IRQ_10              0x0C // GPU IRQ 10
#define GPU_IRQ_18              0x0D // GPU IRQ 18
#define GPU_IRQ_19              0x0E // GPU IRQ 19
#define GPU_IRQ_53              0x0F // GPU IRQ 53
#define GPU_IRQ_54              0x10 // GPU IRQ 54
#define GPU_IRQ_55              0x11 // GPU IRQ 55
#define GPU_IRQ_56              0x12 // GPU IRQ 56
#define GPU_IRQ_57              0x13 // GPU IRQ 57
#define GPU_IRQ_62              0x14 // GPU IRQ 62
#define ARM_IRQ_UNUSED          0x15 // Unused

#endif /* _BCM2835_ARM_INT_H_ */
