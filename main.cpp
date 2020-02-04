#include <iostream>
#include <thread>
#include <vector>
#include "dataTypes.h"
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
	POWER_INFORMATION_LEVEL InformationLevel = SystemPowerInformation;
    SYSTEM_POWER_POLICY powerInfo = SYSTEM_POWER_POLICY();
	PVOID OutputBuffer = PVOID();
	ULONG OutputBufferLength;
	POWER_DATA_ACCESSOR AccessFlags = POWER_DATA_ACCESSOR();
	UINT pwrSchame = UINT();
	PUINT number  = &pwrSchame;
	GUID g;
	LPWSTR guidstr = LPWSTR("{8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c}");
	CLSID ff;
	//wchar_t* clsid_str = L"{5C98B8E4-2B3D-12B1-ADE2-0000F86456B23}";
	/*CLSIDFromString(guidstr, &ff);
	auto ff = GetActivePwrScheme(number);*/
	//DWORD flag = PowerSettingAccessCheck( AccessFlags, );
 	NTSTATUS status = CallNtPowerInformation(SystemPowerPolicyDc, NULL, NULL, &powerInfo, sizeof(powerInfo));
	printPowerInfo(powerInfo);
	auto threads2 = vector <thread>(0);
	for(int i=0;i<4;++i)
		threads2.push_back(thread(loop));

	for (auto& th : threads2)
		th.join();
	return 0;
}
