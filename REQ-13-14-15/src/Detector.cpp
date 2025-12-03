#include "Detector.h"
#include <iostream>

// --- Smoke Detector ---
SmokeDetector::SmokeDetector(int id, const string& name) 
    : Device(name), smokeDetected(false) {
    this->id = id;
    this->state = ACTIVE; // Sensörler varsayılan olarak aktiftir
}

void SmokeDetector::setSmokeDetected(bool status) {
    bool oldStatus = smokeDetected;
    smokeDetected = status;
    
    if (status) {
        // Duman algılandıysa durumu FAILED veya özel bir alarm durumuna çekebiliriz
        // Ancak şimdilik sadece observer'ı uyarıyoruz.
        cout << "[ALERT] Smoke Detected on Sensor " << id << endl;
    }
    
    if (oldStatus != status) notifyObservers();
}

bool SmokeDetector::isSmokeDetected() const { return smokeDetected; }

Device* SmokeDetector::clone() const { return new SmokeDetector(*this); }

void SmokeDetector::operate() {
    cout << "[SmokeDetector] ID: " << id 
         << ", Name: " << name
         << ", Status: " << (smokeDetected ? "DANGER" : "Safe") 
         << ", State: " << (state == ACTIVE ? "Active" : "Inactive") << endl;
}

// --- Gas Detector ---
GasDetector::GasDetector(int id, const string& name) 
    : Device(name), gasDetected(false) {
    this->id = id;
    this->state = ACTIVE;
}

void GasDetector::setGasDetected(bool status) {
    bool oldStatus = gasDetected;
    gasDetected = status;
    if(status) cout << "[ALERT] Gas Leak Detected on Sensor " << id << endl;
    
    if (oldStatus != status) notifyObservers();
}

bool GasDetector::isGasDetected() const { return gasDetected; }

Device* GasDetector::clone() const { return new GasDetector(*this); }

void GasDetector::operate() {
    cout << "[GasDetector] ID: " << id 
         << ", Name: " << name
         << ", Status: " << (gasDetected ? "LEAK DETECTED" : "Safe") 
         << ", State: " << (state == ACTIVE ? "Active" : "Inactive") << endl;
}