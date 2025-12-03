#ifndef TV_H
#define TV_H

#include "Device.h"

// TV cihazını temsil eden sınıf
class TV : public Device {
public:
    TV(const string& n)
        : Device(n) {}

    virtual Device* clone() const override {
        return new TV(*this);
    }

    virtual void operate() override {
        cout << "[TV] " << name << " is showing content." << endl;
    }
};

#endif
