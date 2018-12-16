#ifndef _COMPASS_HPP_
#define _COMPASS_HPP_

#include <math.h>
#include <vector>

#include <devices/core/Device.hpp>

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

    vector<CardinalDirection> directions_;

protected:

    virtual CompassMeasurement readMeasurementFromDevice_(bool correction) = 0;

public:
    /**
     * Build a new instance of Compass
     *
     * @param directions:  a vector of CardinalDirections to use for
     *                     displaying human-readable measurements
     */
    Compass(vector<CardinalDirection> directions)
      : directions_(directions) {};

    /**
     * Pure virtual destructor.
     */
    virtual ~Compass() = 0;

    /**
     * Get the cardinal directions assigned to this.
     */
    vector<CardinalDirection> getCardinalDirections() const {
        return directions_;
    }

    /**
     * Set the cardinal directions for this.
     */
    void setCardinalDirections(vector<CardinalDirection> directions) {
        directions_ = directions;
    }

    /**
     * Get current heading in degrees. Because this class acts as a
     * proxy to the actual device, how the read is performed is up to
     * the implementation of the virtual method
     * readMeasurementFromDevice_()
     */
    double getHeading(bool correction, float offset, uint8_t precision) const {
        CompassMeasurement m = readMeasurementFromDevice_(correction);
        int p = pow(10, precision);
        return (round(((m.heading + offset) * p)) / p);
    }

    /**
     * Determine the nearest cardinal direction from the current
     * heading.
     *
     * @param correction:  whether to use the compass's internal
     *                     correction functionality (if the compass
     *                     supports it)
     * @param offset:  offset to add to the heading returned from the
     *                 compass (in degrees)
     * @param precision:  decimal precision to use (1 for tenths, 2 for
     *                    hundredths, etc.)
     *
     * @return  the nearest cardinal direction as a CardinalDirection
     */
    CardinalDirection nearestCardinalDirection(bool correction, float offset, uint8_t precision) const {
        if (directions_.size() == 0) {
            printf("There are no cardinal directions assigned to this compass\n");
            return NULL;
        }
        double heading = getHeading(correction, offset, precision);

        long index = lround(heading/(360/directions_.size()));

        return directions_[(index == directions_.size()) ? 0 : index];
    }

    /**
     * Determine the nearest cardinal direction from the current
     * heading.
     *
     * @param correction:  whether to use the compass's internal
     *                     correction functionality (if the compass
     *                     supports it)
     * @param offset:  offset to add to the heading returned from the
     *                 compass (in degrees)
     *
     * @return  the nearest cardinal direction as a CardinalDirection
     *          with a decimal precision of 2
     */
    CardinalDirection nearestCardinalDirection(bool correction, float offset) {
        return nearestCardinalDirection(correction, offset, 2);
    }
};

#endif /* _COMPASS_HPP_ */
