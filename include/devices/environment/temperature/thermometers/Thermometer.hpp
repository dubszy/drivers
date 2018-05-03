#ifndef _THERMOMETER_HPP_
#define _THERMOMETER_HPP_

#include <math.h>

#include <devices/core/Device.hpp>

#define INVALID_TEMP_SCALE -10000

typedef enum {
    ScaleCelsius,
    ScaleDelisle,
    ScaleFahrenheit,
    ScaleKelvin,
    ScaleRankine,
    ScaleReaumur,
    ScaleRomer
} TemperatureScale;

class Thermometer : public Device {

private:
    Thermometer(const Thermometer&);
    Thermometer& operator=(const Thermometer&);

protected:
    TemperatureScale scale_;
    uint8_t precision_;

    virtual float readTempFromDevice_() = 0;

public:
    Thermometer(TemperatureScale scale = ScaleCelsius, uint8_t decimal_precision = 2)
      : scale_(scale), precision_(decimal_precision) {};

    virtual ~Thermometer();

    float getTemperature() {
        float c = readTempFromDevice_();
        int p = pow(10, precision_);

        switch (scale_) {
            case ScaleCelsius:
                return (floorf((c * p)) / p);
            case ScaleDelisle:
                return (floorf((((100 - c) * 1.5) * p)) / p);
            case ScaleFahrenheit:
                return (floorf((((c * 1.8) + 32) * p)) / p);
            case ScaleKelvin:
                return (floorf(((c + 273.15) * p)) / p);
            case ScaleRankine:
                return (floorf((((c + 273.15) * 1.8) * p)) / p);
            case ScaleReaumur:
                return (floorf(((c * 0.8) * p)) / p);
            case ScaleRomer:
                return (floorf((((c * (21/40)) + 7.5) * p)) / p);
            default:
                return INVALID_TEMP_SCALE;
        }
    }

    TemperatureScale getScale() { return scale_; }
    void setScale(TemperatureScale scale) { scale_ = scale; }
};

#endif /* _THERMOMETER_HPP_ */
