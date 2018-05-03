#ifndef _SYSTEM_CONTEXT_H_
#define _SYSTEM_CONTEXT_H_

#include <types/board_config_types.h>
#include <stdio.h>
#include <memory.h>

const char *sc_sysfs_bus_dir                    = "bus";
const char *sc_sysfs_class_dir                  = "class";

const char *sc_sysfs_class_gpio_dir             = "gpio";
const char *sc_sysfs_class_gpio_fmt             = "gpio%d";
const char *sc_sysfs_class_gpio_export_file     = "export";
const char *sc_sysfs_class_gpio_unexport_file   = "unexport";
const char *sc_sysfs_class_gpio_direction_file  = "direction";
const char *sc_sysfs_class_gpio_edge_file       = "edge";
const char *sc_sysfs_class_gpio_value_file      = "value";

const char *sc_sysfs_bus_w1_dir                 = "w1";
const char *sc_sysfs_bus_w1_devices_dir         = "devices";
const char *sc_sysfs_bus_w1_slave_file          = "w1-slave";

typedef struct {
    BoardConfig board_config;
    const char *dev_mount_path;
    const char *sysfs_mount_path;
} SystemContext;

SystemContext *globalSystemContext;

SystemContext *getGlobalSystemContext();
int setGlobalSystemContext(SystemContext context);
int createGlobalSystemContext();

inline void sc_sysfs_gpio_path(char *path) {
    sprintf(path, "/%s/%s/%s/",
            getGlobalSystemContext()->sysfs_mount_path,
            sc_sysfs_class_dir,
            sc_sysfs_class_gpio_dir);
}

inline void sc_sysfs_gpio_num_path_fmt(char *path) {
    char gpio_path[32];
    sc_sysfs_gpio_path(gpio_path);
    sprintf(path, "/%s/%s/", gpio_path, sc_sysfs_class_gpio_fmt);
}

inline void sc_sysfs_w1_path(char *path) {
    sprintf(path, "/%s/%s/%s/%s/",
            getGlobalSystemContext()->sysfs_mount_path,
            sc_sysfs_bus_dir,
            sc_sysfs_bus_w1_dir,
            sc_sysfs_bus_w1_devices_dir);
}

#endif /* _SYSTEM_CONTEXT_H_ */
