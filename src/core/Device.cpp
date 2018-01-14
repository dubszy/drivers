#include "Device.hpp"

using namespace Core;

/**
 * Get the name for this device
 * This is purely informational; does not communicate with any device
 */
string *Device::getName() {
	return name;
}

/**
 * Set the name for this device
 * This is purely informational; does not communicate with any device
 */
void Device::setName(string *name) {
	this->name = name;
}
