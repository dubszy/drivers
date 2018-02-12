#ifndef _BCM2835_CM_H_
#define _BCM2835_CM_H_

#include "../bcm2835_mem.h"

/* Clock Manager (0x7E101000 - 0x7E102FFF) */

#define CM_GP0CTL       0x70
#define CM_GP0DIV       0x74
#define CM_GP1CTL       0x78
#define CM_GP1DIV       0x7C
#define CM_GP2CTL       0x80
#define CM_GP2DIV       0x84

/*
 * CM_UNUSED0 and CM_UNUSED1 are only listed as 'Unused' in the ARM
 * peripherals data sheet.
 *
 * Do not change CM_SRC or CM_MASH while CM_BUSY=1 or at the same time as
 * asserting CM_ENAB.
 *
 * Do not change CM_FLIP, CM_DIVF, or CM_DIVI while CM_BUSY=1 (to avoid
 * output glitches).
 *
 * CM_ENAB requests the clock to start or stop without glitches. The output
 * clock will not stop immediately because the cycle must be allowed to
 * complete to avoid glitches. CM_BUSY will go low when the final cycle is
 * completed.
 *
 * CM_KILL is intended for test/debug only. Using this control may cause
 * a glitch on the clock generator output.
 *
 * CM_FLIP is intended for use in test/debug only. Switching this control
 * will generate an edge on the clock generator output.
 *
 * CM_DIVI has a minimum limit to it's value (determined by the MASH
 * setting).
 */

#define CM_SRC          0x00 // Clock source (R/W)
#define CM_ENAB         0x04 // Enable clock generator (R/W)
#define CM_KILL         0x05 // Kill clock generator (R/W)
#define CM_UNUSED0      0x06 // Unused (R)
#define CM_BUSY         0x07 // Clock generator is running (R)
#define CM_FLIP         0x08 // Invert generator output (R/W)
#define CM_MASH         0x09 // MASH control (R/W)
#define CM_UNUSED1      0x0A // Unused (R)
#define CM_CTL_PASSWD   0x18 // Clock Manager password (W)

/* Values for CM_SRC */
typedef enum {
    CM_SRC_GND  = 0, // Ground (also 8 - 15)
    CM_SRC_OSC  = 1, // Oscillator
    CM_SRC_TD0  = 2, // Test Debug 0
    CM_SRC_TD1  = 3, // Test Debug 1
    CM_SRC_PLLA = 4, // PLLA per
    CM_SRC_PLLC = 5, // PLLC per
    CM_SRC_PLLD = 6, // PLLD per
    CM_SRC_HDMI = 7  // HDMI
} CMClockSource;

/* Values for CM_MASH */
typedef enum {
    CM_MASH_DIV = 0, // Integer division
    CM_MASH_1ST = 1, // 1-stage MASH (equivalent to non-MASH dividers)
    CM_MASH_2ST = 2, // 2-stage MASH
    CM_MASH_3ST = 3  // 3-stage MASH
} CMMashControl;

#define CM_DIVF         0x00 // Fractional part of divisor (R/W)
#define CM_DIVI         0x0C // Integer part of divisor (R/W)
#define CM_DIV_PASSWD   0x18 // Clock Manager password (W)

/*
 * Value for CM_CTL_PASSWD and CM_DIV_PASSWD
 */
#define CM_PASSWORD     0x5A << 24

#endif
