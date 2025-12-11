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

    // Helper
    Device* getDevice(int id);

    // Cihaz Yonetimi
    void addDevice(Device* d);
    void removeDevice(int id); 
    
    // REQ10: Prototype
    void duplicateDevice(int index, int newId);
    
    // REQ11 & REQ7: Mod ve Durum Yonetimi
    void changeMode(ModeType newMode);
    
    // REQ12: Undo
    void restorePreviousMode();
    
    // Listeleme
    void listDevices();

    // REQ16: Taha'nin Acil Durum Senaryosu
    void callFireStation();
};

#endif
