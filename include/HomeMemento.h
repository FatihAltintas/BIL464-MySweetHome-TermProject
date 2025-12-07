#ifndef HOMEMEMENTO_H
#define HOMEMEMENTO_H

#include <string>
#include <vector>
#include "Device.h" 

class HomeMemento {
private:
    std::string stateName;
   
    std::vector<DeviceState> deviceStates; 

public:
    HomeMemento(const std::string& name, const std::vector<DeviceState>& states) 
        : stateName(name), deviceStates(states) {}
        
        ~HomeMemento() {
        deviceStates.clear(); 
    }

    std::string getStateName() const { return stateName; }
    std::vector<DeviceState> getDeviceStates() const { return deviceStates; }
};

#endif