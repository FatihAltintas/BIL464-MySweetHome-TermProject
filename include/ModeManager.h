#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <string>
#include <iostream>



enum ModeType {
    MODE_NORMAL,
    MODE_EVENING, 
    MODE_PARTY,
    MODE_CINEMA
};

enum SystemStateType {
    STATE_NORMAL,
    STATE_HIGH_PERF,
    STATE_LOW_POWER,
    STATE_SLEEP
};


std::string modeToString(ModeType m);

#endif