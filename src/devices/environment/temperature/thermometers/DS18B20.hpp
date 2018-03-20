#ifndef _DS18B20_HPP_
#define _DS18B20_HPP_

#include "Thermometer.hpp"
#include <core/OneWireDevice.hpp>

class DS18B20 : public Thermometer, public OneWireDevice {

private:
    DS18B20(const DS18B20&);
    DS18B20& operator=(const DS18B20);

    float readTempFromDevice_();

public:
    DS18B20(TemperatureScale scale = ScaleCelsius, uint8_t decimal_precision = 2, uint8_t *device_addr);
};
