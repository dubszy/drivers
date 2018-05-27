
#include <devices/core/interfacing/memory/gpio/gpio_mem.h>
#include <devices/core/interfacing/memory/gpio/GPIOMemoryDevice.hpp>

GPIODevice::GPIODeviceImpl::GPIODeviceImpl(unsigned int gpio_num) {
    gpio_num_ = gpio_num;
    if (!is_gpio_mapped()) {
        gpio_map();
    }
}

GPIOPinMode GPIODevice::GPIODeviceImpl::getPinMode() const {
    return gpio_get_pin_mode(gpio_num_);
}

void GPIODevice::GPIODeviceImpl::setPinMode(GPIOPinMode pin_mode) {
    gpio_set_pin_mode(gpio_num_, pin_mode);
}

GPIOValue GPIODevice::GPIODeviceImpl::getValue() const {
    return (gpio_read_level(gpio_num_)) ? GPIOValueHigh : GPIOValueLow;
}

void GPIODevice::GPIODeviceImpl::setValue(GPIOValue value) {
    if (value == GPIOValueHigh) {
        gpio_set_high(gpio_num_);
    } else if (value == GPIOValueLow) {
        gpio_set_low(gpio_num_);
    } else {
        printf("Invalid value for GPIO: %d", value);
    }
}

int GPIODevice::GPIODeviceImpl::getEdgeDetect() const {
    int edge_detect = 0;

    edge_detect |= (gpio_is_event_detect_rising(gpio_num_))        ? GPIOEdgeDetectRising       : GPIOEdgeDetectNone;
    edge_detect |= (gpio_is_event_detect_falling(gpio_num_))       ? GPIOEdgeDetectFalling      : GPIOEdgeDetectNone;
    edge_detect |= (gpio_is_event_detect_high(gpio_num_))          ? GPIOEdgeDetectHigh         : GPIOEdgeDetectNone;
    edge_detect |= (gpio_is_event_detect_low(gpio_num_))           ? GPIOEdgeDetectLow          : GPIOEdgeDetectNone;
    edge_detect |= (gpio_is_event_detect_async_rising(gpio_num_))  ? GPIOEdgeDetectAsyncRising  : GPIOEdgeDetectNone;
    edge_detect |= (gpio_is_event_detect_async_falling(gpio_num_)) ? GPIOEdgeDetectAsyncFalling : GPIOEdgeDetectNone;

    return edge_detect;
}

void GPIODevice::GPIODeviceImpl::setEdgeDetect(GPIOEdgeDetect edge_detect) {
    GPIOEDS eds;

    switch(edge_detect) {
        case GPIOEdgeDetectRising:
            eds = GPIOEDSRisingEdge;
            break;
        case GPIOEdgeDetectFalling:
            eds = GPIOEDSFallingEdge;
            break;
        case GPIOEdgeDetectHigh:
            eds = GPIOEDSHigh;
            break;
        case GPIOEdgeDetectLow:
            eds = GPIOEDSLow;
            break;
        case GPIOEdgeDetectAsyncRising:
            eds = GPIOEDSAsyncRisingEdge;
            break;
        case GPIOEdgeDetectAsyncFalling:
            eds = GPIOEDSAsyncFallingEdge;
            break;
        default:
            printf("Invalid value for GPIO edge detect: %d\n", edge_detect);
            break;
    }

    gpio_set_event_detect_trigger(gpio_num_, eds);
}
