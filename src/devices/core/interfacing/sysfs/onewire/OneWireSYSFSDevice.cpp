#include <cstdio>

#include <devices/core/interfacing/sysfs/onewire/onewire_sysfs.h>

#include <devices/core/interfacing/sysfs/onewire/OneWireSYSFSDevice.hpp>

OneWireDevice::OneWireDeviceImpl::OneWireDeviceImpl(OneWireFamilyCode family_code, string addr)
  : family_code_(family_code), addr_(addr) {
    char device_dir[15];
    sprintf(device_dir, "%02x-%s", family_code, addr.c_str());
    strcpy(device_dir_, device_dir);
};

int OneWireDevice::OneWireDeviceImpl::read(char *buf, int length) {
    char pathBuffer[128];
    char *path;
    sc_sysfs_w1_path(pathBuffer);
    path = pathBuffer;

    path = strcat(path, device_dir_);
    path = strcat(path, "/");
    path = strcat(path, sc_sysfs_bus_w1_slave_file);
    return onewire_read(buf, length, path);
}


