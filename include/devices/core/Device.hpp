#ifndef _DEVICE_HPP_
#define _DEVICE_HPP_

#include <string>

#include <system/system_context.h>

using namespace std;

class Device {

private:
    Device(const Device&);
    Device& operator=(const Device&);

protected:
	string name_;

public:
	Device(string name = "Device") : name_(name) {};

	string getName();
	void setName(string name);
};

#endif /* _DEVICE_HPP_ */
