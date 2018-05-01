#ifndef _IP_DEVICE_HPP_
#define _IP_DEVICE_HPP_

#include <core/types/ip_types.h>

#include "Device.hpp"

class IPDevice : public Device {

    private:
        IPAddress ipAddress;

    public:
        IPAddress getIP();
        void setIP(IPAddress ip);

        void ping();
};

#endif /* _IP_DEVICE_HPP_ */
