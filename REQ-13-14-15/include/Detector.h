#ifndef DETECTOR_H
#define DETECTOR_H

#include "Device.h"

// --- Duman Dedektörü ---
class SmokeDetector : public Device {
private:
    bool smokeDetected;
public:
    SmokeDetector(int id, const string& name);
    
    void setSmokeDetected(bool status);
    bool isSmokeDetected() const;
    
    Device* clone() const override;
    void operate() override; // printStatus yerine operate
};

// --- Gaz Dedektörü ---
class GasDetector : public Device {
private:
    bool gasDetected;
public:
    GasDetector(int id, const string& name);
    
    void setGasDetected(bool status);
    bool isGasDetected() const;
    
    Device* clone() const override;
    void operate() override;
};

#endif