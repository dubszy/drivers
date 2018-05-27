#ifndef _ONE_WIRE_SYSFS_DEVICE_HPP_
#define _ONE_WIRE_SYSFS_DEVICE_HPP_

#include <devices/core/OneWireDevice.hpp>

#include <logger/c++/Logger.hpp>

class OneWireDevice::OneWireDeviceImpl {

public:
    OneWireDeviceImpl(OneWireFamilyCode familyCode, string address);

    size_t read(char *buf, size_t length);

    OneWireFamilyCode getFamilyCode();
    string getAddress();
    string getDeviceDirectory();

    string toString();

private:
    OneWireFamilyCode familyCode_;
    string address_;
    string deviceDirectory_;

    Logger *log = Logger::forClass<OneWireDevice::OneWireDeviceImpl>(LogLevelInfo);
};

#endif /* _ONE_WIRE_SYSFS_DEVICE_HPP_ */
