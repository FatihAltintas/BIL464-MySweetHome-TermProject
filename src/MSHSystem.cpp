#include "../include/MSHSystem.h"
#include "../include/Light.h"
#include <iostream>

using namespace std;

// Constructor
MSHSystem::MSHSystem() {
    caretaker = new StateCaretaker();
    currentMode = MODE_NORMAL;
}

// Destructor
MSHSystem::~MSHSystem() {
    delete caretaker;
    for (size_t i = 0; i < devices.size(); ++i) {
        delete devices[i];
    }
    devices.clear();
}

// ID ile Cihaz Bulma (Menu ve Komutlar icin Helper)
Device* MSHSystem::getDevice(int id) {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getId() == id) {
            return devices[i];
        }
    }
    return NULL;
}

void MSHSystem::addDevice(Device* d) {
    devices.push_back(d);
    cout << "[SYSTEM] Device added: " << d->getName() << endl;
}

// REQ8 (Fatih'in Isteri)
void MSHSystem::removeDevice(int id) {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getId() == id) {
            cout << "[SYSTEM] Removing device: " << devices[i]->getName() << endl;
            delete devices[i]; 
            devices.erase(devices.begin() + i); 
            return;
        }
    }
    cout << "[SYSTEM] Device ID " << id << " not found!" << endl;
}

// REQ10 (Erhan - Prototype)
void MSHSystem::duplicateDevice(int index, int newId) {
    if (index >= 0 && index < (int)devices.size()) {
        cout << "\n[REQ10] Cloning device..." << endl;
        Device* cloneDevice = devices[index]->clone(); 
        cloneDevice->setId(newId);
        devices.push_back(cloneDevice);
        cout << "[REQ10] Success! New device created from prototype." << endl;
    }
}

// REQ7 & REQ11 (Elmar & Erhan - Mod Degisimi ve Memento)
void MSHSystem::changeMode(ModeType newMode) {
    cout << "\n[REQ11] Changing mode from " << modeToString(currentMode) 
         << " to " << modeToString(newMode) << "..." << endl;
    
    // 1. Durumu Kaydet (Memento)
    vector<DeviceState> currentStates;
    for (size_t i = 0; i < devices.size(); ++i) {
        currentStates.push_back(devices[i]->getState());
    }
    HomeMemento* memento = new HomeMemento(modeToString(currentMode), currentStates);
    caretaker->saveMemento(memento);

    // 2. Modu Guncelle
    currentMode = newMode;
    
    // 3. Mod Mantigini Uygula (Elmar'in Logic)
    for (size_t i = 0; i < devices.size(); ++i) {
        Device* d = devices[i];
        string n = d->getName(); 

        if (currentMode == MODE_NORMAL) {
             d->powerOn();
        }
        else if (currentMode == MODE_EVENING) { 
            // Evening: Isiklar (Light) acik, digerleri kapali
            if (n.find("Light") != string::npos || n.find("Isigi") != string::npos) { 
                d->powerOn(); 
            } else {
                d->powerOff();
            }
        }
        else if (currentMode == MODE_PARTY) {
            d->powerOn();
        }
        else if (currentMode == MODE_CINEMA) {
            // Cinema: TV acik, digerleri kapali
            if (n.find("TV") != string::npos || n.find("Tv") != string::npos) {
                d->powerOn();
            } else {
                d->powerOff();
            }
        }
    }
}

// REQ12 (Erhan - Undo/Geri Alma)
void MSHSystem::restorePreviousMode() {
    cout << "\n[REQ12] Attempting to restore previous state..." << endl;
    
    HomeMemento* memento = caretaker->undo();
    if (memento != NULL) {
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

// REQ16 (Taha - Acil Durum)
void MSHSystem::callFireStation() {
    cout << "\n!!! CRITICAL ALARM (REQ16) !!!" << endl;
    cout << ">> Smoke detected and user did not respond!" << endl;
    cout << ">> CALLING FIRE STATION... (110)" << endl;
    cout << ">> ALL NON-ESSENTIAL DEVICES SHUTTING DOWN..." << endl;
    
    // Taha'nin mantigi: Her seyi kapat
    for (size_t i = 0; i < devices.size(); ++i) {
        devices[i]->powerOff();
    }
}