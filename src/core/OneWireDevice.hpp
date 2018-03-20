#ifndef _ONE_WIRE_HPP_
#define _ONE_WIRE_HPP_

#include <stdint.h>

#include "Device.hpp"

typedef enum {
    OWFC_DS2401      = 0x01,
    OWFC_DS2411      = 0x01,
    OWFC_DS1990R     = 0x01,
    OWFC_DS2490A     = 0x01,
    OWFC_DS1991      = 0x02,
    OWFC_DS2404      = 0x04,
    OWFC_DS2405      = 0x05,
    OWFC_DS1993      = 0x06,
    OWFC_DS1992      = 0x08,
    OWFC_DS2502      = 0x09,
    OWFC_DS2703      = 0x09,
    OWFC_DS2704      = 0x09,
    OWFC_DS2505      = 0x0B,
    OWFC_DS2506      = 0x0F,
    OWFC_DS18S20     = 0x10,
    OWFC_DS2406      = 0x12,
    OWFC_DS2430A     = 0x14,
    OWFC_DS1954      = 0x16,
    OWFC_DS1957      = 0x16,
    OWFC_DS1963S     = 0x18,
    OWFC_DS1962      = 0x18,
    OWFC_DS1963L     = 0x1A,
    OWFC_DS2436      = 0x1B,
    OWFC_DS28E04_100 = 0x1C,
    OWFC_DS2423      = 0x1D,
    OWFC_DS2437      = 0x1E,
    OWFC_DS2409      = 0x1F,
    OWFC_DS2450      = 0x20,
    OWFC_DS1921      = 0x21,
    OWFC_DS1922      = 0x22,
    OWFC_DS2433      = 0x23,
    OWFC_DS1973      = 0x23,
    OWFC_DS2415      = 0x24,
    OWFC_DS2438      = 0x26,
    OWFC_DS2417      = 0x27,
    OWFC_DS18B20     = 0x28,
    OWFC_DS2408      = 0x29,
    OWFC_DS2890      = 0x2C,
    OWFC_DS2431      = 0x2D,
    OWFC_DS1972      = 0x2D,
    OWFC_DS2770      = 0x2E,
    OWFC_DS2760      = 0x30,
    OWFC_DS2720      = 0x31,
    OWFC_DS2780      = 0x32,
    OWFC_DS1961S     = 0x33,
    OWFC_DS2432      = 0x33,
    OWFC_DS2703      = 0x34,
    OWFC_DS2755      = 0x35,
    OWFC_DS2740      = 0x36,
    OWFC_DS1977      = 0x37,
    OWFC_DS2413      = 0x3A,
    OWFC_DS1825      = 0x3B,
    OWFC_MAX31826    = 0x3B,
    OWFC_DS2781      = 0x3D,
    OWFC_DS1923      = 0x41,
    OWFC_DS28EA00    = 0x42,
    OWFC_DS28EC20    = 0x43,
    OWFC_DS28E10     = 0x44,
    OWFC_DS2751      = 0x51,
    OWFC_EDS00XX     = 0x7E,
    OWFC_DS2490R     = 0x81,
    OWFC_DS2490B     = 0x81,
    OWFC_DS1425      = 0x82,
    OWFC_DS1982U     = 0x89,
    OWFC_DS1985U     = 0x8B,
    OWFC_DS1986U     = 0x8F,
    OWFC_mRS001      = 0xA0,
    OWFC_mVM001      = 0xA1,
    OWFC_mCM001      = 0xA2,
    OWFC_mTS017      = 0xA6,
    OWFC_mTC001      = 0xB1,
    OWFC_mAM001      = 0xB2,
    OWFC_mTC002      = 0xB3,
    OWFC_UVI         = 0xEE,
    OWFC_MH          = 0xEF,
    OWFC_BAE0910     = 0xFC,
    OWFC_BAE0911     = 0xFC,
    OWFC_LCD         = 0xFF
} OneWireFamilyCode;

class OneWireDevice : public Device {

private:
    OneWireDevice(const OneWireDevice&);
    OneWireDevice& operator=(const OneWireDevice);

    class OneWireDeviceImpl;
    OneWireDeviceImpl *p_impl_;

public:
    OneWireDevice(OneWireFamilyCode family_code, uint8_t *addr);

    virtual ~OneWireDevice();

    int read(char *buf, int length);
};

#endif /* _ONE_WIRE_HPP_ */
