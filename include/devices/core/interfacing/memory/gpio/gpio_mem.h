#ifndef _GPIO_MEM_H_
#define _GPIO_MEM_H_

#include <stdbool.h>

#define _CHIPSET_BCM2835_

#include <devices/core/peripherals/peripheral_gpio.h>
#include <devices/core/interfacing/memory/mapmem.h>

extern bool gpio_mapped;
extern struct mem_block gpio;

int gpio_map();
int gpio_unmap();
bool is_gpio_mapped();
GPIOPinMode gpio_get_pin_mode(unsigned int g);
void gpio_set_pin_mode(unsigned int g, GPIOPinMode f);
void gpio_set_high(unsigned int g);
void gpio_set_low(unsigned int g);
bool gpio_read_level(unsigned int g);
bool gpio_get_event_detect_status(unsigned int g);
bool gpio_is_event_detect_rising(unsigned int g);
bool gpio_is_event_detect_falling(unsigned int g);
bool gpio_is_event_detect_high(unsigned int g);
bool gpio_is_event_detect_low(unsigned int g);
bool gpio_is_event_detect_async_rising(unsigned int g);
bool gpio_is_event_detect_async_falling(unsigned int g);
void gpio_set_event_detect_trigger(unsigned int g, GPIOEDS e);
void gpio_set_pull_enable(unsigned int g, GPIOPUD p);
void gpio_set_pull_clock(unsigned int g);

#endif /* _GPIO_MEM_H_ */
