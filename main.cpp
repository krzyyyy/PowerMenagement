#include <iostream>
#include <thread>
#include <vector>
#include "dataTypes.h"
#include <cstring>
#include <chrono>
#include <ctime>
#include <Windows.h>
#include <powrprof.h>
//#include <powerbase.h>

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



int main() {
	GUID *schemat = nullptr;
	auto ok_get = PowerGetActiveScheme(0, &schemat);
	auto ok_set = PowerSetActiveScheme(0, &GUID_MIN_POWER_SAVINGS);

	auto threads2 = vector <thread>(0);
	for(int i=0;i<8;++i)
		threads2.push_back(thread(loop));

	for (auto& th : threads2)
		th.join();
	auto ok_get2 = PowerSetActiveScheme(0, schemat);
	return 0;
}
