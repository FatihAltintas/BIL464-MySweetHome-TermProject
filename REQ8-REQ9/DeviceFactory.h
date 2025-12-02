#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include "ConcreteDevices.h"

// REQ8.3: Factory Pattern
class DeviceFactory {
public:
    static Device* createDevice(int type) {
        switch (type) {
        case 1: return new Light("Salon Isigi");
        case 2: return new Camera("Guvenlik Kamerasi");
        case 3: return new ExternalLightAdapter("Dis Cephe Isigi (Adapter)");
        default: return NULL;
        }
    }
};

#endif