#include <devices/core/OneWireDevice.hpp>
#include <devices/core/interfacing/sysfs/onewire/OneWireSYSFSDevice.hpp>
#include <utility>

OneWireDevice::OneWireDevice(string name, OneWireFamilyCode family_code, string addr)
  : p_impl_(new OneWireDeviceImpl(family_code, std::move(addr))), Device(std::move(name)) {}

OneWireDevice::~OneWireDevice() {
    delete p_impl_;
}

int OneWireDevice::read(char *buf, int length) {
    return p_impl_->read(buf, length);
}
