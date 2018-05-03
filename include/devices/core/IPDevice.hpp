#ifndef _IP_DEVICE_HPP_
#define _IP_DEVICE_HPP_

#include <types/ip_types.h>

#include "Device.hpp"

class IPDevice : public Device {

public:
    IPDevice(string name, IPAddress ipAddress)
      : ipAddress_(ipAddress), Device(std::move(name)) {}

    IPAddress getIP();
    void setIP(IPAddress ip);

    void ping();

private:
    IPAddress ipAddress_;
};

#endif /* _IP_DEVICE_HPP_ */
