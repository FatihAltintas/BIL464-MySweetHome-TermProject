#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>
#include <vector>

// Forward Declaration
class Device;

// Observer Interface (Bu interface oldugu icin burada kalabilir veya ayrilabilir, 
// ama genelde interface { } ici bos oldugu icin headerda kalmasi sorun degildir. 
// Yine de kurala uyalım.)
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

    // Saf sanal fonksiyonlar (Bunlarin cpp'si olmaz)
    virtual Device* clone() const = 0;
    virtual void operate() = 0;

    // Normal fonksiyonlar (Bunlarin ici cpp'ye gidecek)
    virtual void copyConfigFrom(const Device* other);
    virtual void powerOn();
    virtual void powerOff();
    
    void setState(DeviceState newState);
    DeviceState getState() const;
    
    std::string getName() const;
    int getId() const;
    void setId(int newId);

    void attach(IObserver* observer);
    void detach(IObserver* observer);
    void notifyObservers();
};

#endif