#ifndef SENSORS_H
#define SENSORS_H

#include "Device.h"
#include <iostream>
#include <string>

// --- 1. Cihaz Siniflari (Sensors) ---

class SmokeDetector : public Device {
public:
    SmokeDetector(int i); // Constructor
    virtual ~SmokeDetector();

    // Prototype (REQ10)
    Device* clone() const;

    // Islevler
    void operate();
    void triggerAlarm(); // Ozel fonksiyon
    
    // Override Edilenler
    void displayStatus();
    bool isCritical() const; // Dedektorler kapatilamaz!
};

class GasDetector : public Device {
public:
    GasDetector(int i); // Constructor
    virtual ~GasDetector();

    // Prototype
    Device* clone() const;

    // Islevler
    void operate();
    
    // Override Edilenler
    void displayStatus();
    bool isCritical() const;
};

// --- 2. Fabrika Siniflari (Abstract Factory Pattern) ---

class DetectorFactory {
public:
    virtual ~DetectorFactory() {}
    virtual Device* createSmokeDetector(int id) = 0;
    virtual Device* createGasDetector(int id) = 0;
};

class SecurityDeviceFactory : public DetectorFactory {
public:
    Device* createSmokeDetector(int id);
    Device* createGasDetector(int id);
};

#endif