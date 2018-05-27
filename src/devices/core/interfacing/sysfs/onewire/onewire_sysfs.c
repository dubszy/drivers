#include <errno.h>
#include <stdio.h>

#include <devices/core/interfacing/sysfs/onewire/onewire_sysfs.h>
#include <memory.h>

size_t onewire_read(char *buf, size_t len, const char *onewire_dir_path) {
    FILE *w1_fd;
    size_t read_res;

    if ((w1_fd = fopen(onewire_dir_path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", onewire_dir_path, strerror(errno));
        return (size_t) -1;
    }

    read_res = fread(buf, 1, len, w1_fd);
    fclose(w1_fd);
    return read_res;
}
