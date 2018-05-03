#include <devices/core/IPDevice.hpp>

IPAddress IPDevice::getIP() {
    return ipAddress_;
}

void IPDevice::setIP(IPAddress ip) {
    ipAddress_ = ip;
}
