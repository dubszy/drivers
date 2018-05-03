#ifndef _SYSFS_GPIO_H_
#define _SYSFS_GPIO_H_

#include <devices/core/peripherals/peripheral_gpio.h>

int gpio_export(int gpio_num, const char *export_path);
int gpio_unexport(int gpio_num, const char *unexport_path);
GPIODirection gpio_get_dir(int gpio_num, const char *gpio_dir_path_fmt);
int gpio_set_dir(int gpio_num, GPIODirection dir, const char *gpio_dir_path_fmt);
GPIOValue gpio_get_val(int gpio_num, const char *gpio_val_path_fmt);
int gpio_set_val(int gpio_num, GPIOValue val, const char *gpio_val_path_fmt);
GPIOEdgeDetect gpio_get_edge_detect(int gpio_num, const char *gpio_edge_path_fmt);
int gpio_set_edge_detect(int gpio_num, GPIOEdgeDetect edge_detect, const char *gpio_edge_path_fmt);

#endif /* _SYSFS_GPIO_H_ */
