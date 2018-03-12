#include <core/devices/interfacing/sysfs/gpio_sysfs.h>

#include "GPIOSYSFSDevice.hpp"

GPIODevice::GPIODeviceImpl::GPIODeviceImpl(int gpio_num) {
    gpio_num_ = gpio_num;
    gpio_export(gpio_num, strcat(sc_sysfs_gpio_path(), sc_sysfs_class_gpio_export_file));
}

GPIODevice::GPIODeviceImpl::~GPIODeviceImpl() {
    gpio_unexport(gpio_num_, strcat(sc_sysfs_gpio_path(), sc_sysfs_class_gpio_unexport_file));
}

GPIOPinMode GPIODevice::GPIODeviceImpl::getPinMode() const {
    GPIODirection dir = gpio_get_dir(gpio_num_, strcat(sc_sysfs_gpio_num_path_fmt(), sc_sysfs_class_gpio_direction_file));
    if (dir == GPIODirectionIn) {
        return GPIOPinModeRead;
    } else if (dir == GPIODirectionOut) {
        return GPIOPinModeWrite;
    } else {
        printf("Invalid direction for GPIO device: %s\n", dir);
        return GPIOPinModeUnknown;
    }
}

void GPIODevice::GPIODeviceImpl::setPinMode(GPIOPinMode pin_mode) {
    GPIODirection dir;

    if (pin_mode == GPIOPinModeRead) {
        dir = GPIODirectionIn;
    } else if (pin_mode == GPIOPinModeWrite) {
        dir = GPIODirectionOut;
    } else {
        printf("Operation not supported: %s", pin_mode);
    }

    gpio_set_dir(gpio_num_, dir, strcat(sc_sysfs_gpio_num_path_fmt(), sc_sysfs_class_gpio_direction_file));
}

GPIOValue GPIODevice::GPIODeviceImpl::getValue() const {
    return gpio_get_val(gpio_num_, strcat(sc_sysfs_gpio_num_path_fmt(), sc_sysfs_class_gpio_value_file));
}

void GPIODevice::GPIODeviceImpl::setValue(GPIOValue value) {
    gpio_set_val(gpio_num_, value, strcat(sc_sysfs_gpio_num_path_fmt(), sc_sysfs_class_gpio_value_file));
}

GPIOEdgeDetect GPIODevice::GPIODeviceImpl::getEdgeDetect() const {
    return gpio_get_edge_detect(gpio_num_, strcat(sc_sysfs_gpio_num_path_fmt(), sc_sysfs_class_gpio_edge_file));
}

void GPIODevice::GPIODeviceImpl::setEdgeDetect(GPIOEdgeDetect edge_detect) {
    gpio_set_edge_detect(gpio_num_, edge_detect, strcat(sc_sysfs_gpio_num_path_fmt(), sc_sysfs_class_gpio_edge_file));
}
