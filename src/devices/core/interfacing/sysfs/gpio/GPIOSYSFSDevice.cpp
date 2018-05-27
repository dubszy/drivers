#include <devices/core/interfacing/sysfs/gpio/gpio_sysfs.h>

#include <devices/core/interfacing/sysfs/gpio/GPIOSYSFSDevice.hpp>

GPIODevice::GPIODeviceImpl::GPIODeviceImpl(unsigned int gpio_num) {
    gpio_num_ = gpio_num;
    gpio_export(gpio_num, SC_PATH_SYSFS_CLASS_GPIO_EXPORT);
}

GPIODevice::GPIODeviceImpl::~GPIODeviceImpl() {
    gpio_unexport(gpio_num_, SC_PATH_SYSFS_CLASS_GPIO_UNEXPORT);
}

GPIOPinMode GPIODevice::GPIODeviceImpl::getPinMode() const {
    GPIODirection dir = gpio_get_dir(gpio_num_, SC_PATH_SYSFS_CLASS_GPIO_N_DIRECTION);
    if (dir == GPIODirectionIn) {
        return GPIOPinModeRead;
    } else if (dir == GPIODirectionOut) {
        return GPIOPinModeWrite;
    } else {
        printf("Invalid direction for GPIO device: %d\n", dir);
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
        printf("Operation not supported: %d", pin_mode);
        return;
    }

    gpio_set_dir(gpio_num_, dir, SC_PATH_SYSFS_CLASS_GPIO_N_DIRECTION);
}

GPIOValue GPIODevice::GPIODeviceImpl::getValue() const {
    return gpio_get_val(gpio_num_, SC_PATH_SYSFS_CLASS_GPIO_N_VALUE);
}

void GPIODevice::GPIODeviceImpl::setValue(GPIOValue value) {
    gpio_set_val(gpio_num_, value, SC_PATH_SYSFS_CLASS_GPIO_N_VALUE);
}

GPIOEdgeDetect GPIODevice::GPIODeviceImpl::getEdgeDetect() const {
    return gpio_get_edge_detect(gpio_num_, SC_PATH_SYSFS_CLASS_GPIO_N_EDGE);
}

void GPIODevice::GPIODeviceImpl::setEdgeDetect(GPIOEdgeDetect edge_detect) {
    gpio_set_edge_detect(gpio_num_, edge_detect, SC_PATH_SYSFS_CLASS_GPIO_N_EDGE);
}
