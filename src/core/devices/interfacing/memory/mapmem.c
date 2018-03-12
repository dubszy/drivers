#include "mapmem.h"

int mapmem(struct mem_block *m, size_t block_size) {
    if ((m->mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
        printf("Failed to open /dev/mem, try checking permissions\n");
        return -1;
    }

    m->map = mmap(NULL, block_size, PROT_READ | PROT_WRITE, MAP_SHARED, m->mem_fd, m->addr_p);

    if (m->map == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    m->addr = (volatile unsigned int *)m->map;

    return 0;
}

int unmapmem(struct mem_block *m, size_t block_size) {
    int unmap_res = munmap(m->map, block_size);
    close(m->mem_fd);
    return unmap_res;
}
