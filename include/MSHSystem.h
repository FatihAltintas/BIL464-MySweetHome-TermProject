#ifndef MSHSYSTEM_H
#define MSHSYSTEM_H

#include "Device.h"
#include "StateCaretaker.h"
#include "HomeMemento.h"
#include <vector>
#include <string>

class MSHSystem {
private:
    std::vector<Device*> devices;
    StateCaretaker* caretaker;
    
    // GUNCELLEME: Elmar'in Enum'i yerine tekrar string kullaniyoruz (Bireysel Modul)
    std::string currentMode;

public:
    MSHSystem();
    ~MSHSystem();

    Device* getDevice(int id);
    void addDevice(Device* d);
    void removeDevice(int id);
    
    void duplicateDevice(int index, int newId);
    
    // GUNCELLEME: string alacak
    void changeMode(const std::string& newMode);
    
    void restorePreviousMode();
    void listDevices();
    void callFireStation();
};

#endif
