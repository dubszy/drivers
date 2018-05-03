#ifdef _CHIPSET_BCM2835_

#ifndef _BCM2835_TIMER_H_
#define _BCM2835_TIMER_H_

#include "../bcm2835_mem.h"

/* System Timer (0x7E003000 - 0x7E003FFF) */

#define TIMER_CS    0x00
#define TIMER_CLO   0x04
#define TIMER_CHI   0x08
#define TIMER_C0    0x0C
#define TIMER_C1    0x10
#define TIMER_C2    0x14
#define TIMER_C3    0x18

/* TIMER_CS */
#define timer_cs_read   *(timer.addr + TIMER_CS) &= 0xF
#define timer_cs_m0_clr *(timer.addr + TIMER_CS) &= 0x1
#define timer_cs_m1_clr *(timer.addr + TIMER_CS) &= 0x2
#define timer_cs_m2_clr *(timer.addr + TIMER_CS) &= 0x4
#define timer_cs_m3_clr *(timer.addr + TIMER_CS) &= 0x8

/* TIMER_CLO, TIMER_CHI */
#define timer_clo_read  *(timer.addr + TIMER_CLO) &= 0xFFFFFFFF
#define timer_chi_read  *(timer.addr + TIMER_CHI) &= 0xFFFFFFFF

/* TIMER_C0, TIMER_C1, TIMER_C2, TIMER_C3 */
#define timer_c_read(c)   *(timer.addr + c) &= 0xFFFFFFFF

#endif /* _BCM2835_TIMER_H_ */

#endif /* _CHIPSET_BCM2835_ */
