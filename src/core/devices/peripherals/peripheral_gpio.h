#ifndef _PERIPHERAL_GPIO_H_
#define _PERIPHERAL_GPIO_H_

#include "peripheral.h"

//*** Chipset-Specific Includes ***//

#ifdef _CHIPSET_BCM2835_
#include <chipsets/bcm2835/peripherals/bcm2835_gpio.h>
#endif /* _CHIPSET_BCM2835_ */


//*** GPIO Types ***//

typedef enum {
    GPIOPinModeUnknown,
    GPIOPinModeRead,
    GPIOPinModeWrite,
    GPIOPinModeAlt0,
    GPIOPinModeAlt1,
    GPIOPinModeAlt2,
    GPIOPinModeAlt3,
    GPIOPinModeAlt4,
    GPIOPinModeAlt5
} GPIOPinMode;

typedef enum {
    GPIODirectionUnknown    = -1,
    GPIODirectionIn         = 0,
    GPIODirectionOut        = 1
} GPIODirection;

typedef enum {
    GPIOValueUnknown    = -1,
    GPIOValueLow        = 0,
    GPIOValueHigh       = 1
} GPIOValue;

typedef enum {
    GPIOEdgeDetectNone         = 0x00,
    GPIOEdgeDetectRising       = 0x01,
    GPIOEdgeDetectFalling      = 0x02,
    GPIOEdgeDetectHigh         = 0x04,
    GPIOEdgeDetectLow          = 0x08,
    GPIOEdgeDetectAsyncRising  = 0x10,
    GPIOEdgeDetectAsyncFalling = 0x20,
    GPIOEdgeDetectUnknown      = 0xF0
} GPIOEdgeDetect;

#endif /* _PERIPHERAL_GPIO_H_ */
