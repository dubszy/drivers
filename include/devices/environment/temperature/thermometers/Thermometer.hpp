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

    /**
     * Read the temperature from the thermometer.
     *
     * Inheritors must implement this method.
     */
    virtual double readTempFromDevice_() = 0;

public:
    /**
     * Build a new instance of Thermometer
     *
     * @param scale: the scale to report the temperature in
     * @param decimalPrecision: precision to report the temperature in (1 for tenths, 2 for hundredths, etc.)
     */
    Thermometer(TemperatureScale scale, uint8_t decimalPrecision) {
        if (scale == ScaleInvalid) {
            scale_ = ScaleCelsius;
        } else {
            scale_ = scale;
        }
        precision_ = decimalPrecision;
    }

    /**
     * Pure virtual destructor
     */
    virtual ~Thermometer() = 0;

    /**
     * Get a TemperatureScale based on an exact match of a single name
     * in TemperatureScale.
     *
     * @return  a TemperatureScale that matches the scale provided; or
     *          ScaleInvalid if no match was found
     */
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

    /**
     * Get the current temperature from the thermometer. Because this
     * class acts as a proxy to the actual device, how the read is
     * performed is up to the implementation of the virtual method
     * readTempFromDevice_()
     */
    double getTemperature() {
        double c = readTempFromDevice_();
        double p = pow(10, precision_);

        // TODO: It might prove more useful to put these conversions in a utility class
        switch (scale_) {
            case ScaleCelsius:
                return (floor((c * p)) / p);
            case ScaleDelisle:
                return (floor((((100 - c) * 1.5) * p)) / p);
            case ScaleFahrenheit:
                return (floor((((c * 1.8) + 32) * p)) / p);
            case ScaleKelvin:
                return (floor(((c + 273.15) * p)) / p);
            case ScaleRankine:
                return (floor((((c + 273.15) * 1.8) * p)) / p);
            case ScaleReaumur:
                return (floor(((c * 0.8) * p)) / p);
            case ScaleRomer:
                return (floor((((c * (21/40)) + 7.5) * p)) / p);
            default:
                return INVALID_TEMP_SCALE;
        }
    }

    /**
     * Get the temperature scale.
     *
     * @return  the value of this.scale_
     */
    TemperatureScale getScale() { return scale_; }

    /**
     * Set the temperature scale.
     *
     * @param scale: the scale to set for this
     */
    void setScale(TemperatureScale scale) { scale_ = scale; }

    /**
     * Get the temperature scale as a human-readable string.
     *
     * @return  the value of this.scale_ transformed into a
     *          human-readable string
     */
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
};

#endif /* _THERMOMETER_HPP_ */
