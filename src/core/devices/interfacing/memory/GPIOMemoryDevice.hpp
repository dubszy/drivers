#ifndef _GPIO_MEMORY_DEVICE_HPP_
#define _GPIO_MEMORY_DEVICE_HPP_

#include <core/GPIODevice.hpp>

class GPIODevice::GPIODeviceImpl {

private:
    int gpio_num_;
    static extern struct mem_block gpio;

public:
    GPIODeviceImpl(int gpio_num);

    virtual ~GPIODeviceImpl();

    int open();
    int close();

    GPIODirection getDirection() const;
    void setDirection(GPIODirection direction);
    GPIOValue getValue() const;
    void setValue(GPIOValue value);
    GPIOEdgeDetect getEdgeDetect() const;
    void setEdgeDetect(GPIOEdgeDetect edge_detect);
    GPIOPinMode getPinMode() const;
    void setPinMode(GPIOPinMode pin_mode);
};

#endif /* _GPIO_MEMORY_DEVICE_HPP_ */
