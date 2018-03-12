#ifndef _SYSFS_GPIO_H_
#define _SYSFS_GPIO_H_

const char *_export_path        = "/sys/class/gpio/export";
const char *_unexport_path      = "/sys/class/gpio/unexport";
const char *_gpio_dir_path_fmt  = "/sys/class/gpio%d/direction";
const char *_gpio_val_path_fmt  = "/sys/class/gpio%d/value";
const char *_gpio_edge_path_fmt = "/sys/class/gpio%d/edge";

typedef enum {
    GPIO_DIR_UNKNOWN    = -1,
    GPIO_DIR_IN         = 0,
    GPIO_DIR_OUT        = 1
} GPIODirection;

typedef enum {
    GPIO_VAL_UNKNOWN    = -1,
    GPIO_VAL_LOW        = 0,
    GPIO_VAL_HIGH       = 1
} GPIOValue;

typedef enum {
    GPIO_EDGE_UNKNOWN   = -1,
    GPIO_EDGE_NONE      = 0,
    GPIO_EDGE_RISING    = 1,
    GPIO_EDGE_FALLING   = 2,
    GPIO_EDGE_BOTH      = 3
} GPIOEdgeDetect;

int gpio_export(int gpio_num);
int gpio_unexport(int gpio_num);
GPIODirection gpio_get_dir(int gpio_num);
int gpio_set_dir(int gpio_num, GPIODirection dir);
GPIOValue gpio_get_val(int gpio_num);
int gpio_set_val(int gpio_num, GPIOValue val);
GPIOEdgeDetect gpio_get_edge_detect(int gpio_num);
int gpio_set_edge_detect(int gpio_num, GPIOEdgeDetect edge_detect);

#endif
