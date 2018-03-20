#include "OneWireDevice.hpp"
#include <core/devices/interfacing/sysfs/onewire/OneWireSYSFSDevice.hpp>

OneWireDevice::OneWireDevice(OneWireFamilyCode family_code, uint8_t *addr)
  : p_impl_(new OneWireDeviceImpl(family_code, addr)) {}

OneWireDevice::~OneWireDevice() {
    delete p_impl_;
}

int OneWireDevice::read(char *buf, int length) {
    return p_impl_->read(buf, length);
}
