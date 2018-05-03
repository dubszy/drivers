#include <devices/core/interfacing/memory/gpio/gpio_mem.h>

bool gpio_mapped = false;
/* GPIO_BASE must be defined by a chipset-specific header in the following location:
 * include/chipsets/<chipset_name>/<chipset_name>_mem.h
 * For example: include/chipsets/bcm2835/bcm2835_mem.h
 *
 * Chipset-specific includes are defined in <include/devices/core/peripherals/peripheral_gpio.h>
 */
struct mem_block gpio = {GPIO_BASE};

int gpio_map() {
    if (gpio_mapped) {
        return 0;
    }
    int mapmem_res = mapmem(&gpio, sc_getPeripheralBlockSize());
    gpio_mapped = (mapmem_res == 0) ? true : false;
    return mapmem_res;
}

int gpio_unmap() {
    if (!gpio_mapped) {
        printf("GPIO memory addresses are not currently mapped\n");
        return 0;
    }
    int unmapmem_res = unmapmem(&gpio, sc_getPeripheralBlockSize());
    gpio_mapped = (unmapmem_res == 0) ? false : true;
    return unmapmem_res;
}

bool is_gpio_mapped() {
    return gpio_mapped;
}

//GPIOFSEL gpio_get_fsel(unsigned int g) {
//    return gpio_fsel_read(g);
//}

void gpio_set_fsel_alt(unsigned int g, GPIOFSEL f) {
    gpio_fsel_alt(g, f);
}

//void gpio_set_fsel(unsigned int g, GPIOFSEL f) {
//    gpio_fsel_write(g, f);
//}

void gpio_set_high(unsigned int g) {
    gpio_set(g);
}

void gpio_set_low(unsigned int g) {
    gpio_clear(g);
}

bool gpio_read_level(unsigned int g) {
    return (gpio_read(g)) ? true : false;
}

bool gpio_get_event_detect_status(unsigned int g) {
    return (gpio_event_detect(g)) ? true : false;
}

bool gpio_is_event_detect_rising(unsigned int g) {
    return (gpio_eds_type_read(g, GPIOEDSRisingEdge)) ? true : false;
}

bool gpio_is_event_detect_falling(unsigned int g) {
    return (gpio_eds_type_read(g, GPIOEDSFallingEdge)) ? true : false;
}

bool gpio_is_event_detect_high(unsigned int g) {
    return (gpio_eds_type_read(g, GPIOEDSHigh)) ? true : false;
}

bool gpio_is_event_detect_low(unsigned int g) {
    return (gpio_eds_type_read(g, GPIOEDSLow)) ? true : false;
}

bool gpio_is_event_detect_async_rising(unsigned int g) {
    return (gpio_eds_type_read(g, GPIOEDSAsyncRisingEdge)) ? true : false;
}

bool gpio_is_event_detect_async_falling(unsigned int g) {
    return (gpio_eds_type_read(g, GPIOEDSAsyncFallingEdge)) ? true : false;
}

void gpio_set_event_detect_trigger(unsigned int g, GPIOEDS e) {
    gpio_eds_type_write(g, e);
}

void gpio_set_pull_enable(unsigned int g, GPIOPUD p) {
    gpio_pull_up_down_write(g, p);
}

void gpio_set_pull_clock(unsigned int g) {
    gpio_pull_up_down_clk_write(g);
}
