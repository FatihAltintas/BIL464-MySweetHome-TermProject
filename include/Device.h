#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>
#include <vector>

class Device;

class IObserver {
public:
    virtual ~IObserver() {}
    virtual void update(Device* device) = 0;
};

enum DeviceState { ACTIVE, INACTIVE, FAILED };

class Device {
protected:
    std::string name;
    int id;
    DeviceState state;
    std::vector<IObserver*> observers;

public:
    Device(const std::string& n) : name(n), id(0), state(INACTIVE) {}
    virtual ~Device() {}

    virtual Device* clone() const = 0;
    virtual void operate() = 0;

    virtual void copyConfigFrom(const Device* other) {
        if (other) {
            this->name = other->name;
            std::cout << "[LOG] Config copied from " << other->name << std::endl;
        }
    }

    virtual void powerOn() {
        if (state != FAILED) {
            state = ACTIVE;
            std::cout << name << " ACILDI." << std::endl;
            notifyObservers();
        }
        else {
            std::cout << name << " FAILEd. Cannot power on." << std::endl;
        }
    }

    virtual void powerOff() {
        if (state != FAILED) {
            state = INACTIVE;
            std::cout << name << " KAPATILDI." << std::endl;
            notifyObservers();
        }
    }

    void setState(DeviceState newState) {
        state = newState;
        notifyObservers();
    }

    DeviceState getState() const { return state; }
    std::string getName() const { return name; }
    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    void attach(IObserver* observer) { observers.push_back(observer); }

    void detach(IObserver* observer) {
        for (std::vector<IObserver*>::iterator it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObservers() {
        for (size_t i = 0; i < observers.size(); ++i) {
            if (observers[i]) observers[i]->update(this);
        }
    }
};
#endif