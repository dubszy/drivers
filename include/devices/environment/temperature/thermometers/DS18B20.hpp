#ifndef _DS18B20_HPP_
#define _DS18B20_HPP_

#include <devices/environment/temperature/thermometers/Thermometer.hpp>
#include <devices/core/OneWireDevice.hpp>

#include <logger/c++/Logger.hpp>

class DS18B20 : public Thermometer, public OneWireDevice {

public:
    DS18B20(string name,
            TemperatureScale scale,
            uint8_t decimalPrecision,
            string deviceAddress);

    DS18B20(string name, string deviceAddress);

    string toString();

private:
    DS18B20(const DS18B20&);
    DS18B20& operator=(const DS18B20);

    float readTempFromDevice_();

    Logger *log = Logger::forClass<DS18B20>(LogLevelInfo);
};

#endif /* _DS18B20_HPP_ */
