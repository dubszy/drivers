#ifndef _SERIAL_DEVICE_HPP_
#define _SERIAL_DEVICE_HPP_

#include "Device.hpp"

class SerialDevice : public Device {

public:
    SerialDevice(string name = "SerialDevice")
      : Device(std::move(name)) {}

private:
    SerialDevice(const SerialDevice&);
    SerialDevice& operator=(const SerialDevice&);
};

#endif /* _SERIAL_DEVICE_HPP_ */
