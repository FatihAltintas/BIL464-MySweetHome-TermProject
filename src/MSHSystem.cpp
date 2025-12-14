#include "MSHSystem.h"
#include "Logger.h"      // Loglama sistemi
#include "HomeMemento.h" // Memento pattern

#include <iostream>
#include <vector>

using namespace std;

// YARDIMCI FONKSIYON: Enum -> String Cevirimi
// ModeManager.h icindeki 'modeToString' fonksiyonunu da kullanabilirdik
// ama burada loglama icin yerel bir cozum de yeterlidir.
string mshModeToString(ModeType mode) {
    switch (mode) {
        case MODE_NORMAL:  return "NORMAL";
        case MODE_EVENING: return "EVENING (Night)";
        case MODE_PARTY:   return "PARTY";
        case MODE_CINEMA:  return "CINEMA";
        default:           return "UNKNOWN";
    }
}

// Constructor
MSHSystem::MSHSystem() {
    caretaker = new StateCaretaker();
    currentMode = MODE_NORMAL; 
    Logger::getInstance()->log("MSH System Constructor called.");
}

// Destructor
MSHSystem::~MSHSystem() {
    if (caretaker) delete caretaker;
    
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]) delete devices[i];
    }
    devices.clear();
    Logger::getInstance()->log("MSH System Destructor called. Memory cleaned.");
}

// ID ile Cihaz Bulma
Device* MSHSystem::getDevice(int id) {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getId() == id) {
            return devices[i];
        }
    }
    return NULL;
}

// Cihaz Ekleme
void MSHSystem::addDevice(Device* d) {
    devices.push_back(d);
    Logger::getInstance()->log("Device added: " + d->getName() + " (ID: " + to_string(d->getId()) + ")");
}

// Cihaz Silme (REQ8)
void MSHSystem::removeDevice(int id) {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getId() == id) {
            string name = devices[i]->getName();
            delete devices[i]; 
            devices.erase(devices.begin() + i); 
            Logger::getInstance()->log("Device removed: " + name);
            return;
        }
    }
    Logger::getInstance()->log("Error: Device ID " + to_string(id) + " not found!");
}

// Prototype Klonlama (REQ10)
void MSHSystem::duplicateDevice(int index, int newId) {
    if (index >= 0 && index < (int)devices.size()) {
        Logger::getInstance()->log("Cloning device from index: " + to_string(index));
        
        Device* cloneDevice = devices[index]->clone(); 
        cloneDevice->setId(newId);
        devices.push_back(cloneDevice);
        
        Logger::getInstance()->log("Success! New device created with ID: " + to_string(newId));
    } else {
        cout << "Invalid index for cloning!" << endl;
    }
}

// Mod Degistirme ve Memento (REQ7 & REQ11)
void MSHSystem::changeMode(ModeType newMode) {
    string oldModeStr = mshModeToString(currentMode);
    string newModeStr = mshModeToString(newMode);

    Logger::getInstance()->log("Changing mode from " + oldModeStr + " to " + newModeStr);
    
    // 1. Durumu Kaydet (Memento - Snapshot)
    
    
    HomeMemento* memento = new HomeMemento(currentMode); 
    caretaker->saveState(memento);

    // 2. Modu Guncelle
    currentMode = newMode;
    
    // 3. Mod Mantigini Uygula 
    for (size_t i = 0; i < devices.size(); ++i) {
        Device* d = devices[i];
        string n = d->getName(); 

        if (currentMode == MODE_NORMAL) {
             d->powerOn();
        }
        else if (currentMode == MODE_EVENING) { 
            // Evening: Isiklar kalsin, digerleri kapansin
            if (n.find("Light") != string::npos || n.find("Isigi") != string::npos) { 
               // Isiklara dokunma veya ac
            } else {
               d->powerOff();
            }
        }
        else if (currentMode == MODE_PARTY) {
            d->powerOn();
        }
        else if (currentMode == MODE_CINEMA) {
            // Cinema: TV acik, Isik kapali
            if (n.find("TV") != string::npos || n.find("Tv") != string::npos) {
                d->powerOn();
            } else if (n.find("Light") != string::npos) {
                d->powerOff();
            }
        }
    }
}

// Undo / Geri Alma (REQ12)
void MSHSystem::restorePreviousMode() {
    Logger::getInstance()->log("Attempting to restore previous state...");
    
    HomeMemento* memento = caretaker->undo();
    if (memento != NULL) {
        currentMode = memento->getMode();
        string restoredMode = mshModeToString(currentMode);
        
        cout << "Mode restored to: " << restoredMode << endl;
        Logger::getInstance()->log("Mode restored to: " + restoredMode);
        
        delete memento;
    } else {
        cout << "No previous state to restore!" << endl;
    }
}

// Listeleme
void MSHSystem::listDevices() {
    cout << "\n--- Device List ---" << endl;
    for (size_t i = 0; i < devices.size(); ++i) {
        // Cihazin kendi displayStatus fonksiyonunu cagiriyoruz
        devices[i]->displayStatus(); 
    }
    cout << "-------------------" << endl;
}

// Acil Durum (REQ16)
void MSHSystem::callFireStation() {
    Logger::getInstance()->log("!!! CRITICAL ALARM: Calling Fire Station (110) !!!");
    cout << ">> ALL NON-ESSENTIAL DEVICES SHUTTING DOWN..." << endl;
    
    for (size_t i = 0; i < devices.size(); ++i) {
        devices[i]->powerOff();
    }
}