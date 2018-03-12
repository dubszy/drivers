#include "IPDevice.hpp"

IPAddress IPDevice::getIP() {
    return ipAddress;
}

void IPDevice::setIP(IPAddress ip) {
    ipAddress = ip;
}
