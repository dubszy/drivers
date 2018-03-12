#ifndef _SERIAL_DEVICE_HPP_
#define _SERIAL_DEVICE_HPP_

#include "Device.hpp"

class SerialDevice : Device {
private:
        SerialDevice(const SerialDevice&);
        SerialDevice& operator=(const SerialDevice&);

public:
        SerialDevice();
};

#endif /* _SERIAL_DEVICE_HPP_ */
