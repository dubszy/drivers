#include <stdio.h>

#include <core/devices/interfacing/sysfs/onewire/onewire_sysfs.h>

#include "OneWireSYSFSDevice.hpp"

OneWireDevice::OneWireDeviceImpl::OneWireDeviceImpl(OneWireFamilyCode family_code, uint8_t *addr)
  : family_code_(family_code), addr_(addr) {
    char device_dir[15];
    sprintf(device_dir, "%02x-%012x", family_code, addr);
    device_dir_ = device_dir;
};

int OneWireDevice::OneWireDeviceImpl::read(char *buf, int length) {
    char *path = sc_sysfs_w1_path();
    path = strcat(path, device_dir_);
    path = strcat(path, "/");
    path = strcat(path, sc_sysfs_bus_w1_slave_file);
    return onewire_read(buf, length, path);
}


