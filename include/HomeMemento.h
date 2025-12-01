#ifndef HOMEMEMENTO_H
#define HOMEMEMENTO_H

#include <string>
#include <vector>

class HomeMemento {
private:
    std::string stateName;
    std::vector<bool> deviceStates; 

public:
    HomeMemento(const std::string& name, const std::vector<bool>& states) 
        : stateName(name), deviceStates(states) {}

    std::string getStateName() const { return stateName; }
    std::vector<bool> getDeviceStates() const { return deviceStates; }
};

#endif