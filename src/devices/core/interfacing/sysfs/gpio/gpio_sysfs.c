#include <devices/core/interfacing/sysfs/gpio/gpio_sysfs.h>
#include <errno.h>
#include <stdio.h>

int gpio_export(int gpio_num, const char *export_path) {
    FILE *export_fd;
    int write_res;

    if ((export_fd = fopen(export_path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", export_path, strerror(errno));
        return -1;
    }

    if ((write_res = fprintf(export_fd, "%d\n", gpio_num)) < 1) {
        printf("Failed to write to '%s' (%d)", export_path, write_res);
        fclose(export_fd);
        return -2;
    }

    fclose(export_fd);
    return 0;
}

int gpio_unexport(int gpio_num, const char *unexport_path) {
    FILE *unexport_fd;
    int write_res;

    if ((unexport_fd = fopen(unexport_path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", unexport_path, strerror(errno));
        return -1;
    }

    if ((write_res = fprintf(unexport_fd, "%d\n", gpio_num)) < 1) {
        printf("Failed to write to '%s' (%d)", unexport_path, write_res);
        fclose(unexport_fd);
        return -2;
    }

    fclose(unexport_fd);
    return 0;
}

GPIODirection gpio_get_dir(int gpio_num, const char *gpio_dir_path_fmt) {
    FILE *dir_fd;
    const char *path;
    char *text;
    GPIODirection dir = GPIODirectionUnknown;

    sprintf(path, gpio_dir_path_fmt, gpio_num);

    if ((dir_fd = fopen(path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return dir;
    }

    while (fgets(text, 5, dir_fd) != NULL) {
        if (strncmp(text, "in", 2) == 0) {
            dir = GPIODirectionIn;
        } else if (strncmp(text, "out", 3) == 0) {
            dir = GPIODirectionOut;
        }
    }

    fclose(dir_fd);
    return dir;
}

int gpio_set_dir(int gpio_num, GPIODirection dir, const char *gpio_dir_path_fmt) {
    FILE *dir_fd;
    const char *path;
    int write_res;
    const char *dir_str;

    sprintf(path, gpio_dir_path_fmt, gpio_num);

    if ((dir_fd = fopen(path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return -1;
    }

    switch (dir) {
        case GPIODirectionIn:
            dir_str = "in";
            break;
        case GPIODirectionOut:
            dir_str = "out";
            break;
        default:
            printf("Invalid direction: %d", dir);
            break;
    }

    if ((write_res = fprintf(dir_fd, "%s\n", dir_str)) < 1) {
        printf("Failed to write to '%s' (%d)", path, write_res);
        fclose(dir_fd);
        return -2;
    }

    fclose(dir_fd);
    return 0;
}

GPIOValue gpio_get_val(int gpio_num, const char *gpio_val_path_fmt) {
    FILE *val_fd;
    const char *path;
    char *text;
    GPIOValue val = GPIOValueUnknown;

    sprintf(path, gpio_val_path_fmt, gpio_num);

    if ((val_fd = fopen(path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return val;
    }

    while (fgets(text, 3, val_fd) != NULL) {
        if (strncmp(text, "0", 1) == 0) {
            val = GPIOValueLow;
        } else if (strncmp(text, "1", 1) == 0) {
            val = GPIOValueHigh;
        }
    }

    fclose(val_fd);
    return val;
}

int gpio_set_val(int gpio_num, GPIOValue val, const char *gpio_val_path_fmt) {
    FILE *val_fd;
    const char *path;
    int write_res;
    const char *val_str;

    sprintf(path, gpio_val_path_fmt, gpio_num);

    if ((val_fd = fopen(path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return -1;
    }

    switch (val) {
        case GPIOValueLow:
            val_str = "0";
            break;
        case GPIOValueHigh:
            val_str = "1";
            break;
        default:
            printf("Invalid value: %d", val);
            break;
    }

    if ((write_res = fprintf(val_fd, "%s\n", val_str)) < 1) {
        printf("Failed to write to '%s' (%d)", path, write_res);
        fclose(val_fd);
        return -2;
    }

    fclose(val_fd);
    return 0;
}

GPIOEdgeDetect gpio_get_edge_detect(int gpio_num, const char *gpio_edge_path_fmt) {
    FILE *edge_fd;
    const char *path;
    char *text;
    GPIOEdgeDetect edge = GPIOEdgeDetectUnknown;

    sprintf(path, gpio_edge_path_fmt, gpio_num);

    if ((edge_fd = fopen(path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return edge;
    }

    while (fgets(text, 9, edge_fd) != NULL) {
        if (strncmp(text, "none", 6) == 0) {
            edge = GPIOEdgeDetectNone;
        } else if (strncmp(text, "rising", 8) == 0) {
            edge = GPIOEdgeDetectRising;
        } else if (strncmp(text, "falling", 9) == 0) {
            edge = GPIOEdgeDetectFalling;
        } else if (strncmp(text, "both", 6) == 0) {
            edge = (GPIOEdgeDetectRising | GPIOEdgeDetectFalling);
        }
    }

    fclose(edge_fd);
    return edge;
}

int gpio_set_edge_detect(int gpio_num, GPIOEdgeDetect edge_detect, const char *gpio_edge_path_fmt) {
    FILE *edge_fd;
    const char *path;
    int write_res;
    const char *edge_str;

    sprintf(path, gpio_edge_path_fmt, gpio_num);

    if ((edge_fd = fopen(path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return -1;
    }

    switch (edge_detect) {
        case GPIOEdgeDetectNone:
            edge_str = "none";
            break;
        case GPIOEdgeDetectRising:
            edge_str = "rising";
            break;
        case GPIOEdgeDetectFalling:
            edge_str = "falling";
            break;
        case (GPIOEdgeDetectRising | GPIOEdgeDetectFalling):
            edge_str = "both";
            break;
        default:
            printf("Invalid value: %d", edge_detect);
            break;
    }

    if ((write_res = fprintf(edge_fd, "%s\n", edge_str)) < 1) {
        printf("Failed to write to '%s' (%d)", path, write_res);
        fclose(edge_fd);
        return -2;
    }

    fclose(edge_fd);
    return 0;
}
