#ifndef SPI_DEVICE_HPP
#define SPI_DEVICE_HPP

#include <stdlib.h>

#include "Device.hpp"

namespace Core {
	class SPIDevice : Device {

	private:
		int fd;
		int channel;
		uint32_t speed;

	public:
		void init(int channel, int speed);
		int transact(unsigned char *data, int length);
	};
}

#endif /* SPI_DEVICE_HPP */
