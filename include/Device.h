#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Device;


class IObserver {
public:
    virtual ~IObserver() {}
    
    virtual void update(Device* device) = 0;
};


enum DeviceState { ACTIVE, INACTIVE, FAILED };


class Device {
protected:
    string name;
    int id;
    DeviceState state; 

    
    vector<IObserver*> observers;

public:
    // Constructor
    Device(const string& n) : name(n), id(0), state(INACTIVE) {}
    virtual ~Device() {}

   
    virtual Device* clone() const = 0;

    
    virtual void operate() = 0;

    
    virtual void copyConfigFrom(const Device* other) {
        if (other) {
            this->name = other->name;
           
            cout << "[LOG] Config copied from " << other->name << endl;
        }
    }

    virtual void powerOn() {
        if (state != FAILED) {
            state = ACTIVE;
            cout << name << " is ON." << endl;
            notifyObservers();
        }
        else {
            cout << name << " is FAILED. Cannot power on." << endl;
        }
    }

    virtual void powerOff() {
        if (state != FAILED) {
            state = INACTIVE;
            cout << name << " is OFF." << endl;
            notifyObservers();
        }
    }

    
    void setState(DeviceState newState) {
        state = newState;
        notifyObservers(); 
    }

    DeviceState getState() const { return state; }
    string getName() const { return name; }
    int getId() const { return id; }
    void setId(int newId) { id = newId; }


    void attach(IObserver* observer) {
        observers.push_back(observer);
    }

    void detach(IObserver* observer) {
        for (vector<IObserver*>::iterator it = observers.begin(); it != observers.end(); ++it) {
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