#ifndef GPIO_DEVICE_HPP
#define GPIO_DEVICE_HPP

#include <devices/core/peripherals/peripheral_gpio.h>
#include "Device.hpp"

class GPIODevice : Device {

private:
    GPIODevice(const GPIODevice&);
    GPIODevice& operator=(const GPIODevice&);

    ~GPIODevice();

    class GPIODeviceImpl;
    GPIODeviceImpl *p_impl_;

public:
    GPIODevice(string name, unsigned int gpio_num);

    GPIOPinMode getPinMode() const;
    void setPinMode(GPIOPinMode pin_mode);
    GPIOValue getValue() const;
    void setValue(GPIOValue value);
    int getEdgeDetect() const;
    void setEdgeDetect(GPIOEdgeDetect edge_detect);
};

#endif /* GPIO_DEVICE_HPP */
