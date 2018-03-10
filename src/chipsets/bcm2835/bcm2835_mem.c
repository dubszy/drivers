#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>

#include "bcm2835_mem.h"

struct mem_block timer          = {PHY_PERIPHERAL_BASE + TIMER_BASE};
struct mem_block usb0           = {PHY_PERIPHERAL_BASE + USB0_BASE};
struct mem_block dma            = {PHY_PERIPHERAL_BASE + DMA_BASE};
struct mem_block axi_perf0      = {PHY_PERIPHERAL_BASE + AXI_PERF0_BASE};
struct mem_block arm_int        = {PHY_PERIPHERAL_BASE + ARM_INT_BASE};
struct mem_block int_controller = {PHY_PERIPHERAL_BASE + INT_CNTRLR_BASE};
struct mem_block mailbox        = {PHY_PERIPHERAL_BASE + MAILBOX_BASE};
struct mem_block vchiq          = {PHY_PERIPHERAL_BASE + VCHIQ_BASE};
struct mem_block watchdog       = {PHY_PERIPHERAL_BASE + WATCHDOG_BASE};
struct mem_block gp_clock       = {PHY_PERIPHERAL_BASE + GPCLOCK_BASE};
struct mem_block rng            = {PHY_PERIPHERAL_BASE + RNG_BASE};
struct mem_block gpio           = {PHY_PERIPHERAL_BASE + GPIO_BASE};
struct mem_block uart0          = {PHY_PERIPHERAL_BASE + UART0_BASE};
struct mem_block sdhost         = {PHY_PERIPHERAL_BASE + SDHOST_BASE};
struct mem_block pcm            = {PHY_PERIPHERAL_BASE + PCM_BASE};
struct mem_block spi0           = {PHY_PERIPHERAL_BASE + SPI0_BASE};
struct mem_block bsc0           = {PHY_PERIPHERAL_BASE + BSC0_BASE};
struct mem_block px_valve0      = {PHY_PERIPHERAL_BASE + PXVALVE0_BASE};
struct mem_block px_valve1      = {PHY_PERIPHERAL_BASE + PXVALVE1_BASE};
struct mem_block dpi            = {PHY_PERIPHERAL_BASE + DPI_BASE};
struct mem_block dsi            = {PHY_PERIPHERAL_BASE + DSI0_BASE};
struct mem_block pwm            = {PHY_PERIPHERAL_BASE + PWM_BASE};
struct mem_block bsc_spi        = {PHY_PERIPHERAL_BASE + SPI_BSC_SL_BASE};
struct mem_block aux            = {PHY_PERIPHERAL_BASE + AUX_BASE};
struct mem_block uart1          = {PHY_PERIPHERAL_BASE + UART1_BASE};
struct mem_block spi1           = {PHY_PERIPHERAL_BASE + SPI1_BASE};
struct mem_block spi2           = {PHY_PERIPHERAL_BASE + SPI2_BASE};
struct mem_block emmc           = {PHY_PERIPHERAL_BASE + EMMC_BASE};
struct mem_block hvs            = {PHY_PERIPHERAL_BASE + HVS_BASE};
struct mem_block smi            = {PHY_PERIPHERAL_BASE + SMI_BASE};
struct mem_block dsi1           = {PHY_PERIPHERAL_BASE + DSI1_BASE};
struct mem_block bsc1           = {PHY_PERIPHERAL_BASE + BSC1_BASE};
struct mem_block bsc2           = {PHY_PERIPHERAL_BASE + BSC2_BASE};
struct mem_block vec            = {PHY_PERIPHERAL_BASE + VEC_BASE};
struct mem_block px_valve2      = {PHY_PERIPHERAL_BASE + PXVALVE2_BASE};
struct mem_block hdmi0          = {PHY_PERIPHERAL_BASE + HDMI0_BASE};
struct mem_block hdmi1          = {PHY_PERIPHERAL_BASE + HDMI1_BASE};
struct mem_block usb1           = {PHY_PERIPHERAL_BASE + USB1_BASE};
struct mem_block v3d            = {PHY_PERIPHERAL_BASE + V3D_BASE};
struct mem_block dma_15         = {PHY_PERIPHERAL_BASE + DMA_15_BASE};
struct mem_block axi_perf1      = {PHY_PERIPHERAL_BASE + AXI_PERF1_BASE};

uint8_t a;

int mapmem(struct mem_block *m) {
    if ((m->mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        printf("Failed to open /dev/mem, try checking permissions\n");
        return -1;
    }

    m->map = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, m->mem_fd, m->addr_p);

    if (m->map == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    m->addr = (volatile unsigned int *)m->map;

    return 0;
}

void unmapmem(struct mem_block *m) {
    munmap(m->map, BLOCK_SIZE);
    close(m->mem_fd);
}
