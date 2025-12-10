#include "../include/MSHSystem.h"
#include "../include/Light.h"
#include <iostream>

using namespace std;

MSHSystem::MSHSystem() {
    caretaker = new StateCaretaker();
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
    cout << "\n[REQ11] Changing mode from " << modeToString(currentMode) 
         << " to " << modeToString(newMode) << "..." << endl;
    
    vector<DeviceState> currentStates;
    for (size_t i = 0; i < devices.size(); ++i) {
        currentStates.push_back(devices[i]->getState());
    }
    HomeMemento* memento = new HomeMemento(modeToString(currentMode), currentStates);
    caretaker->saveMemento(memento);

    currentMode = newMode;
    
    for (size_t i = 0; i < devices.size(); ++i) {
        Device* d = devices[i];
        string n = d->getName(); 

        if (currentMode == MODE_NORMAL) {
             d->powerOn();
        }
        else if (currentMode == MODE_EVENING) { 
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
    void MSHSystem:: callFireStation () {
    cout << "\n!!! CRITICAL ALARM (REQ16) !!!" << endl;
    cout << ">> Smoke detected and user did not respond!" << endl;
    cout << ">> CALLING FIRE STATION... (110)" << endl;
    cout << ">> ALL NON-ESSENTIAL DEVICES SHUTTING DOWN..." << endl;
    
    // Taha'nin mantigi: Her seyi kapat
    for (size_t i = 0; i < devices.size(); ++i) {
        devices[i]->powerOff();
    }

}

Device* MSHSystem::getDevice(int id) {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getId() == id) {
            return devices[i];
        }
    }
    return NULL;
}
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