#ifndef _SYSTEM_CONTEXT_H_
#define _SYSTEM_CONTEXT_H_

#include <types/board_config_types.h>
#include <stdio.h>
#include <memory.h>

#define SC_PATH_SYSFS_MOUNT                     "/sys"

#define SC_PATH_SYSFS_BUS                       SC_PATH_SYSFS_MOUNT"/bus"

#define SC_PATH_SYSFS_BUS_W1                    SC_PATH_SYSFS_BUS"/w1"
#define SC_PATH_SYSFS_BUS_W1_DEVICES            SC_PATH_SYSFS_BUS_W1"/devices"
#define SC_PATH_SYSFS_BUS_W1_DEVICE_N           SC_PATH_SYSFS_BUS_W1_DEVICES"/%s"
#define SC_PATH_SYSFS_BUS_W1_DEVICE_N_SLAVE     SC_PATH_SYSFS_BUS_W1_DEVICE_N"/w1_slave"

#define SC_PATH_SYSFS_CLASS                     SC_PATH_SYSFS_MOUNT"/class"

#define SC_PATH_SYSFS_CLASS_GPIO                SC_PATH_SYSFS_CLASS"/gpio"
#define SC_PATH_SYSFS_CLASS_GPIO_N              SC_PATH_SYSFS_CLASS_GPIO"/gpio%d"
#define SC_PATH_SYSFS_CLASS_GPIO_N_DIRECTION    SC_PATH_SYSFS_CLASS_GPIO_N"/direction"
#define SC_PATH_SYSFS_CLASS_GPIO_N_EDGE         SC_PATH_SYSFS_CLASS_GPIO_N"/edge"
#define SC_PATH_SYSFS_CLASS_GPIO_N_VALUE        SC_PATH_SYSFS_CLASS_GPIO_N"/value"
#define SC_PATH_SYSFS_CLASS_GPIO_EXPORT         SC_PATH_SYSFS_CLASS_GPIO"/export"
#define SC_PATH_SYSFS_CLASS_GPIO_UNEXPORT       SC_PATH_SYSFS_CLASS_GPIO"/unexport"

#endif /* _SYSTEM_CONTEXT_H_ */
