#ifndef MSHSYSTEM_H
#define MSHSYSTEM_H

#include "Device.h"
#include "StateCaretaker.h"
#include "HomeMemento.h"
#include "ModeManager.h"
#include <vector>
#include <string>

class MSHSystem {
private:
    std::vector<Device*> devices;
    StateCaretaker* caretaker;
    ModeType currentMode;

public:
    MSHSystem();
    ~MSHSystem();
    Device* getDevice(int id);

    void addDevice(Device* d);
    void removeDevice(int id); 
    void duplicateDevice(int index, int newId);
    void changeMode(ModeType newMode);
    void restorePreviousMode();
    void listDevices();

    void callFireStation();
};

#endif