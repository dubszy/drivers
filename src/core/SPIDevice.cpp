
#include "SPIDevice.hpp"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/ioctl.h>

#include "dummy_headers/spidev_dummy.h"

using namespace Core;

const static char     *device0    = "/dev/spidev0.0";
const static char     *device1    = "/dev/spidev0.1";
const static uint8_t  mode        = 0;
const static uint8_t  bitsPerWord = 8;
const static uint16_t delay       = 0;

void SPIDevice::init(int channel, int speed) {
	int _fd;

	channel &= 1;

	if ((_fd = open(channel == 0 ? device0 : device1, O_RDWR)) < 0) {
		printf("Unable to open SPI device: %s", strerror(errno));
		return;
	}

	this->speed = speed;
	this->fd = _fd;

	if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0) {
		printf("Could not change mode for SPI device (%s)", strerror(errno));
		return;
	}
	if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bitsPerWord) < 0) {
		printf("Could not set bits per word for SPI device (%s)", strerror(errno));
		return;
	}
	if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &this->speed) < 0) {
		printf("Could not set speed for SPI device (%s)", strerror(errno));
		return;
	}
}

int SPIDevice::transact(unsigned char *data, int length) {
	struct spi_ioc_transfer spi;

	spi.tx_buf        = (unsigned long) data;
	spi.rx_buf        = (unsigned long) data;
	spi.len           = length;
	spi.delay_usecs   = delay;
	spi.speed_hz      = speed;
	spi.bits_per_word = bitsPerWord;

	return ioctl(fd, SPI_IOC_MESSAGE(1), &spi);
}
