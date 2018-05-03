#ifndef _PERIPHERAL_H_
#define _PERIPHERAL_H_

#include <stddef.h>
#include <stdint.h>

typedef enum {
    PeripheralTypeAXI,
    PeripheralTypeDMA,
    PeripheralTypeDPI,
    PeripheralTypeDSI,
    PeripheralTypeGP_CLOCK,
    PeripheralTypeGPIO,
    PeripheralTypeHDMI,
    PeripheralTypeHVS,
    PeripheralTypeI2C,
    PeripheralTypeINTERRUPT,
    PeripheralTypeINTERRUPT_CONTROLLER,
    PeripheralTypeMAILBOX,
    PeripheralTypeMMC,
    PeripheralTypeOTHER,
    PeripheralTypePCM,
    PeripheralTypePIXEL_VALVE,
    PeripheralTypePWM,
    PeripheralTypeRNG,
    PeripheralTypeSDHOST,
    PeripheralTypeSMI,
    PeripheralTypeSPI,
    PeripheralTypeTIMER,
    PeripheralTypeUART,
    PeripheralTypeUART_MINI,
    PeripheralTypeUSB,
    PeripheralTypeV3D,
    PeripheralTypeVEC,
    PeripheralTypeVCHIQ,
    PeripheralTypeWATCHDOG
} PeripheralType;

struct mem_block sc_getPeripheral(PeripheralType type, uint8_t num);
const struct mem_block sc_getFirstPeripheral(PeripheralType type);
size_t sc_getPeripheralBlockSize();

#endif /* _PERIPHERAL_H_ */
