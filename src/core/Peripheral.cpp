#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#include "Peripheral.hpp"

using namespace Core;

int Peripheral::mapPeripheral(struct peripheral_dev *p) {

	if ((p->mem_fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
		printf("Failed to open /dev/mem, try checking permissions\n");
		return -1;
	}

	p->map = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, p->mem_fd, p->addr_p);

	if (p->map == MAP_FAILED) {
		perror("mmap");
		return -1;
	}

	p->addr = (volatile unsigned int *)p->map;

	return 0;
}

void Peripheral::unmapPeripheral(struct peripheral_dev *p) {
	munmap(p->map, BLOCK_SIZE);
	close(p->mem_fd);
}
