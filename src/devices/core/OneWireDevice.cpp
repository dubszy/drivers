#include <devices/core/OneWireDevice.hpp>
#include <devices/core/interfacing/sysfs/onewire/OneWireSYSFSDevice.hpp>
#include <utility>
#include <sstream>

OneWireDevice::OneWireDevice(string name, OneWireFamilyCode familyCode, string address)
  : p_impl_(new OneWireDeviceImpl(familyCode, address)),
    Device(name) {
    log->debug("Instantiating new OneWireDevice");
}

OneWireDevice::~OneWireDevice() {
    delete p_impl_;
}

size_t OneWireDevice::read(char *buf, size_t length) {
    return p_impl_->read(buf, length);
}

OneWireFamilyCode OneWireDevice::getFamilyCode() {
    return p_impl_->getFamilyCode();
}

string OneWireDevice::getAddress() {
    return p_impl_->getAddress();
}

string OneWireDevice::toString() {
    stringstream sstream;
    sstream << "OneWireDevice: { Name: " << getName()
            << ", Family Code: 0x" << std::hex << (uint32_t)getFamilyCode()
            << ", Address: " << getAddress()
            << " }";
    return sstream.str();
}
