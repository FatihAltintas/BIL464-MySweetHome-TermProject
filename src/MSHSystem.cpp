#include "../include/MSHSystem.h"
#include "../include/Light.h"
#include <iostream>

using namespace std;

MSHSystem::MSHSystem() {
    caretaker = new StateCaretaker();
    currentMode = "Normal";
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

void MSHSystem::changeMode(const string& newMode) {
    cout << "\n[REQ11] Changing mode from " << currentMode << " to " << newMode << "..." << endl;
    

    vector<DeviceState> currentStates;
    for (size_t i = 0; i < devices.size(); ++i) {
        currentStates.push_back(devices[i]->getState());
    }
    
    HomeMemento* memento = new HomeMemento(currentMode, currentStates);
    caretaker->saveMemento(memento);

    currentMode = newMode;
    for (size_t i = 0; i < devices.size(); ++i) {
        devices[i]->powerOff();
    }
}

void MSHSystem::restorePreviousMode() {
    cout << "\n[REQ12] Attempting to restore previous state..." << endl;
    
    HomeMemento* memento = caretaker->undo();
    if (memento != NULL) {
        currentMode = memento->getStateName();
        vector<DeviceState> states = memento->getDeviceStates();

        cout << "[REQ12] Mode restored to: " << currentMode << endl;

        for (size_t i = 0; i < devices.size() && i < states.size(); ++i) {
            // Yeni Device.h yapisindaki Enum kontrolü
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