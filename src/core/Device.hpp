#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

#include <core/system/system_context.h>

using namespace std;

class Device {

protected:
	string *name;

public:
	string *getName();
	void setName(string *name);
};

#endif /* DEVICE_HPP */
