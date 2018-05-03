#include <devices/core/interfacing/sysfs/gpio/gpio_sysfs.h>

#include <devices/core/interfacing/sysfs/gpio/GPIOSYSFSDevice.hpp>

GPIODevice::GPIODeviceImpl::GPIODeviceImpl(int gpio_num) {
    gpio_num_ = gpio_num;
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_path(pathBuffer);
    path = pathBuffer;
    gpio_export(gpio_num, strcat(path, sc_sysfs_class_gpio_export_file));
}

GPIODevice::GPIODeviceImpl::~GPIODeviceImpl() {
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_path(pathBuffer);
    path = pathBuffer;
    gpio_unexport(gpio_num_, strcat(path, sc_sysfs_class_gpio_unexport_file));
}

GPIOPinMode GPIODevice::GPIODeviceImpl::getPinMode() const {
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_num_path_fmt(pathBuffer);
    path = pathBuffer;
    GPIODirection dir = gpio_get_dir(gpio_num_, strcat(path, sc_sysfs_class_gpio_direction_file));
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
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_num_path_fmt(pathBuffer);
    path = pathBuffer;

    if (pin_mode == GPIOPinModeRead) {
        dir = GPIODirectionIn;
    } else if (pin_mode == GPIOPinModeWrite) {
        dir = GPIODirectionOut;
    } else {
        printf("Operation not supported: %s", pin_mode);
    }

    gpio_set_dir(gpio_num_, dir, strcat(path, sc_sysfs_class_gpio_direction_file));
}

GPIOValue GPIODevice::GPIODeviceImpl::getValue() const {
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_num_path_fmt(pathBuffer);
    path = pathBuffer;
    return gpio_get_val(gpio_num_, strcat(path, sc_sysfs_class_gpio_value_file));
}

void GPIODevice::GPIODeviceImpl::setValue(GPIOValue value) {
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_num_path_fmt(pathBuffer);
    path = pathBuffer;
    gpio_set_val(gpio_num_, value, strcat(path, sc_sysfs_class_gpio_value_file));
}

GPIOEdgeDetect GPIODevice::GPIODeviceImpl::getEdgeDetect() const {
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_num_path_fmt(pathBuffer);
    path = pathBuffer;
    return gpio_get_edge_detect(gpio_num_, strcat(path, sc_sysfs_class_gpio_edge_file));
}

void GPIODevice::GPIODeviceImpl::setEdgeDetect(GPIOEdgeDetect edge_detect) {
    char pathBuffer[128];
    char *path;
    sc_sysfs_gpio_num_path_fmt(pathBuffer);
    path = pathBuffer;
    gpio_set_edge_detect(gpio_num_, edge_detect, strcat(path, sc_sysfs_class_gpio_edge_file));
}
