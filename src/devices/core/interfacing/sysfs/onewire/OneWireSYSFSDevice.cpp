#ifndef _ONEWIRE_SYSFS_DEVICE_HPP_
#define _ONEWIRE_SYSFS_DEVICE_HPP_

#include <cstdio>

#include <devices/core/interfacing/sysfs/onewire/onewire_sysfs.h>

#include <devices/core/interfacing/sysfs/onewire/OneWireSYSFSDevice.hpp>
#include <cerrno>
#include <sstream>

OneWireDevice::OneWireDeviceImpl::OneWireDeviceImpl(OneWireFamilyCode familyCode, string address)
  : familyCode_(familyCode), address_(address) {
    log->debug("Instantiating new OneWireDevice::OneWireDeviceImpl");
    stringstream sstream;
    sstream << std::hex << familyCode << "-" << address;
    deviceDirectory_ = sstream.str();
}

size_t OneWireDevice::OneWireDeviceImpl::read(char *buf, size_t length) {
    char pathBuffer[128];
    char *path;
    sprintf(pathBuffer, SC_PATH_SYSFS_BUS_W1_DEVICE_N_SLAVE, deviceDirectory_.c_str());
    path = pathBuffer;

    FILE *w1_fd;
    size_t read_res;

    if ((w1_fd = fopen(path, "r")) == nullptr) {
        log->error("Failed to open '%s' (error: %s)", path, strerror(errno));
        return (size_t) -1;
    }

    read_res = fread(buf, 1, length, w1_fd);
    fclose(w1_fd);
    return read_res;
}

OneWireFamilyCode OneWireDevice::OneWireDeviceImpl::getFamilyCode() {
    return familyCode_;
}

string OneWireDevice::OneWireDeviceImpl::getAddress() {
    return address_;
}

string OneWireDevice::OneWireDeviceImpl::getDeviceDirectory() {
    return deviceDirectory_;
}

string OneWireDevice::OneWireDeviceImpl::toString() {
    stringstream sstream;
    sstream << "OneWireDeviceImpl: { Family Code: " << familyCode_
            << ", Address: " << address_
            << ", Device Directory: " << deviceDirectory_
            << " }";
    return sstream.str();
}

#endif /* _ONEWIRE_SYSFS_DEVICE_HPP_ */
