#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

class Device {
protected:
    std::string name;
    int id;
    bool isActive;

public:
    Device(const std::string& n, int i) : name(n), id(i), isActive(false) {}
    virtual ~Device() {}

    virtual Device* clone() const = 0;

    virtual void copyConfigFrom(const Device* other) {
        if (other) {
            this->name = other->name; 
            std::cout << "[LOG] Configuration copied from " << other->name << " to new device." << std::endl;
        }
    }

    void powerOn() { 
        isActive = true; 
        std::cout << name << " (ID: " << id << ") is now ON." << std::endl;
    }

    void powerOff() { 
        isActive = false; 
        std::cout << name << " (ID: " << id << ") is now OFF." << std::endl;
    }

    bool getStatus() const { return isActive; }
    std::string getName() const { return name; }
    void setID(int newId) { id = newId; }
};

#endif