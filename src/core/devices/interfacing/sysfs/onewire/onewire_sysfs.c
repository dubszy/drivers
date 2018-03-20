#include <errno.h>
#include <stdio.h>

#include "onewire_sysfs.h"

int onewire_read(char *buf, int len, const char *onewire_dir_path) {
    FILE *w1_fd;
    int read_res;

    if ((w1_fd = fopen(onewire_dir_path, "r")) == NULL) {
        printf("Failed to open '%s' (error: %s)", onewire_dir_path, strerror(errno));
        return -1;
    }

    read_res = fread(buf, 1, len, onewire_dir_path);
    fclose(w1_fd);
    return read_res;
}
