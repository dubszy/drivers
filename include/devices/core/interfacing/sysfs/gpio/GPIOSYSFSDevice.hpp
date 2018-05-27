#ifndef _GPIO_SYSFS_DEVICE_HPP_
#define _GPIO_SYSFS_DEVICE_HPP_

#include <devices/core/GPIODevice.hpp>

class GPIODevice::GPIODeviceImpl {

private:
    int gpio_num_;

public:
    GPIODeviceImpl(unsigned int gpio_num);

    virtual ~GPIODeviceImpl();

    GPIOPinMode getPinMode() const;
    void setPinMode(GPIOPinMode pin_mode);
    GPIOValue getValue() const;
    void setValue(GPIOValue value);
    GPIOEdgeDetect getEdgeDetect() const;
    void setEdgeDetect(GPIOEdgeDetect edge_detect);
};

#endif /* _GPIO_SYSFS_DEVICE_HPP_ */
