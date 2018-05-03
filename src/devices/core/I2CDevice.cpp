#include <devices/core/I2CDevice.hpp>

#include <cerrno>
#include <cstdio>
#include <fcntl.h>

I2CDevice::I2CDevice(string name, string deviceFilePath, int deviceId) {
	int fd;

	if ((fd = open(deviceFilePath.c_str(), O_RDWR)) < 0) {
		printf("Could not open I2C device file: %s", strerror(errno));
		fd = -1;
	}

	if (ioctl(fd, I2C_SLAVE, deviceId) < 0) {
		printf("Could not select I2C device: %s", strerror(errno));
		fd = -1;
	}

	this->fd = fd;
}

int I2CDevice::read() {
	union smbus_data data {};
	return smbus_transact(fd, SMBUS_READ, 0, SMBUS_BYTE, &data) ? -1 : data.byte & 0xFF;
}

int I2CDevice::readByte(uint8_t reg) {
	union smbus_data data {};
	return smbus_transact(fd, SMBUS_READ, reg, SMBUS_BYTE_DATA, &data) ? -1 : data.byte & 0xFF;
}

int I2CDevice::readWord(uint8_t reg) {
	union smbus_data data {};
	return smbus_transact(fd, SMBUS_READ, reg, SMBUS_WORD_DATA, &data) ? -1 : data.word & 0xFFFF;
}

int I2CDevice::write(uint8_t data) {
	return smbus_transact(fd, SMBUS_WRITE, data, SMBUS_BYTE, nullptr);
}

int I2CDevice::writeByte(uint8_t reg, uint8_t value) {
	union smbus_data data {};
	data.byte = value;
	return smbus_transact(fd, SMBUS_WRITE, reg, SMBUS_BYTE_DATA, &data);
}

int I2CDevice::writeWord(uint8_t reg, uint16_t value) {
	union smbus_data data {};
	data.word = value;
	return smbus_transact(fd, SMBUS_WRITE, reg, SMBUS_WORD_DATA, &data);
}
