#pragma once
#include <Windows.h>
#include <powerbase.h>
#include <powrprof.h>
#include <iostream>
class PowerPolicy
{
public:
	PowerPolicy operator <<(const SYSTEM_POWER_POLICY& obj);
	PowerPolicy operator <<(const bool& obj);
};

