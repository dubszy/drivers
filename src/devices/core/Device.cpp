#include <devices/core/Device.hpp>

/**
 * Get the name for this device
 * This is purely informational; does not communicate with any device
 */
string Device::getName() {
	return name_;
}

/**
 * Set the name for this device
 * This is purely informational; does not communicate with any device
 */
void Device::setName(string name) {
	name_ = name;
}
