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

    void addDevice(Device* d);
    void removeDevice(int id); // Fatih icin eklemistik
    void duplicateDevice(int index, int newId);
    void changeMode(ModeType newMode);
    void restorePreviousMode();
    void listDevices();

    // Taha (REQ16) icin ekledigimiz satir:
    void callFireStation();
};

#endif