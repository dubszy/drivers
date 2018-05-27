#ifndef SPI_DEVICE_HPP
#define SPI_DEVICE_HPP

#include <stdlib.h>
#include <sstream>

#include "Device.hpp"

#include <logger/c++/Logger.hpp>

class SPIDevice : public Device {

public:
	SPIDevice(string name, int channel, uint32_t speed, uint8_t bitsPerWord);

	int transact(uint8_t *data, unsigned int length);
	int transact16(uint16_t *data, unsigned int length);
	int transact32(uint32_t *data, unsigned int length);
	int transact64(uint64_t *data, unsigned int length);

	string toString();

private:
	int fd_;
	int channel_;
	uint32_t speed_;
	uint8_t bitsPerWord_;

	int transact_(void *data, unsigned int length);

	Logger *log = Logger::forClass<SPIDevice>(LogLevelInfo);
};


#endif /* SPI_DEVICE_HPP */
