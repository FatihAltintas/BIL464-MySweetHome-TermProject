#include "../include/MSHSystem.h"
#include "../include/Light.h"
#include <iostream>

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
    std::cout << "[SYSTEM] Device added: " << d->getName() << std::endl;
}

void MSHSystem::duplicateDevice(int index, int newId) {
    if (index >= 0 && index < (int)devices.size()) {
        std::cout << "\n[REQ10] Cloning device..." << std::endl;
        
        Device* cloneDevice = devices[index]->clone(); 
        
        cloneDevice->setID(newId);
        
        devices.push_back(cloneDevice);
        std::cout << "[REQ10] Success! New device created from prototype." << std::endl;
    }
}

void MSHSystem::changeMode(const std::string& newMode) {
    std::cout << "\n[REQ11] Changing mode from " << currentMode << " to " << newMode << "..." << std::endl;
    
    std::vector<bool> currentStates;
    for (size_t i = 0; i < devices.size(); ++i) {
        currentStates.push_back(devices[i]->getStatus());
    }
    
    HomeMemento* memento = new HomeMemento(currentMode, currentStates);
    caretaker->saveMemento(memento);

    currentMode = newMode;
    
    for (size_t i = 0; i < devices.size(); ++i) {
        devices[i]->powerOff();
    }
}

void MSHSystem::restorePreviousMode() {
    std::cout << "\n[REQ12] Attempting to restore previous state..." << std::endl;
    
    HomeMemento* memento = caretaker->undo();
    if (memento != NULL) {
        currentMode = memento->getStateName();
        std::vector<bool> states = memento->getDeviceStates();

        std::cout << "[REQ12] Mode restored to: " << currentMode << std::endl;

        for (size_t i = 0; i < devices.size() && i < states.size(); ++i) {
            if (states[i]) {
                devices[i]->powerOn();
            } else {
                devices[i]->powerOff();
            }
        }
        
        delete memento;
    }
}

void MSHSystem::listDevices() {
    std::cout << "--- Device List ---" << std::endl;
    for (size_t i = 0; i < devices.size(); ++i) {
        std::cout << "ID: " << i << " | Name: " << devices[i]->getName() 
                  << " | Status: " << (devices[i]->getStatus() ? "ON" : "OFF") << std::endl;
    }
    std::cout << "-------------------" << std::endl;
}