#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <string>
#include <iostream>

using namespace std;

enum ModeType {
    MODE_NORMAL,
    MODE_NIGHT,
    MODE_PARTY,
    MODE_CINEMA
};

inline string modeToString(ModeType m) {
    switch (m) {
        case MODE_NORMAL: return "Normal";
        case MODE_NIGHT:  return "Night";
        case MODE_PARTY:  return "Party";
        case MODE_CINEMA: return "Cinema";
        default:          return "Unknown";
    }
}

#endif
