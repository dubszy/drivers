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
    ScaleRomer,
    ScaleInvalid
} TemperatureScale;

class Thermometer {

private:
    Thermometer(const Thermometer&);
    Thermometer& operator=(const Thermometer&);

protected:
    TemperatureScale scale_;
    uint8_t precision_;

    virtual float readTempFromDevice_() = 0;

public:
    Thermometer(TemperatureScale scale, uint8_t decimal_precision) {
        if (scale == 0 || scale == ScaleInvalid) {
            scale_ = ScaleCelsius;
        }
        if (decimal_precision == 0) {
            decimal_precision = 2;
        }
    }

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

    string getScaleAsString() {
        switch (scale_) {
            case ScaleCelsius:
                return "Celsius";
            case ScaleDelisle:
                return "Delisle";
            case ScaleFahrenheit:
                return "Fahrenheit";
            case ScaleKelvin:
                return "Kelvin";
            case ScaleRankine:
                return "Rankine";
            case ScaleReaumur:
                return "Reamur";
            case ScaleRomer:
                return "Romer";
            default:
                return "Invalid Scale";
        }
    }

    static TemperatureScale getScaleFromString(string scale) {
        if (scale == "ScaleCelsius") {
            return ScaleCelsius;
        } else if (scale == "ScaleDelisle") {
            return ScaleDelisle;
        } else if (scale == "ScaleFahrenheit") {
            return ScaleFahrenheit;
        } else if (scale == "ScaleKelvin") {
            return ScaleKelvin;
        } else if (scale == "ScaleRankine") {
            return ScaleRankine;
        } else if (scale == "ScaleReamur") {
            return ScaleReaumur;
        } else if (scale == "ScaleRomer") {
            return ScaleRomer;
        }
        return ScaleInvalid;
    }

    void setScale(TemperatureScale scale) { scale_ = scale; }
};

#endif /* _THERMOMETER_HPP_ */
