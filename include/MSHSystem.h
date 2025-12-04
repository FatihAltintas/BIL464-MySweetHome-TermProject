#ifndef MSHSYSTEM_H
#define MSHSYSTEM_H

#include "Device.h"
#include "StateCaretaker.h"
#include "HomeMemento.h"
#include "ModeManager.h" // Elmar'in Enumlarini taniyoruz
#include <vector>
#include <string>

class MSHSystem {
private:
    std::vector<Device*> devices;
    StateCaretaker* caretaker;
    
    // GUNCELLEME: Artik string degil ModeType tutuyoruz
    ModeType currentMode;

public:
    MSHSystem();
    ~MSHSystem();

    void addDevice(Device* d);
    void duplicateDevice(int index, int newId);

    // GUNCELLEME: Fonksiyon artik ModeType aliyor
    void changeMode(ModeType newMode);
    
    void restorePreviousMode();
    void listDevices();
};

#endif