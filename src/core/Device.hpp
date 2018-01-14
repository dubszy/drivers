#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

using namespace std;

namespace Core {

	class Device {

	protected:
		string *name;

	public:
		string *getName();
		void setName(string *name);
	};
}

#endif /* DEVICE_HPP */
