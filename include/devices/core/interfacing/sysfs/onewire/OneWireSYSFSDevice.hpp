#ifndef _ONE_WIRE_SYSFS_DEVICE_HPP_
#define _ONE_WIRE_SYSFS_DEVICE_HPP_

#include <devices/core/OneWireDevice.hpp>

class OneWireDevice::OneWireDeviceImpl {

private:
    OneWireFamilyCode family_code_;
    string addr_; // Address for the device (48 bits long, 16MSB are ignored)
    char *device_dir_;

public:
    OneWireDeviceImpl(OneWireFamilyCode family_code, string addr);

    int read(char *buf, int length);
};

#endif /* _ONE_WIRE_SYSFS_DEVICE_HPP_ */
