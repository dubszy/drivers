#ifndef _BCM2835_UART0_H_
#define _BCM2835_UART0_H_

#include "../bcm2835_mem.h"

/* UART0 (0x7E201000 - 0x7E201FFF) */

#define UART_DR     0x00 // Data
#define UART_RSRECR 0x04 // Receive Status/Error Clear
#define UART_FR     0x18 // Flag
#define UART_ILPR   0x20 // IrDA (disabled)
#define UART_IBRD   0x24 // Integer Baud rate divisor
#define UART_FBRD   0x28 // Fractional Baud rate divisor
#define UART_LCRH   0x2C // Line Control
#define UART_CR     0x30 // Control
#define UART_IFLS   0x34 // Interrupt FIFO Level Select
#define UART_IMSC   0x38 // Interrupt Mask Set Clear
#define UART_RIS    0x3C // Raw Interrupt Status
#define UART_MIS    0x40 // Masked Interrupt Status
#define UART_ICR    0x44 // Interrupt Clear
#define UART_DMACR  0x48 // DMA Control
#define UART_ITCR   0x80 // Test Control
#define UART_ITIP   0x84 // Integration test input
#define UART_ITOP   0x88 // Integration test output
#define UART_TDR    0x8C // Test Data

#endif
