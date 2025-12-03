#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"

// Güvenlik kamerasını temsil eden sınıf
class Camera : public Device {
public:
    Camera(const string& n)
        : Device(n) {}

    virtual Device* clone() const override {
        return new Camera(*this);
    }

    virtual void operate() override {
        cout << "[Camera] " << name << " is recording." << endl;
    }
};

#endif
