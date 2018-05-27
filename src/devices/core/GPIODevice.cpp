#include <devices/core/GPIODevice.hpp>
#include <devices/core/interfacing/sysfs/gpio/GPIOSYSFSDevice.hpp>
#include <utility>

GPIODevice::GPIODevice(string name, unsigned int gpio_num)
  : p_impl_(new GPIODeviceImpl(gpio_num)), Device(std::move(name)) {
#if defined(GPIO_MIN) && defined(GPIO_MAX)
    if (gpio_num > GPIO_MAX || gpio_num < GPIO_MIN) {
        printf("GPIO pin number must be between %d and %d (inclusive)", GPIO_MIN, GPIO_MAX);
    }
#endif
}

GPIODevice::~GPIODevice() {
    delete p_impl_;
}

GPIOPinMode GPIODevice::getPinMode() const {
    return p_impl_->getPinMode();
}

void GPIODevice::setPinMode(GPIOPinMode pin_mode) {
    p_impl_->setPinMode(pin_mode);
}

GPIOValue GPIODevice::getValue() const {
    return p_impl_->getValue();
}

void GPIODevice::setValue(GPIOValue value) {
    p_impl_->setValue(value);
}

int GPIODevice::getEdgeDetect() const {
    return p_impl_->getEdgeDetect();
}

void GPIODevice::setEdgeDetect(GPIOEdgeDetect edge_detect) {
    p_impl_->setEdgeDetect(edge_detect);
}
