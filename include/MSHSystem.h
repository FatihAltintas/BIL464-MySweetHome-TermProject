#ifndef MSHSYSTEM_H
#define MSHSYSTEM_H

#include "Device.h"
#include "StateCaretaker.h"
#include "HomeMemento.h"
#include "ModeManager.h" // ModeType tanimi icin gerekli
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
    
    // REQ10: Prototype (Klonlama)
    void duplicateDevice(int index, int newId);
    
    // REQ11 & REQ7: Mod ve Durum Yonetimi
    void changeMode(ModeType newMode);
    
    // REQ12: Undo (Geri Alma)
    void restorePreviousMode();
    
    // Listeleme
    void listDevices();

    // REQ16: Acil Durum
    void callFireStation();
};

#endif