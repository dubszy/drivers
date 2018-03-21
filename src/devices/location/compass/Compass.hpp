#ifndef _COMPASS_HPP_
#define _COMPASS_HPP_

#include <math.h>

#include <core/Device.hpp>

#define GAUSS_TO_MICROTESLA 100

typedef struct {
    float degrees;
    string name;
    string abbreviation;
} CardinalDirection;

typedef struct {
    float x;
    float y;
    float z;
    float heading;
    float aod;
} CompassMeasurement;

class Compass : public Device {

private:
    Compass(const Compass&);
    Compass& operator=(const Compass&);

    CardinalDirection *directions_;
    uint8_t directions_count_;

    virtual CompassMeasurement readMeasurementFromDevice_(bool correction) = 0;

public:
    Compass(CardinalDirection *directions)
      : directions_(directions), directions_count_((sizeof(directions) / sizeof(CardinalDirection) / 8)) {};

    virtual ~Compass();

    void setCardinalDirections(CardinalDirection *directions) {
        directions_ = directions;
        directions_count_ = (sizeof(directions) / sizeof(CardinalDirection) / 8);
    }

    CardinalDirection *getCardinalDirections() const {
        return directions_;
    }

    uint8_t getCardinalDirectionsCount() const {
        return directions_count_;
    }

    float getHeading(bool correction, float offset, uint8_t precision) const {
        CompassMeasurement m = readMeasurementFromDevice_(correction);
        int p = pow(10, precision);
        return (roundf(((m.heading + offset) * p)) / p);
    }

    CardinalDirection nearestCardinalDirection(bool correction, float offset, uint8_t precision) const {
        if (directions_count_ == 0) {
            printf("There are no cardinal directions assigned to this compass\n");
            return NULL;
        }
        float heading = getHeading(correction, offset, precision);
        int index = (int)roundf(heading/(360/directions_count_));
        return directions_[(index == directions_count_) ? 0 : index];
    }

    CardinalDirection nearestCardinalDirection(bool correction, float offset) {
        return nearestCardinalDirection(correction, offset, 2);
    }
};

#endif /* _COMPASS_HPP_ */
