#include "PowerCapabilities.h"

using namespace std;

PowerCapabilities PowerCapabilities::operator<<(const SYSTEM_POWER_CAPABILITIES& obj)
{
	cout << int(obj.ProcessorThrottle)<< endl;
	cout << int(obj.ProcessorMinThrottle) << endl;
	//cout << obj.Proce << endl;
	cout << int(obj.ProcessorMaxThrottle) << endl;


	return *this;
}

PowerCapabilities PowerCapabilities::operator<<(const bool& obj)
{
	if (obj == true)
		cout << "True";
	else
		cout << "False";
	return *this;
}
