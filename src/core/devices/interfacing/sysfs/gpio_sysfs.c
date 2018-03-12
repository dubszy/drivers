#include <errno.h>
#include <stdio.h>

#include "gpio.h"

int gpio_export(int gpio_num) {
    FILE *export_fd;
    int write_res;

    if ((export_fd = fopen(_export_path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", _export_path, strerror(errno));
        return -1;
    }

    if ((write_res = fprintf(export_fd, "%d\n", gpio_num)) < 1) {
        printf("Failed to write to '%s' (%d)", _export_path, write_res);
        fclose(export_fd);
        return -2;
    }

    fclose(export_fd);
    return 0;
}

int gpio_unexport(int gpio_num) {
    FILE *unexport_fd;
    int write_res;

    if ((unexport_fd = fopen(_unexport_path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", _export_path, strerror(errno));
        return -1;
    }

    if ((write_res = fprintf(unexport_fd, "%d\n", gpio_num)) < 1) {
        printf("Failed to write to '%s' (%d)", _unexport_path, write_res);
        fclose(unexport_fd);
        return -2;
    }

    fclose(unexport_fd);
    return 0;
}

GPIODirection gpio_get_dir(int gpio_num) {
    FILE *dir_fd;
    const char *path;
    char *text;
    GPIODirection dir = GPIO_DIR_UNKNOWN;

    sprintf(path, _gpio_dir_path_fmt, gpio_num);

    if ((dir_fd = fopen(path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return GPIO_DIR_UNKNOWN;
    }

    while (fgets(text, 5, dir_fd) != NULL) {
        if (strncmp(text, "in", 2) == 0) {
            dir = GPIO_DIR_IN;
        } else if (strncmp(text, "out", 3) == 0) {
            dir = GPIO_DIR_OUT;
        }
    }

    fclose(dir_fd);
    return dir;
}

int gpio_set_dir(int gpio_num, GPIODirection dir) {
    FILE *dir_fd;
    const char *path;
    int write_res;
    const char *dir_str;

    sprintf(path, _gpio_dir_path_fmt, gpio_num);

    if ((dir_fd = fopen(path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return -1;
    }

    switch (dir) {
        case GPIO_DIR_IN:
            dir_str = "in";
            break;
        case GPIO_DIR_OUT:
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

GPIOValue gpio_get_val(int gpio_num) {
    FILE *val_fd;
    const char *path;
    char *text;
    GPIOValue val = GPIO_VAL_UNKNOWN;

    sprintf(path, _gpio_val_path_fmt, gpio_num);

    if ((val_fd = fopen(path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return GPIO_VAL_UNKNOWN;
    }

    while (fgets(text, 3, val_fd) != NULL) {
        if (strncmp(text, "0", 1) == 0) {
            val = GPIO_VAL_LOW;
        } else if (strncmp(text, "1", 1) == 0) {
            val = GPIO_VAL_HIGH;
        }
    }

    fclose(val_fd);
    return val;
}

int gpio_set_val(int gpio_num, GPIOValue val) {
    FILE *val_fd;
    const char *path;
    int write_res;
    const char *val_str;

    sprintf(path, _gpio_val_path_fmt, gpio_num);

    if ((val_fd = fopen(path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return -1;
    }

    switch (val) {
        case GPIO_VAL_LOW:
            val_str = "0";
            break;
        case GPIO_DIR_OUT:
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

GPIOEdgeDetect gpio_get_edge_detect(int gpio_num) {
    FILE *edge_fd;
    const char *path;
    char *text;
    GPIOEdgeDetect edge = GPIO_EDGE_UNKNOWN;

    sprintf(path, _gpio_edge_path_fmt, gpio_num);

    if ((edge_fd = fopen(path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return GPIO_EDGE_UNKNOWN;
    }

    while (fgets(text, 9, edge_fd) != NULL) {
        if (strncmp(text, "none", 6) == 0) {
            edge = GPIO_EDGE_NONE;
        } else if (strncmp(text, "rising", 8) == 0) {
            edge = GPIO_EDGE_RISING;
        } else if (strncmp(text, "falling", 9) == 0) {
            edge = GPIO_EDGE_FALLING;
        } else if (strncmp(text, "both", 6) == 0) {
            edge = GPIO_EDGE_BOTH;
        }
    }

    fclose(edge_fd);
    return edge;
}

int gpio_set_edge_detect(int gpio_num, GPIOEdgeDetect edge_detect) {
    FILE *edge_fd;
    const char *path;
    int write_res;
    const char *edge_str;

    sprintf(path, _gpio_edge_path_fmt, gpio_num);

    if ((edge_fd = fopen(path, "w")) == NULL) {
        printf("Failed to open '%s' (error: %s)", path, strerror(errno));
        return -1;
    }

    switch (edge_detect) {
        case GPIO_EDGE_NONE:
            edge_str = "none";
            break;
        case GPIO_EDGE_RISING:
            edge_str = "rising";
            break;
        case GPIO_EDGE_FALLING:
            edge_str = "falling";
            break;
        case GPIO_EDGE_BOTH:
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
