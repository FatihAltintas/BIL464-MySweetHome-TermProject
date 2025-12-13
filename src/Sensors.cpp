#include "Sensors.h"
#include "Logger.h"

using namespace std;

// ==========================================
// SMOKE DETECTOR IMPLEMENTATION
// ==========================================

SmokeDetector::SmokeDetector(int i) : Device("Smoke Detector") {
    setId(i);
    // Dedektorler varsayilan olarak acik baslar
    state = ACTIVE; 
}

SmokeDetector::~SmokeDetector() {}

Device* SmokeDetector::clone() const {
    return new SmokeDetector(*this);
}

void SmokeDetector::operate() {
    Logger::getInstance()->log("[SENSOR] Smoke Detector is active. Scanning air particles...");
}

void SmokeDetector::triggerAlarm() {
    Logger::getInstance()->log("!!! CRITICAL: SMOKE DETECTED! ALARM TRIGGERED !!!");
    cout << "\n!!! WEE-WOO WEE-WOO: SMOKE ALARM !!!\n" << endl;
}

void SmokeDetector::displayStatus() {
    Device::displayStatus();
    cout << "   -> Detail: Type=Optical Sensor, Battery=98%" << endl;
}

// Dedektorler elle kapatilamaz (Guvenlik geregi)
bool SmokeDetector::isCritical() const {
    return true; 
}


// ==========================================
// GAS DETECTOR IMPLEMENTATION
// ==========================================

GasDetector::GasDetector(int i) : Device("Gas Detector") {
    setId(i);
    state = ACTIVE;
}

GasDetector::~GasDetector() {}

Device* GasDetector::clone() const {
    return new GasDetector(*this);
}

void GasDetector::operate() {
    Logger::getInstance()->log("[SENSOR] Gas Detector is active. Checking CO levels...");
}

void GasDetector::displayStatus() {
    Device::displayStatus();
    cout << "   -> Detail: Type=Carbon Monoxide, Level=Normal" << endl;
}

bool GasDetector::isCritical() const {
    return true;
}


// ==========================================
// FACTORY IMPLEMENTATION
// ==========================================

Device* SecurityDeviceFactory::createSmokeDetector(int id) {
    Logger::getInstance()->log("Factory created a new Smoke Detector (ID: " + to_string(id) + ")");
    return new SmokeDetector(id);
}

Device* SecurityDeviceFactory::createGasDetector(int id) {
    Logger::getInstance()->log("Factory created a new Gas Detector (ID: " + to_string(id) + ")");
    return new GasDetector(id);
}