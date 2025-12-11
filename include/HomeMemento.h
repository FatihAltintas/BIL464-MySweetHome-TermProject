#ifndef HOMEMEMENTO_H
#define HOMEMEMENTO_H

#include <string>
#include <vector>
#include "Device.h" // Enum icin

class HomeMemento {
private:
    std::string stateName;
    std::vector<DeviceState> deviceStates;

public:
    HomeMemento(const std::string& name, const std::vector<DeviceState>& states);
    std::string getStateName() const;
    std::vector<DeviceState> getDeviceStates() const;
};

#endif