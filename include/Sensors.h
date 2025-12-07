#ifndef SENSORS_H
#define SENSORS_H

#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

class SmokeDetector : public Device {
public:
    SmokeDetector(int i) : Device("Smoke Detector") {
        setId(i); 
    }

    Device* clone() const {
        return new SmokeDetector(*this);
    }

    void operate() {
        cout << "[SENSOR] Smoke Detector is scanning for smoke..." << endl;
    }

    void triggerAlarm() {
        cout << "!!! SMOKE DETECTED !!! ALARM TRIGGERED !!!" << endl;
    }
};

class GasDetector : public Device {
public:
    GasDetector(int i) : Device("Gas Detector") {
        setId(i);
    }

    Device* clone() const {
        return new GasDetector(*this);
    }

    void operate() {
        cout << "[SENSOR] Gas Detector is checking air quality..." << endl;
    }
};

class DetectorFactory {
public:
    virtual ~DetectorFactory() {}
    virtual Device* createSmokeDetector(int id) = 0;
    virtual Device* createGasDetector(int id) = 0;
};

class SecurityDeviceFactory : public DetectorFactory {
public:
    Device* createSmokeDetector(int id) {
        return new SmokeDetector(id);
    }

    Device* createGasDetector(int id) {
        return new GasDetector(id);
    }
};

#endif