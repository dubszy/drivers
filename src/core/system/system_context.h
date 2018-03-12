#ifndef _SYSTEM_CONTEXT_H_
#define _SYSTEM_CONTEXT_H_

#include <core/types/board_config_types.h>

const char *sc_sysfs_class_dir                  = "class";
const char *sc_sysfs_class_gpio_dir             = "gpio";
const char *sc_sysfs_class_gpio_fmt             = "gpio%d";
const char *sc_sysfs_class_gpio_export_file     = "export";
const char *sc_sysfs_class_gpio_unexport_file   = "unexport";
const char *sc_sysfs_class_gpio_direction_file  = "direction";
const char *sc_sysfs_class_gpio_edge_file       = "edge";
const char *sc_sysfs_class_gpio_value_file      = "value";

typedef struct {
    BoardConfig board_config;
    const char *dev_mount_path;
    const char *sysfs_mount_path;
} SystemContext;

SystemContext *globalSystemContext;

SystemContext *getGlobalSystemContext();
int setGlobalSystemContext(SystemContext context);
int createGlobalSystemContext();

inline char *sc_sysfs_gpio_path() {
    char *path = strcpy(path, getGlobalSystemContext()->sysfs_mount_path);
    path = strcat(path, sc_sysfs_class_dir);
    path = strcat(path, sc_sysfs_class_gpio_dir);
    return path;
}

inline char *sc_sysfs_gpio_num_path_fmt() {
    char *path = strcpy(path, sc_sysfs_gpio_path());
    path = strcat(path, sc_sysfs_class_gpio_fmt);
    return path;
}

#endif /* _SYSTEM_CONTEXT_H_ */
