#ifdef _CHIPSET_BCM2835_

#ifndef _BCM2835_GPIO_H_
#define _BCM2835_GPIO_H_

#include "../bcm2835_mem.h"

#define GPIO_MIN    0
#define GPIO_MAX    53

/* GPIO (0x7E200000 - 0x7E2000B3) */
/*
 * Registers with the format __RSVD# are listed as 'Reserved' in the ARM
 * peripherals data sheet.
 *
 * __TEST is listed as 'Test' in the ARM peripherals data sheet.
 */

#define GPFSEL0     0x00 // GPIO Function Select 0 (R/W)
#define GPFSEL1     0x04 // GPIO Function Select 1 (R/W)
#define GPFSEL2     0x08 // GPIO Function Select 2 (R/W)
#define GPFSEL3     0x0C // GPIO Function Select 3 (R/W)
#define GPFSEL4     0x10 // GPIO Function Select 4 (R/W)
#define GPFSEL5     0x14 // GPIO Function Select 5 (R/W)
#define __RSVD0     0x18 // Reserved
#define GPSET0      0x1C // GPIO Pin Output Set 0 (W)
#define GPSET1      0x20 // GPIO Pin Output Set 1 (W)
#define __RSVD1     0x24 // Reserved
#define GPCLR0      0x28 // GPIO Pin Output Clear 0 (W)
#define GPCLR1      0x2C // GPIO Pin Output Clear 1 (W)
#define __RSVD2     0x30 // Reserved
#define GPLEV0      0x34 // GPIO Pin Level 0 (R)
#define GPLEV1      0x38 // GPIO Pin Level 1 (R)
#define __RSVD3     0x3C // Reserved
#define GPEDS0      0x40 // GPIO Pin Event Detect Status 0 (R/W)
#define GPEDS1      0x44 // GPIO Pin Event Detect Status 1 (R/W)
#define __RSVD4     0x48 // Reserved
#define GPREN0      0x4C // GPIO Pin Rising Edge Detect Enable 0 (R/W)
#define GPREN1      0x50 // GPIO Pin Rising Edge Detect Enable 1 (R/W)
#define __RSVD5     0x54 // Reserved
#define GPFEN0      0x58 // GPIO Pin Falling Edge Detect Enable 0 (R/W)
#define GPFEN1      0x5C // GPIO Pin Falling Edge Detect Enable 1 (R/W)
#define __RSVD6     0x60 // Reserved
#define GPHEN0      0x64 // GPIO Pin High Detect Enable 0 (R/W)
#define GPHEN1      0x68 // GPIO Pin High Detect Enable 1 (R/W)
#define __RSVD7     0x6C // Reserved
#define GPLEN0      0x70 // GPIO Pin Low Detect Enable 0 (R/W)
#define GPLEN1      0x74 // GPIO Pin Low Detect Enable 1 (R/W)
#define __RSVD8     0x78 // Reserved
#define GPAREN0     0x7C // GPIO Pin Async Rising Edge Detect 0 (R/W)
#define GPAREN1     0x80 // GPIO Pin Async Rising Edge Detect 1 (R/W)
#define __RSVD9     0x84 // Reserved
#define GPAFEN0     0x88 // GPIO Pin Async Falling Edge Detect 0 (R/W)
#define GPAFEN1     0x8C // GPIO Pin Async Falling Edge Detect 1 (R/W)
#define __RSVD10    0x90 // Reserved
#define GPPUD       0x94 // GPIO Pin Pull-Up/Down Enable (R/W)
#define GPPUDCLK0   0x98 // GPIO Pin Pull-Up/Down Enable Clock 0 (R/W)
#define GPPUDCLK1   0x9C // GPIO Pin Pull-Up/Down Enable Clock 1 (R/W)
#define __RSVD11    0xA0 // Reserved
#define __TEST      0xB0 // Test (R/W)

typedef enum {
    GPIOFSELInput  = 0,
    GPIOFSELOutput = 1,
    GPIOFSELAlt5   = 2,
    GPIOFSELAlt4   = 3,
    GPIOFSELAlt0   = 4,
    GPIOFSELAlt1   = 5,
    GPIOFSELAlt2   = 6,
    GPIOFSELAlt3   = 7
} GPIOFSEL;

typedef enum {
    GPIOEDSRisingEdge       = GPREN0,
    GPIOEDSFallingEdge      = GPFEN0,
    GPIOEDSHigh             = GPHEN0,
    GPIOEDSLow              = GPLEN0,
    GPIOEDSAsyncRisingEdge  = GPAREN0,
    GPIOEDSAsyncFallingEdge = GPAFEN0
} GPIOEDS;

typedef enum {
    GPIOPUDOff  = 0,
    GPIOPUDDown = 1,
    GPIOPUDUP   = 2,
    GPIOPUDRsvd = 3
} GPIOPUD;

/* GPFSELx */
#define gpio_fsel_read(g)               *((gpio.addr + GPFSEL0 + ((g) / 10)) >> (((g) % 10) * 3) & 7)
#define gpio_fsel_write(g,f)            *(((gpio.addr + GPFSEL0 + ((g) / 10)) &= ~(7 << (((g) % 10) * 3))) |= (((f) & 7) << (((g) % 10) * 3)))
/* GPSETx */
#define gpio_set(g)                     *(gpio.addr + GPSET0) = (1 << (g))
/* GPCLRx */
#define gpio_clear(g)                   *(gpio.addr + GPCLR0) = (1 << (g))
/* GPLEVx */
#define gpio_read(g)                    *(gpio.addr + GPLEV0) &= (1 << (g))
/* GPEDSx */
#define gpio_event_detect(g)            *(gpio.addr + GPEDS0) &= (1 << (g))
/* GPRENx, GPFENx, GPHENx, GPLENx, GPARENx, GPAFENx */
#define gpio_eds_type_read(g,e)         *(gpio.addr + e) &= (1 << (g))
#define gpio_eds_type_write(g,e)        *(gpio.addr + e) |= (1 << (g))
/* GPPUD, GPPUDCLKx */
#define gpio_pull_up_down_read(g, c)    *(gpio.addr + GPPUD) &= (3 << ((g) * 2))
#define gpio_pull_up_down_write(g, c)   *(gpio.addr + GPPUD) = ((c) << ((g) * 2))
#define gpio_pull_up_down_clk_read(g)   *(gpio.addr + GPPUDCLK0) &= (1 << (g))
#define gpio_pull_up_down_clk_write(g)  *(gpio.addr + GPPUDCLK0) |= (1 << (g))

#define NONE            "NONE"

/** JTAG **/
#define ARM_TRST        "ARM_TRST"          // ARM JTAG Reset
#define ARM_TMS         "ARM_TMS"           // ARM JTAG Mode Select
#define ARM_TCK         "ARM_TCK"           // ARM JTAG Clock
#define ARM_RTCK        "ARM_RTCK"          // ARM JTAG Return Clock
#define ARM_TDI         "ARM_TDI"           // ARM JTAG Data In
#define ARM_TDO         "ARM_TDO"           // ARM JTAG Data Out

#define SD0_CLK         "SD0_CLK"
#define SD0_CMD         "SD0_CMD"
#define SD0_DAT0        "SD0_DAT0"
#define SD0_DAT1        "SD0_DAT1"
#define SD0_DAT2        "SD0_DAT2"
#define SD0_DAT3        "SD0_DAT3"
#define SD1_CLK         "SD1_CLK"
#define SD1_CMD         "SD1_CMD"
#define SD1_DAT0        "SD1_DAT0"
#define SD1_DAT1        "SD1_DAT1"
#define SD1_DAT2        "SD1_DAT2"
#define SD1_DAT3        "SD1_DAT3"
#define SD1_DAT4        "SD1_DAT4"
#define SD1_DAT5        "SD1_DAT5"
#define SD1_DAT6        "SD1_DAT6"
#define SD1_DAT7        "SD1_DAT7"

/** Secondary Memory Interface **/
#define SA0             "SA0"               // Secondary Memory Address Bus 0
#define SA1             "SA1"               // Secondary Memory Address Bus 1
#define SA2             "SA2"               // Secondary Memory Address Bus 2
#define SA3             "SA3"               // Secondary Memory Address Bus 3
#define SA4             "SA4"               // Secondary Memory Address Bus 4
#define SA5             "SA5"               // Secondary Memory Address Bus 5
#define SD0             "SD0"               // Secondary Memory Data Bus 0
#define SD1             "SD1"               // Secondary Memory Data Bus 1
#define SD2             "SD2"               // Secondary Memory Data Bus 2
#define SD3             "SD3"               // Secondary Memory Data Bus 3
#define SD4             "SD4"               // Secondary Memory Data Bus 4
#define SD5             "SD5"               // Secondary Memory Data Bus 5
#define SD6             "SD6"               // Secondary Memory Data Bus 6
#define SD7             "SD7"               // Secondary Memory Data Bus 7
#define SD8             "SD8"               // Secondary Memory Data Bus 8
#define SD9             "SD9"               // Secondary Memory Data Bus 9
#define SD10            "SD10"              // Secondary Memory Data Bus 10
#define SD11            "SD11"              // Secondary Memory Data Bus 11
#define SD12            "SD12"              // Secondary Memory Data Bus 12
#define SD13            "SD13"              // Secondary Memory Data Bus 13
#define SD14            "SD14"              // Secondary Memory Data Bus 14
#define SD15            "SD15"              // Secondary Memory Data Bus 15
#define SD16            "SD16"              // Secondary Memory Data Bus 16
#define SD17            "SD17"              // Secondary Memory Data Bus 17
#define SOE_N__SE       "SOE_N__SE"         // Secondary Memory Controls
#define SWE_N__SRW_N    "SWE_N__SRW_N"      // Secondary Memory Controls

/** GPCLK **/
#define GPCLK0          "GPCLK0"            // GP Clock 0
#define GPCLK1          "GPCLK1"            // GP Clock 1
#define GPCLK2          "GPCLK2"            // GP Clock 2

/** PWM **/
#define PWM0            "PWM0"              // Pulse Width Modulator 0
#define PWM1            "PWM1"              // Pulse Width Modulator 1

/** UART **/
#define TXD0            "TXD0"              // UART 0 Transmit Data
#define RXD0            "RXD0"              // UART 0 Receive Data
#define CTS0            "CTS0"              // UART 0 Clear to Send
#define RTS0            "RTS0"              // UART 0 Request to Send
#define TXD1            "TXD1"              // UART 1 Transmit Data
#define RXD1            "RXD1"              // UART 1 Receive Data
#define CTS1            "CTS1"              // UART 1 Clear to Send
#define RTS1            "RTS1"              // UART 1 Request to Send

/** BSC/I2C **/
#define SDA0            "SDA0"              // BSC Master 0 Data Line
#define SCL0            "SCL0"              // BSC Master 0 Clock Line
#define SDA1            "SDA1"              // BSC Master 1 Data Line
#define SCL1            "SCL1"              // BSC Master 1 Clock Line

/** SPI **/
#define SPI0_CE0_N      "SPI0_CE0_N"        // SPI0 Chip Select 0
#define SPI0_CE1_N      "SPI0_CE1_N"        // SPI0 Chip Select 1
#define SPI0_MISO       "SPI0_MISO"         // SPI0 MISO
#define SPI0_MOSI       "SPI0_MOSI"         // SPI0 MOSI
#define SPI0_SCLK       "SPI0_SCLK"         // SPI0 Serial Clock
#define SPI1_CE0_N      "SPI1_CE0_N"        // SPI1 Chip Select 0
#define SPI1_CE1_N      "SPI1_CE1_N"        // SPI1 Chip Select 1
#define SPI1_CE2_N      "SPI1_CE2_N"        // SPI1 Chip Select 2
#define SPI1_MISO       "SPI1_MISO"         // SPI1 MISO
#define SPI1_MOSI       "SPI1_MOSI"         // SPI1 MOSI
#define SPI1_SCLK       "SPI1_SCLK"         // SPI1 Serial Clock
#define SPI2_CE0_N      "SPI2_CE0_N"        // SPI2 Chip Select 0
#define SPI2_CE1_N      "SPI2_CE1_N"        // SPI2 Chip Select 1
#define SPI2_CE2_N      "SPI2_CE2_N"        // SPI2 Chip Select 2
#define SPI2_MISO       "SPI2_MISO"         // SPI2 MISO
#define SPI2_MOSI       "SPI2_MOSI"         // SPI2 MOSI
#define SPI2_SCLK       "SPI2_SCLK"         // SPI2 Serial Clock
#define BSCSL_SDA_MOSI  "BSCSL_SDA_MOSI"    // BSC Slave Data, SPI Slave MOSI
#define BSCSL_SCL_SCLK  "BSCSL_SCL_SCLK"    // BSC Slave Clock, SPI Slave Clock
#define BSCSL_MISO      "BSCSL_MISO"        // BSC (not used), SPI MISO
#define BSCSL_CE_N      "BSCSL_CE_N"        // BSC (not used), SPI Chip Select [n]

/** PCM **/
#define PCM_CLK         "PCM_CLK"           // PCM Clock
#define PCM_FS          "PCM_FS"            // PCM Frame Sync
#define PCM_DIN         "PCM_DIN"           // PCM Data In
#define PCM_DOUT        "PCM_DOUT"          // PCM Data Out

/** Parallel Display Interface **/
#define PCLK            "PCLK"
#define DE              "DE"
#define LCD_VSYNC       "LCD_VSYNC"
#define LCD_HSYNC       "LCD_HSYNC"
#define DPI_D0          "DPI_D0"
#define DPI_D1          "DPI_D1"
#define DPI_D2          "DPI_D2"
#define DPI_D3          "DPI_D3"
#define DPI_D4          "DPI_D4"
#define DPI_D5          "DPI_D5"
#define DPI_D6          "DPI_D6"
#define DPI_D7          "DPI_D7"
#define DPI_D8          "DPI_D8"
#define DPI_D9          "DPI_D9"
#define DPI_D10         "DPI_D10"
#define DPI_D11         "DPI_D11"
#define DPI_D12         "DPI_D12"
#define DPI_D13         "DPI_D13"
#define DPI_D14         "DPI_D14"
#define DPI_D15         "DPI_D15"
#define DPI_D16         "DPI_D16"
#define DPI_D17         "DPI_D17"
#define DPI_D18         "DPI_D18"
#define DPI_D19         "DPI_D19"
#define DPI_D20         "DPI_D20"
#define DPI_D21         "DPI_D21"
#define DPI_D22         "DPI_D22"
#define DPI_D23         "DPI_D23"

#define RING_OCLK       "RING_OCLK"

#define TE0             "TE0"
#define TE1             "TE1"
#define TE2             "TE2"

#define FL0             "FL0"
#define FL1             "FL1"

#define AVEOUT_VCLK     "AVEOUT_VCLK"
#define AVEOUT_DSYNC    "AVEOUT_DSYNC"
#define AVEOUT_VSYNC    "AVEOUT_VSYNC"
#define AVEOUT_HSYNC    "AVEOUT_HSYNC"
#define AVEOUT_VID0     "AVEOUT_VID0"
#define AVEOUT_VID1     "AVEOUT_VID1"
#define AVEOUT_VID2     "AVEOUT_VID2"
#define AVEOUT_VID3     "AVEOUT_VID3"
#define AVEOUT_VID4     "AVEOUT_VID4"
#define AVEOUT_VID5     "AVEOUT_VID5"
#define AVEOUT_VID6     "AVEOUT_VID6"
#define AVEOUT_VID7     "AVEOUT_VID7"
#define AVEOUT_VID8     "AVEOUT_VID8"
#define AVEOUT_VID9     "AVEOUT_VID9"
#define AVEOUT_VID10    "AVEOUT_VID10"
#define AVEOUT_VID11    "AVEOUT_VID11"
#define AVEIN_VCLK      "AVEIN_VCLK"
#define AVEIN_DSYNC     "AVEIN_DSYNC"
#define AVEIN_VSYNC     "AVEIN_VSYNC"
#define AVEIN_HSYNC     "AVEIN_HSYNC"
#define AVEIN_VID0      "AVEIN_VID0"
#define AVEIN_VID1      "AVEIN_VID1"
#define AVEIN_VID2      "AVEIN_VID2"
#define AVEIN_VID3      "AVEIN_VID3"
#define AVEIN_VID4      "AVEIN_VID4"
#define AVEIN_VID5      "AVEIN_VID5"
#define AVEIN_VID6      "AVEIN_VID6"
#define AVEIN_VID7      "AVEIN_VID7"
#define AVEIN_VID8      "AVEIN_VID8"
#define AVEIN_VID9      "AVEIN_VID9"
#define AVEIN_VID10     "AVEIN_VID10"
#define AVEIN_VID11     "AVEIN_VID11"


struct bcm2835_alt_func {
    const char *alt0;
    const char *alt1;
    const char *alt2;
    const char *alt3;
    const char *alt4;
    const char *alt5;
};

struct bcm2835_alt_func gpio_alt_func_map[54] = {
    {SDA0,          SA5,            PCLK,       AVEOUT_VCLK,    AVEIN_VCLK,     NONE},       // 0
    {SCL0,          SA4,            DE,         AVEOUT_DSYNC,   AVEIN_DSYNC,    NONE},       // 1
    {SDA1,          SA3,            LCD_VSYNC,  AVEOUT_VSYNC,   AVEIN_VSYNC,    NONE},       // 2
    {SCL1,          SA2,            LCD_HSYNC,  AVEOUT_HSYNC,   AVEIN_HSYNC,    NONE},       // 3
    {GPCLK0,        SA1,            DPI_D0,     AVEOUT_VID0,    AVEIN_VID0,     ARM_TDI},    // 4
    {GPCLK1,        SA0,            DPI_D1,     AVEOUT_VID1,    AVEIN_VID1,     ARM_TDO},    // 5
    {GPCLK2,        SOE_N__SE,      DPI_D2,     AVEOUT_VID2,    AVEIN_VID2,     ARM_RTCK},   // 6
    {SPI0_CE1_N,    SWE_N__SRW_N,   DPI_D3,     AVEOUT_VID3,    AVEIN_VID3,     NONE},       // 7
    {SPI0_CE0_N,    SD0,            DPI_D4,     AVEOUT_VID4,    AVEIN_VID4,     NONE},       // 8
    {SPI0_MISO,     SD1,            DPI_D5,     AVEOUT_VID5,    AVEIN_VID5,     NONE},       // 9
    {SPI0_MOSI,     SD2,            DPI_D6,     AVEOUT_VID6,    AVEIN_VID6,     NONE},       // 10
    {SPI0_SCLK,     SD3,            DPI_D7,     AVEOUT_VID7,    AVEIN_VID7,     NONE},       // 11
    {PWM0,          SD4,            DPI_D8,     AVEOUT_VID8,    AVEIN_VID8,     ARM_TMS},    // 12
    {PWM1,          SD5,            DPI_D9,     AVEOUT_VID9,    AVEIN_VID9,     ARM_TCK},    // 13
    {TXD0,          SD6,            DPI_D10,    AVEOUT_VID10,   AVEIN_VID10,    TXD1},       // 14
    {RXD0,          SD7,            DPI_D11,    AVEOUT_VID11,   AVEIN_VID11,    RXD1},       // 15
    {FL0,           SD8,            DPI_D12,    CTS0,           SPI1_CE2_N,     CTS1},       // 16
    {FL1,           SD9,            DPI_D13,    RTS0,           SPI1_CE1_N,     RTS1},       // 17
    {PCM_CLK,       SD10,           DPI_D14,    BSCSL_SDA_MOSI, SPI1_CE0_N,     PWM0},       // 18
    {PCM_FS,        SD11,           DPI_D15,    BSCSL_SCL_SCLK, SPI1_MISO,      PWM1},       // 19
    {PCM_DIN,       SD12,           DPI_D16,    BSCSL_MISO,     SPI1_MOSI,      GPCLK0},     // 20
    {PCM_DOUT,      SD13,           DPI_D17,    BSCSL_CE_N,     SPI1_SCLK,      GPCLK1},     // 21
    {SD0_CLK,       SD14,           DPI_D18,    SD1_CLK,        ARM_TRST,       NONE},       // 22
    {SD0_CMD,       SD15,           DPI_D19,    SD1_CMD,        ARM_RTCK,       NONE},       // 23
    {SD0_DAT0,      SD16,           DPI_D20,    SD1_DAT0,       ARM_TDO,        NONE},       // 24
    {SD0_DAT1,      SD17,           DPI_D21,    SD1_DAT1,       ARM_TCK,        NONE},       // 25
    {SD0_DAT2,      TE0,            DPI_D22,    SD1_DAT2,       ARM_TDI,        NONE},       // 26
    {SD0_DAT3,      TE1,            DPI_D23,    SD1_DAT3,       ARM_TMS,        NONE},       // 27
    {SDA0,          SA5,            PCM_CLK,    FL0,            NONE,           NONE},       // 28
    {SCL0,          SA4,            PCM_FS,     FL1,            NONE,           NONE},       // 29
    {TE0,           SA3,            PCM_DIN,    CTS0,           NONE,           CTS1},       // 30
    {FL0,           SA2,            PCM_DOUT,   RTS0,           NONE,           RTS1},       // 31
    {GPCLK0,        SA1,            RING_OCLK,  TXD0,           NONE,           TXD1},       // 32
    {FL1,           SA0,            TE1,        RXD0,           NONE,           RXD1},       // 33
    {GPCLK0,        SOE_N__SE,      TE2,        SD1_CLK,        NONE,           NONE},       // 34
    {SPI0_CE1_N,    SWE_N__SRW_N,   NONE,       SD1_CMD,        NONE,           NONE},       // 35
    {SPI0_CE0_N,    SD0,            TXD0,       SD1_DAT0,       NONE,           NONE},       // 36
    {SPI0_MISO,     SD1,            RXD0,       SD1_DAT1,       NONE,           NONE},       // 37
    {SPI0_MOSI,     SD2,            RTS0,       SD1_DAT2,       NONE,           NONE},       // 38
    {SPI0_SCLK,     SD3,            CTS0,       SD1_DAT3,       NONE,           NONE},       // 39
    {PWM0,          SD4,            NONE,       SD1_DAT4,       SPI2_MISO,      TXD1},       // 40
    {PWM1,          SD5,            TE0,        SD1_DAT5,       SPI2_MOSI,      RXD1},       // 41
    {GPCLK1,        SD6,            TE1,        SD1_DAT6,       SPI2_SCLK,      RTS1},       // 42
    {GPCLK2,        SD7,            TE2,        SD1_DAT7,       SPI2_CE0_N,     CTS1},       // 43
    {GPCLK1,        SDA0,           SDA1,       TE0,            SPI2_CE1_N,     NONE},       // 44
    {PWM1,          SCL0,           SCL1,       TE1,            SPI2_CE2_N,     NONE},       // 45
    {SDA0,          SDA1,           SPI0_CE0_N, NONE,           NONE,           SPI2_CE1_N}, // 46
    {SCL0,          SCL1,           SPI0_MISO,  NONE,           NONE,           SPI2_CE0_N}, // 47
    {SD0_CLK,       FL0,            SPI0_MOSI,  SD1_CLK,        ARM_TRST,       SPI2_SCLK},  // 48
    {SD0_CMD,       GPCLK0,         SPI0_SCLK,  SD1_CMD,        ARM_RTCK,       SPI2_MOSI},  // 49
    {SD0_DAT0,      GPCLK1,         PCM_CLK,    SD1_DAT0,       ARM_TDO,        NONE},       // 50
    {SD0_DAT1,      GPCLK2,         PCM_FS,     SD1_DAT1,       ARM_TCK,        NONE},       // 51
    {SD0_DAT2,      PWM0,           PCM_DIN,    SD1_DAT2,       ARM_TDI,        NONE},       // 52
    {SD0_DAT3,      PWM1,           PCM_DOUT,   SD1_DAT3,       ARM_TMS,        NONE}        // 53
};

#endif /* _BCM2835_GPIO_H_ */

#endif /* _CHIPSET_BCM2835_ */
