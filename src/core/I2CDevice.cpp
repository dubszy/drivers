#include "I2CDevice.hpp"

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

using namespace Core;

void I2CDevice::init(string *deviceFilePath, int deviceId) {
	int fd;

	if ((fd = open(deviceFilePath->c_str(), O_RDWR)) < 0) {
		printf("Could not open I2C device file: %s", strerror(errno));
		fd = -1;
		return;
	}

	if (ioctl(fd, I2C_SLAVE, deviceId) < 0) {
		printf("Could not select I2C device: %s", strerror(errno));
		fd = -1;
		return;
	}

	this->fd = fd;
}

int I2CDevice::read() {
	union smbus_data data;
	if (smbus_transact(fd, SMBUS_READ, 0, SMBUS_BYTE, &data)) {
		return -1;
	} else {
		return data.byte & 0xFF;
	}
}

int I2CDevice::readByte(int reg) {
	union smbus_data data;
	if (smbus_transact(fd, SMBUS_READ, reg, SMBUS_BYTE_DATA, &data)) {
		return -1;
	} else {
		return data.byte & 0xFF;
	}
}

int I2CDevice::readWord(int reg) {
	union smbus_data data;
	if (smbus_transact(fd, SMBUS_READ, reg, SMBUS_WORD_DATA, &data)) {
		return -1;
	} else {
		return data.word & 0xFFFF;
	}
}

int I2CDevice::write(int data) {
	return smbus_transact(fd, SMBUS_WRITE, data, SMBUS_BYTE, NULL);
}

int I2CDevice::writeByte(int reg, int value) {
	union smbus_data data;
	data.byte = value;
	return smbus_transact(fd, SMBUS_WRITE, reg, SMBUS_BYTE_DATA, &data);
}

int I2CDevice::writeWord(int reg, int value) {
	union smbus_data data;
	data.word = value;
	return smbus_transact(fd, SMBUS_WRITE, reg, SMBUS_WORD_DATA, &data);
}
