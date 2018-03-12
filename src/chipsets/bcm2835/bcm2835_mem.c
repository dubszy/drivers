#ifdef _CHIPSET_BCM2835_

#include <chipsets/peripherals/peripheral.h>

#include "bcm2835_mem.h"

struct mem_block getPeripheral(PeripheralType type, uint8_t num) {
    struct mem_block memblk;
    memblk.addr_p = PHY_PERIPHERAL_BASE;
    switch (type) {
        case PeripheralTypeAXI:
            memblk.addr_p += (!num) ? AXI_PERF0_BASE : AXI_PERF1_BASE;
            break;
        case PeripheralTypeDMA:
            if (num > 15) {
                printf("There are only 16 DMA channels on this system\n");
                return NULL;
            }
            memblk.addr_p += (num < 15) ? (DMA0_BASE + (num * DMA_PAD)) : DMA15_BASE;
            break;
        case PeripheralTypeDPI:
            memblk.addr_p += DPI_BASE;
            break;
        case PeripheralTypeDSI:
            memblk.addr_p += (!num) ? DSI0_BASE : DSI1_BASE;
            break;
        case PeripheralTypeGP_CLOCK:
            memblk.addr_p += GPCLOCK_BASE;
            break;
        case PeripheralTypeGPIO:
            memblk.addr_p += GPIO_BASE;
            break;
        case PeripheralTypeHDMI:
            memblk.addr_p += (!num) ? HDMI0_BASE : HDMI1_BASE;
            break;
        case PeripheralTypeHVS:
            memblk.addr_p += HVS_BASE;
            break;
        case PeripheralTypeI2C:
            if (!num) {
                memblk.addr_p += BSC0_BASE;
            } else if (num == 1) {
                memblk.addr_p += BSC1_BASE;
            } else {
                memblk.addr_p += BSC2_BASE;
            }
            break;
        case PeripheralTypeINTERRUPT:
            memblk.addr_p += ARM_INT_BASE;
            break;
        case PeripheralTypeINTERRUPT_CONTROLLER:
            memblk.addr_p += INT_CNTRLR_BASE;
            break;
        case PeripheralTypeMAILBOX:
            memblk.addr_p += MAILBOX_BASE;
            break;
        case PeripheralTypeMMC:
            memblk.addr_p += EMMC_BASE;
            break;
        case PeripheralTypePCM:
            memblk.addr_p += PCM_BASE;
            break;
        case PeripheralTypePIXEL_VALVE:
            if (!num) {
                memblk.addr_p += PXVALVE0_BASE;
            } else if (num == 1) {
                memblk.addr_p += PXVALVE1_BASE;
            } else {
                memblk.addr_p += PXVALVE2_BASE;
            }
            break;
        case PeripheralTypePWM:
            memblk.addr_p += PWM_BASE;
            break;
        case PeripheralTypeRNG:
            memblk.addr_p += RNG_BASE;
            break;
        case PeripheralTypeSDHOST:
            memblk.addr_p += SDHOST_BASE;
            break;
        case PeripheralTypeSMI:
            memblk.addr_p += SMI_BASE;
            break;
        case PeripheralTypeSPI:
            if (!num) {
                memblk.addr_p += SPI0_BASE;
            } else if (num == 1) {
                memblk.addr_p += SPI1_BASE;
            } else {
                memblk.addr_p += SPI2_BASE;
            }
            break;
        case PeripheralTypeTIMER:
            memblk.addr_p += TIMER_BASE;
            break;
        case PeripheralTypeUART:
            memblk.addr_p += UART0_BASE;
            break;
        case PeripheralTypeUART_MINI:
            memblk.addr_p += UART1_BASE;
            break;
        case PeripheralTypeUSB:
            memblk.addr_p += (!num) ? USB0_BASE : USB1_BASE;
            break;
        case PeripheralTypeV3D:
            memblk.addr_p += V3D_BASE;
            break;
        case PeripheralTypeVEC:
            memblk.addr_p += VEC_BASE;
            break;
        case PeripheralTypeVCHIQ:
            memblk.addr_p += VCHIQ_BASE;
            break;
        case PeripheralTypeWATCHDOG:
            memblk.addr_p += WATCHDOG_BASE;
            break;
        default:
            printf("Peripheral '%s #%d' is not available on this system\n", type, num);
            memblk = NULL;
            break;
    }
    return memblk;
}

struct mem_block getPeripheral(PeripheralType type) {
    return getPeripheral(type, 0);
}

#endif /* _CHIPSET_BCM2835_ */
