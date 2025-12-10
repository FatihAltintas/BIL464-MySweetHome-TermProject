#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <string>
#include <iostream>

using namespace std;

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

inline string modeToString(ModeType m) {
    switch (m) {
        case MODE_NORMAL:  return "Normal";
        case MODE_EVENING: return "Evening";
        case MODE_PARTY:   return "Party";
        case MODE_CINEMA:  return "Cinema";
        default:           return "Unknown";
    }
}

#endif