/**
 * I2C device communication using SMBus
 */

#ifndef I2C_DEVICE_HPP
#define I2C_DEVICE_HPP

#include <stdlib.h>
#include <string>
#include <sys/ioctl.h>

#include "Device.hpp"

#define I2C_SLAVE		0x0703
#define I2C_SMBUS		0x0720

#define SMBUS_WRITE		0
#define SMBUS_READ		1

// SMBus transaction types
#define SMBUS_QUICK				0
#define SMBUS_BYTE				1
#define SMBUS_BYTE_DATA			2
#define SMBUS_WORD_DATA			3
#define SMBUS_PROC_CALL			4
#define SMBUS_BLOCK_DATA			5
#define SMBUS_I2C_BLOCK_BROKEN	6
#define SMBUS_BLOCK_PROC_CALL	7
#define SMBUS_I2C_BLOCK_DATA		8

#define SMBUS_BLOCK_MAX			32

union smbus_data {
	uint8_t  byte;
	uint16_t word;
	uint8_t  block[SMBUS_BLOCK_MAX + 2]; // block[0] is used for length, block[33] for PEC
};

struct smbus_transaction_data {
	char    read_write;
	uint8_t command;
	int     size;
	union   smbus_data *data;
};

static inline int smbus_transact(int fd, char rw, uint8_t command, int size, union smbus_data *data) {
	struct smbus_transaction_data t_data;
	t_data.read_write = rw;
	t_data.command = command;
	t_data.size = size;
	t_data.data = data;

	return ioctl(fd, I2C_SMBUS, &t_data);
};

using namespace std;


class I2CDevice : public Device {

public:
	I2CDevice(string name, string deviceFilePath, int deviceId);

	int getFd();
	int read();
	int readByte(uint8_t reg);
	int readWord(uint8_t reg);
	int write(uint8_t data);
	int writeByte(uint8_t reg, uint8_t value);
	int writeWord(uint8_t reg, uint16_t value);

private:
	I2CDevice(const I2CDevice&);
	I2CDevice& operator=(const I2CDevice&);

	int fd;
};


#endif /* I2C_DEVICE_HPP */
