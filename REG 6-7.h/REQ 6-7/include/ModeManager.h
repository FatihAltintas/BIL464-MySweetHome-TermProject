#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include "DeviceManager.h"

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

// REQ7: Mod yönetimi
class ModeManager {
    ModeType currentMode;

public:
    ModeManager() : currentMode(MODE_NORMAL) {}

    ModeType getCurrentMode() const { return currentMode; }
    string getModeName() const { return modeToString(currentMode); }

    void setMode(ModeType m, DeviceManager& dm) {
        if (m == currentMode) {
            cout << "  Zaten bu moddasiniz: " << getModeName() << endl;
            return;
        }
        currentMode = m;
        applyMode(dm);
        cout << "  Mod degistirildi: " << getModeName() << endl;
    }

    // Cihaz davranışları modlara göre
    void applyMode(DeviceManager& dm) {
        const vector<Device*>& devs = dm.getDevices();

        for (size_t i = 0; i < devs.size(); ++i) {
            Device* d = devs[i];
            string n = d->getName();

            if (currentMode == MODE_NORMAL) {
                // Kullanıcının bıraktığı gibi kalsın
            }
            else if (currentMode == MODE_NIGHT) {
                // Night: sadece LivingRoomLight ACTIVE olsun
                if (n == "LivingRoomLight") {
                    d->powerOn();
                } else {
                    d->powerOff();
                }
            }
            else if (currentMode == MODE_PARTY) {
                // Party: tüm cihazlar ACTIVE
                d->powerOn();
            }
            else if (currentMode == MODE_CINEMA) {
                // Cinema: sadece TV'ler ACTIVE
                if (n.find("TV") != string::npos) {
                    d->powerOn();
                } else {
                    d->powerOff();
                }
            }
        }
    }
};

#endif
