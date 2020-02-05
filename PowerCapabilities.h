#pragma once
#include <Windows.h>
#include <powerbase.h>
#include <powrprof.h>
#include <iostream>

class PowerCapabilities
{
public:
	PowerCapabilities operator <<(const SYSTEM_POWER_CAPABILITIES& obj);
	PowerCapabilities operator <<(const bool& obj);
};

