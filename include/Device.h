#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm> // remove icin

// Forward Declaration
class Device;

// Observer Interface 

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
    Device(const std::string& n);
    virtual ~Device();

    // Saf sanal fonksiyonlar
    virtual Device* clone() const = 0;
    virtual void operate() = 0;

    // Implementation gerektiren fonksiyonlar
    virtual void copyConfigFrom(const Device* other);
    virtual void powerOn();
    virtual void powerOff();
    
    
    virtual void displayStatus(); 

    // Getter & Setter
    void setState(DeviceState newState);
    DeviceState getState() const;
    
    std::string getName() const;
    int getId() const;
    void setId(int newId);
    
    // Observer Yonetimi
    void attach(IObserver* observer);
    void detach(IObserver* observer);
    void notifyObservers();
    
    
    virtual bool isCritical() const;
};

#endif