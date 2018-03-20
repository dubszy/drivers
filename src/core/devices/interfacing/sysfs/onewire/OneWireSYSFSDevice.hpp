#ifndef _ONE_WIRE_SYSFS_DEVICE_HPP_
#define _ONE_WIRE_SYSFS_DEVICE_HPP_

#include <core/OneWireDevice.hpp>

class OneWireDevice::OneWireDeviceImpl {

private:
    OneWireFamilyCode family_code_;
    uint8_t addr_[8];
    const char *device_dir_;

public:
    OneWireDeviceImpl(OneWireFamilyCode family_code, uint8_t *addr);

    int read(char *buf, int length);
};

#endif /* _ONE_WIRE_SYSFS_DEVICE_HPP_ */
