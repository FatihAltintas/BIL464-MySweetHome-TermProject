#include "ModeManager.h"

using namespace std;


string modeToString(ModeType m) {
    switch (m) {
        case MODE_NORMAL:  return "Normal";
        case MODE_EVENING: return "Evening";
        case MODE_PARTY:   return "Party";
        case MODE_CINEMA:  return "Cinema";
        default:           return "Unknown";
    }
}