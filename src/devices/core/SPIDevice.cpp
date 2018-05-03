
#include <devices/core/SPIDevice.hpp>

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <string>
#include <sys/ioctl.h>

#include <devices/core/dummy_headers/spidev_dummy.h>

const static char     *device0    = "/dev/spidev0.0";
const static char     *device1    = "/dev/spidev0.1";
const static uint8_t  mode        = 0;
const static uint16_t delay       = 0;

SPIDevice::SPIDevice(string name, int channel, uint32_t speed, uint8_t bitsPerWord)
  : Device(std::move(name)) {

    channel_ = (channel & 1);
    speed_ = speed;
    bitsPerWord_ = bitsPerWord;

    if ((fd_ = open(channel_ == 0 ? device0 : device1, O_RDWR)) < 0) {
        printf("Unable to open SPI device: %s", strerror(errno));
        return;
    }

    if (ioctl(fd_, SPI_IOC_WR_MODE, &mode) < 0) {
        printf("Could not change mode for SPI device (%s)", strerror(errno));
        return;
    }
    if (ioctl(fd_, SPI_IOC_WR_BITS_PER_WORD, &bitsPerWord_) < 0) {
        printf("Could not set bits per word for SPI device (%s)", strerror(errno));
        return;
    }
    if (ioctl(fd_, SPI_IOC_WR_MAX_SPEED_HZ, &speed_) < 0) {
        printf("Could not set speed for SPI device (%s)", strerror(errno));
        return;
    }
}

int SPIDevice::transact(uint8_t *data, unsigned int length) {
    return transact_((void *)data, length);
}

int SPIDevice::transact16(uint16_t *data, unsigned int length) {
    return transact_((void *)data, length);
}

int SPIDevice::transact32(uint32_t *data, unsigned int length) {
    return transact_((void *)data, length);
}

int SPIDevice::transact64(uint64_t *data, unsigned int length) {
    return transact_((void *)data, length);
}

int SPIDevice::transact_(void *data, unsigned int length) {

    struct spi_ioc_transfer spi {};

    spi.tx_buf        = (unsigned long) data;
    spi.rx_buf        = (unsigned long) data;
    spi.len           = length;
    spi.delay_usecs   = delay;
    spi.speed_hz      = speed_;
    spi.bits_per_word = bitsPerWord_;

    return ioctl(fd_, SPI_IOC_MESSAGE(1), &spi);
}
