#include <iostream>
#include <thread>
#include <vector>
#include "dataTypes.h"
#include "PowerPolicy.h"
#include "PowerCapabilities.h"
#include <cstring>

using namespace std;
void loop() {
	double i = 0;
	while (true) {
		i = i+1.;
	}
}


void printPowerInfo(const SYSTEM_POWER_POLICY& powerInfo) {
	auto boolToStr = [](const bool& var) {
		if (var == true)
			return "TRUE";
		return "FALSE";
	};
	cout << "Revision  " << powerInfo.Revision << endl;
	cout << "FanThrottleTolerance  " << powerInfo.FanThrottleTolerance << endl;
	cout << "ForcedThrottle  " << powerInfo.ForcedThrottle << endl;
	cout << "MinThrottle  " << int(powerInfo.MinThrottle) << endl;
	cout << "OptimizeForPower  " << boolToStr(powerInfo.OptimizeForPower) << endl;
	cout << "OverThrottled.Action  " << powerInfo.OverThrottled.Action << endl;
	cout << "OverThrottled.EventCode  " << powerInfo.OverThrottled.EventCode << endl;
	cout << "OverThrottled.Flags  " << powerInfo.OverThrottled.Flags << endl;
	cout << "DynamicThrottle  " << int(powerInfo.DynamicThrottle) << endl;

}

int main() {
    SYSTEM_POWER_POLICY powerInfoBefore = SYSTEM_POWER_POLICY(), powerInfoAfter = SYSTEM_POWER_POLICY();
 	NTSTATUS status = CallNtPowerInformation(SystemPowerPolicyDc, NULL, NULL, &powerInfoBefore, sizeof(powerInfoBefore));
 	//NTSTATUS status2 = CallNtPowerInformation(SystemPowerCapabilities, NULL, NULL, &capabilitysFlags, sizeof(capabilitysFlags));
	PowerPolicy powerPolycy;
	PowerCapabilities powerCapability;
	powerPolycy << powerInfoBefore;
	powerInfoBefore.MinThrottle = 100;
	NTSTATUS status2 = CallNtPowerInformation(SystemPowerPolicyDc, & powerInfoBefore, sizeof(powerInfoBefore), nullptr, 0);
	NTSTATUS status4 = CallNtPowerInformation(SystemPowerPolicyDc, NULL, NULL, &powerInfoBefore, sizeof(powerInfoBefore));
	cout << endl << endl;
	powerPolycy << powerInfoBefore;
	cout << endl << endl;
	powerInfoBefore.MinThrottle = 100;
	NTSTATUS status3 = CallNtPowerInformation(SystemPowerPolicyDc, &powerInfoBefore, sizeof(powerInfoBefore), nullptr, 0);
	cout << endl << endl;
	powerPolycy << powerInfoAfter;

	auto threads2 = vector <thread>(0);
	for(int i=0;i<4;++i)
		threads2.push_back(thread(loop));

	for (auto& th : threads2)
		th.join();
	return 0;
}
