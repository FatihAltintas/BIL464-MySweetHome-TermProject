#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include "Device.h"
#include "Light.h"
#include "Tv.h"
#include "Camera.h"
// include "ConcreteDevices.h" <-- BUNU SILDIK, yerine asil dosyalari ekledik

class DeviceFactory {
public:
    static Device* createDevice(const string& type, const string& name, int id) {
        if (type == "Light") {
            return new Light(name, id);
        }
        else if (type == "Tv") {
            return new Tv(name, id);
        }
        else if (type == "Camera") {
            return new Camera(name, id);
        }
        return NULL;
    }
};

#endif