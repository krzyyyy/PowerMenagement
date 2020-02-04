#pragma once
#include <Windows.h>
#include <powerbase.h>
#include <powrprof.h>

//extern "C" {
//#include <powerbase.h>
//
//}
//#pragma comment(lib, "PowrProf.lib")


struct MY_SYSTEM_POWER_POLICY {
    DWORD               Revision;
    POWER_ACTION_POLICY PowerButton;
    POWER_ACTION_POLICY SleepButton;
    POWER_ACTION_POLICY LidClose;
    SYSTEM_POWER_STATE  LidOpenWake;
    DWORD               Reserved;
    POWER_ACTION_POLICY Idle;
    DWORD               IdleTimeout;
    BYTE                IdleSensitivity;
    BYTE                DynamicThrottle;
    BYTE                Spare2[2];
    SYSTEM_POWER_STATE  MinSleep;
    SYSTEM_POWER_STATE  MaxSleep;
    SYSTEM_POWER_STATE  ReducedLatencySleep;
    DWORD               WinLogonFlags;
    DWORD               Spare3;
    DWORD               DozeS4Timeout;
    DWORD               BroadcastCapacityResolution;
    SYSTEM_POWER_LEVEL  DischargePolicy[NUM_DISCHARGE_POLICIES];
    DWORD               VideoTimeout;
    BOOLEAN             VideoDimDisplay;
    DWORD               VideoReserved[3];
    DWORD               SpindownTimeout;
    BOOLEAN             OptimizeForPower;
    BYTE                FanThrottleTolerance;
    BYTE                ForcedThrottle;
    BYTE                MinThrottle;
    POWER_ACTION_POLICY OverThrottled;
};