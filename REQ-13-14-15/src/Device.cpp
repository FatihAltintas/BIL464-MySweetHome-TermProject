#include "../include/Device.h"
#include <iostream>

Device::Device(int id, const std::string& name) 
    : id(id), name(name), isPowered(false), isActive(true) {}

Device::~Device() {

}

void Device::turnOn() {
    if (isActive) {
        isPowered = true;
        std::cout << "Device ID: " << id << " (" << name << ") is now ON." << std::endl;
    } else {
        std::cout << "Device ID: " << id << " (" << name << ") cannot be turned on (INACTIVE/BROKEN)." << std::endl;
    }
}

void Device::turnOff() {
    isPowered = false;
    std::cout << "Device ID: " << id << " (" << name << ") is now OFF." << std::endl;
}

int Device::getId() const { 
    return id; 
}

std::string Device::getName() const { 
    return name; 
}

bool Device::getPowerState() const { 
    return isPowered; 
}

bool Device::getActiveState() const {
    return isActive;
}

void Device::setId(int newId) {
    this->id = newId;
}

void Device::setActiveState(bool active) {
    this->isActive = active;
    if (!active) {
        isPowered = false;
    }
}