#ifndef SENSORS_H
#define SENSORS_H

#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

// --- DUMAN SENSORU ---
class SmokeDetector : public Device {
public:
    SmokeDetector(int i) : Device("Smoke Detector") {
        setId(i); // Yeni Device.h uyumu
    }

    Device* clone() const {
        return new SmokeDetector(*this);
    }

    void operate() {
        cout << "[SENSOR] Smoke Detector is scanning for smoke..." << endl;
    }

    // Emre'nin ekstra fonksiyonu varsa buraya eklenir
    void triggerAlarm() {
        cout << "!!! SMOKE DETECTED !!! ALARM TRIGGERED !!!" << endl;
    }
};

// --- GAZ SENSORU ---
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

// --- FACTORY PATTERN (Emre'nin Fabrikası) ---
// Abstract Factory
class DetectorFactory {
public:
    virtual ~DetectorFactory() {}
    virtual Device* createSmokeDetector(int id) = 0;
    virtual Device* createGasDetector(int id) = 0;
};

// Concrete Factory
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