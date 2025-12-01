#ifndef MSHSYSTEM_H
#define MSHSYSTEM_H

#include "Device.h"
#include "StateCaretaker.h"
#include "HomeMemento.h"
#include <vector>

class MSHSystem {
private:
    std::vector<Device*> devices;
    StateCaretaker* caretaker;
    std::string currentMode;

public:
    MSHSystem();
    ~MSHSystem();

    void addDevice(Device* d);
    
    void duplicateDevice(int sourceDeviceId, int newId);

    void changeMode(const std::string& newMode);
    void restorePreviousMode();

    void listDevices();
};

#endif