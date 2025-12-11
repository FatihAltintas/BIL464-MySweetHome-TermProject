#include "../include/Device.h"

using namespace std;

// Constructor
Device::Device(const string& n) : name(n), id(0), state(INACTIVE) {}

// Destructor
Device::~Device() {}

// REQ10 Config Copy
void Device::copyConfigFrom(const Device* other) {
    if (other) {
        this->name = other->name;
        cout << "[LOG] Config copied from " << other->getName() << endl;
    }
}

void Device::powerOn() {
    if (state != FAILED) {
        state = ACTIVE;
        cout << name << " is ON." << endl;
        notifyObservers();
    } else {
        cout << name << " is FAILED. Cannot power on." << endl;
    }
}

void Device::powerOff() {
    if (state != FAILED) {
        state = INACTIVE;
        cout << name << " is OFF." << endl;
        notifyObservers();
    }
}

void Device::setState(DeviceState newState) {
    state = newState;
    notifyObservers();
}

DeviceState Device::getState() const { return state; }
string Device::getName() const { return name; }
int Device::getId() const { return id; }
void Device::setId(int newId) { id = newId; }

// Observer Islemleri
void Device::attach(IObserver* observer) {
    observers.push_back(observer);
}

void Device::detach(IObserver* observer) {
    for (vector<IObserver*>::iterator it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break;
        }
    }
}

void Device::notifyObservers() {
    for (size_t i = 0; i < observers.size(); ++i) {
        if (observers[i]) observers[i]->update(this);
    }
}