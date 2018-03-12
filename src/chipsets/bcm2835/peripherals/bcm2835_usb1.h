#ifdef _CHIPSET_BCM2835_

#ifndef _BCM2835_USB1_H_
#define _BCM2835_USB1_H_

#include "../bcm2835_mem.h"

/* USB1 (0x7E980000 - 0x7E98FFFF) */

#define USB_GAHBCFG     0x08 // USB AHB configuration
#define USB_MDIO_CNTL   0x80 // MDIO interface control
#define USB_MDIO_GEN    0x84 // Data for MDIO interface
#define USB_VBUS_DRV    0x88 // VBUS and other miscellaneous controls

#endif /* _BCM2835_USB1_H_ */

#endif /* _CHIPSET_BCM2835_ */
