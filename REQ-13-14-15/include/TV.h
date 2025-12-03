#ifndef TV_H
#define TV_H

#include "Device.h"

class TV : public Device {
private:
    int channel;
    int volume;
public:
    TV(int id, const string& name) : Device(name), channel(1), volume(10) {
        this->id = id;
    }

    void setChannel(int ch) { channel = ch; notifyObservers(); }
    void setVolume(int vol) { volume = vol; notifyObservers(); }

    Device* clone() const override { return new TV(*this); }
    
    void operate() override {
        cout << "[TV] ID: " << id << " is " << (state == ACTIVE ? "ON" : "OFF")
             << ", Ch: " << channel << ", Vol: " << volume << endl;
    }
};

#endif