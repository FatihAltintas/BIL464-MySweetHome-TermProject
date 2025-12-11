#include "../include/HomeMemento.h"

HomeMemento::HomeMemento(const std::string& name, const std::vector<DeviceState>& states) 
    : stateName(name), deviceStates(states) {}

std::string HomeMemento::getStateName() const {
    return stateName;
}

std::vector<DeviceState> HomeMemento::getDeviceStates() const {
    return deviceStates;
}