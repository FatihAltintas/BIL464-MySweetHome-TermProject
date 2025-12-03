#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "DeviceManager.h"

// Mod tipleri (REQ7)
enum ModeType {
    MODE_NORMAL,
    MODE_NIGHT,
    MODE_PARTY,
    MODE_CINEMA
};

inline std::string modeToString(ModeType m) {
    switch (m) {
        case MODE_NORMAL: return "Normal";
        case MODE_NIGHT:  return "Night";
        case MODE_PARTY:  return "Party";
        case MODE_CINEMA: return "Cinema";
        default:          return "Unknown";
    }
}

class ModeManager {
    ModeType currentMode;

public:
    ModeManager() : currentMode(MODE_NORMAL) {}

    ModeType getCurrentMode() const {
        return currentMode;
    }

    std::string getModeName() const {
        return modeToString(currentMode);
    }

    void setMode(ModeType m, DeviceManager& dm) {
        if (m == currentMode) {
            std::cout << "  Zaten bu moddasiniz: " << getModeName() << std::endl;
            return;
        }
        currentMode = m;
        applyMode(dm);
        std::cout << "  Mod degistirildi: " << getModeName() << std::endl;
    }

    // REQ7: Modlara gore davranis
    void applyMode(DeviceManager& dm) {
        const std::vector<Device*>& devs = dm.getDevices();

        for (size_t i = 0; i < devs.size(); ++i) {
            Device* d = devs[i];
            std::string n = d->getName();

            if (currentMode == MODE_NORMAL) {
                // Normal: kullanicinin biraktigi gibi
            }
            else if (currentMode == MODE_NIGHT) {
                // Night: sadece LivingRoomLight acik kalsin
                if (n == "LivingRoomLight") {
                    d->powerOn();
                } else {
                    d->powerOff();
                }
            }
            else if (currentMode == MODE_PARTY) {
                // Party: tum cihazlari ac
                d->powerOn();
            }
            else if (currentMode == MODE_CINEMA) {
                // Cinema: sadece TV acik kalsin
                if (n.find("TV") != std::string::npos) {
                    d->powerOn();
                } else {
                    d->powerOff();
                }
            }
        }
    }
};

#endif

