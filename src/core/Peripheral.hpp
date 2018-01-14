#ifndef PERIPHERAL_HPP
#define PERIPHERAL_HPP

#define BLOCK_SIZE 1024

struct peripheral_dev {
	unsigned long addr_p;
	int mem_fd;
	void *map;
	volatile unsigned int *addr;
};

namespace Core {
	class Peripheral {

	public:
		int mapPeripheral(struct peripheral_dev *p);
		void unmapPeripheral(struct peripheral_dev *p);
	};
}

#endif PERIPHERAL_HPP
