#ifndef _MAP_MEM_H_
#define _MAP_MEM_H_

#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>

struct mem_block {
    unsigned long addr_p;
    int mem_fd;
    void *map;
    volatile unsigned int *addr;
};

int mapmem(struct mem_block *m, size_t block_size);
int unmapmem(struct mem_block *m, size_t block_size);

#endif /* _MAP_MEM_H_ */
