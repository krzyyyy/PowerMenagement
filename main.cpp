#include <iostream>
#include <thread>
#include <vector>
#include "dataTypes.h"
#include <cstring>
#include <chrono>
#include <ctime>

using namespace std;
void loop() {
	auto start = std::chrono::system_clock::now();
	// Some computation here
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	double i = 0;
	do {
		i = i+1.;
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		//std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	} while (elapsed_seconds.count()<20.);
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
	GUID *schemat = nullptr;
	auto ok_get = PowerGetActiveScheme(0, &schemat);

	auto ok_set = PowerSetActiveScheme(0, &GUID_MIN_POWER_SAVINGS);
	
	auto threads2 = vector <thread>(0);
	for(int i=0;i<4;++i)
		threads2.push_back(thread(loop));

	for (auto& th : threads2)
		th.join();
	auto ok_get2 = PowerSetActiveScheme(0, schemat);
	return 0;
}
