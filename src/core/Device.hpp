#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

#include <core/system/system_context.h>

using namespace std;

class Device {

private:
    Device(const Device&);
    Device& operator=(const Device&);

protected:
	string name_;

public:
	Device(string name) : name_(name) {};

	string getName();
	void setName(string name_);
};

#endif /* DEVICE_HPP */
