#include "PowerPolicy.h"

using namespace std;

PowerPolicy PowerPolicy::operator<<(const SYSTEM_POWER_POLICY& obj)
{
	cout << "Revision  " << obj.Revision << endl;
	cout << "Reserved  " << obj.Reserved << endl;
	cout << "IdleTimeout  " << obj.IdleTimeout << endl;
	cout << "IdleSensitivity  " << obj.IdleSensitivity << endl;
	cout << "Spare2[0]  " << obj.Spare2[0] << endl;
	cout << "Spare2[1]  " << obj.Spare2[1] << endl;
	cout << "WinLogonFlags  " << obj.WinLogonFlags << endl;
	cout << "Spare3  " << obj.Spare3 << endl;
	cout << "DozeS4Timeout  " << obj.DozeS4Timeout << endl;
	cout << "BroadcastCapacityResolution  " << obj.BroadcastCapacityResolution << endl;
	cout << "Revision  " << obj.Revision << endl;
	cout << "FanThrottleTolerance  " << int(obj.FanThrottleTolerance) << endl;
	cout << "ForcedThrottle  " << int(obj.ForcedThrottle) << endl;
	cout << "MinThrottle  " << int(obj.MinThrottle) << endl;
	cout << "OptimizeForPower  "; *this << obj.OptimizeForPower; cout << endl;
	cout << "OverThrottled.Action  " << obj.OverThrottled.Action << endl;
	cout << "OverThrottled.EventCode  " << obj.OverThrottled.EventCode << endl;
	cout << "OverThrottled.Flags  " << obj.OverThrottled.Flags << endl;
	cout << "DynamicThrottle  " << int(obj.DynamicThrottle) << endl;
	cout << "VideoTimeout  " << int(obj.VideoTimeout) << endl;
	return *this;
}

PowerPolicy PowerPolicy::operator<<(const bool& obj)
{
	if (obj == true)
		cout << "True";
	else 
		cout << "False";
	return *this;
}
