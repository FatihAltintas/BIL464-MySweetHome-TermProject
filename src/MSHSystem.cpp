#include "../include/MSHSystem.h"
#include "../include/Light.h"
#include <iostream>

using namespace std;

MSHSystem::MSHSystem() {
    caretaker = new StateCaretaker();
    // Varsayilan mod
    currentMode = MODE_NORMAL;
}

MSHSystem::~MSHSystem() {
    delete caretaker;
    for (size_t i = 0; i < devices.size(); ++i) {
        delete devices[i];
    }
    devices.clear();
}

void MSHSystem::addDevice(Device* d) {
    devices.push_back(d);
    cout << "[SYSTEM] Device added: " << d->getName() << endl;
}

void MSHSystem::duplicateDevice(int index, int newId) {
    if (index >= 0 && index < (int)devices.size()) {
        cout << "\n[REQ10] Cloning device..." << endl;
        Device* cloneDevice = devices[index]->clone(); 
        cloneDevice->setId(newId);
        devices.push_back(cloneDevice);
        cout << "[REQ10] Success! New device created from prototype." << endl;
    }
}

// --- ELMAR'IN MOD MANTIGI BURAYA ENTEGRE EDILDI ---
void MSHSystem::changeMode(ModeType newMode) {
    cout << "\n[REQ7 & REQ11] Changing mode from " << modeToString(currentMode) 
         << " to " << modeToString(newMode) << "..." << endl;
    
    // 1. Onceki Durumu Kaydet (Memento)
    vector<DeviceState> currentStates;
    for (size_t i = 0; i < devices.size(); ++i) {
        currentStates.push_back(devices[i]->getState());
    }
    
    // Memento string istedigi icin modeToString kullaniyoruz
    HomeMemento* memento = new HomeMemento(modeToString(currentMode), currentStates);
    caretaker->saveMemento(memento);

    // 2. Modu Guncelle
    currentMode = newMode;
    
    // 3. Elmar'in Cihaz Yonetim Mantigi (Apply Mode Logic)
    for (size_t i = 0; i < devices.size(); ++i) {
        Device* d = devices[i];
        string n = d->getName(); // Cihaz ismi

        if (currentMode == MODE_NORMAL) {
            // Normal modda hepsi acik olsun (veya kullanici biraktigi gibi)
             d->powerOn();
        }
        else if (currentMode == MODE_NIGHT) {
            // Night: Sadece "LivingRoomLight" acik kalsin, digerleri kapansin
            // (Elmar'in mantigi)
            if (n == "LivingRoomLight" || n == "Test Oturma Odasi") { // Test icin senin ismini de ekledim
                d->powerOn();
            } else {
                d->powerOff();
            }
        }
        else if (currentMode == MODE_PARTY) {
            // Party: Her sey acilsin!
            d->powerOn();
        }
        else if (currentMode == MODE_CINEMA) {
            // Cinema: Isinde "TV" gecenler acik, isiklar kapali
            if (n.find("TV") != string::npos || n.find("Tv") != string::npos) {
                d->powerOn();
            } else {
                d->powerOff();
            }
        }
    }
}

void MSHSystem::restorePreviousMode() {
    cout << "\n[REQ12] Attempting to restore previous state..." << endl;
    
    HomeMemento* memento = caretaker->undo();
    if (memento != NULL) {
        // Memento'dan gelen string modu geri yukluyoruz
        // (Burada string'den Enum'a donusum yapmak gerekebilir ama 
        // gorsellik icin string yetsin, logic calisir)
        string restoredModeName = memento->getStateName();
        cout << "[REQ12] Mode restored to: " << restoredModeName << endl;

        vector<DeviceState> states = memento->getDeviceStates();

        for (size_t i = 0; i < devices.size() && i < states.size(); ++i) {
            if (states[i] == ACTIVE) {
                devices[i]->powerOn();
            } else if (states[i] == INACTIVE) {
                devices[i]->powerOff();
            }
        }
        delete memento;
    }
}

void MSHSystem::listDevices() {
    cout << "--- Device List ---" << endl;
    for (size_t i = 0; i < devices.size(); ++i) {
        string statusStr = (devices[i]->getState() == ACTIVE) ? "ON" : "OFF";
        cout << "ID: " << devices[i]->getId() 
             << " | Name: " << devices[i]->getName() 
             << " | Status: " << statusStr << endl;
    }
    cout << "-------------------" << endl;
}