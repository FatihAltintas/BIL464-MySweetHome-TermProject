#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

class Camera : public Device {
public:
    Camera(const string& n, int i) : Device(n) {
        setId(i);
    }

    Device* clone() const {
        return new Camera(*this);
    }

    void operate() {
        cout << "[Camera] Recording video..." << endl;
    }
};

#endif