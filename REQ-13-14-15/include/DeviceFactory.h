#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include "Device.h"
#include "Light.h"
#include "Camera.h"
#include "Detector.h"
#include "TV.h"
#include "Alarm.h"
#include <string>

class DeviceFactory {
public:
    static Device* createDevice(const string& type, int id) {
        if (type == "Light") {
            return new Light(id, "Default Light", 0, "White");
        } 
        else if (type == "Camera") {
            return new Camera(id, "Security Cam", 1080);
        }
        else if (type == "SmokeDetector") {
            return new SmokeDetector(id, "Smoke Sensor");
        }
        else if (type == "GasDetector") {
            return new GasDetector(id, "Gas Sensor");
        }
        else if (type == "TV") {
            return new TV(id, "Living Room TV");
        }
        else if (type == "Alarm") {
            return new Alarm(id);
        }
        return NULL;
    }
};

#endif