#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"

// Guvenlik kamerasini temsil eden sinif
class Camera : public Device {
public:
    Camera(const std::string& n, int i)
        : Device(n, i) {}

    virtual Device* clone() const override {
        return new Camera(*this);
    }

    // Ileride FPS, aci, cozunurluk vb. ozellikler eklenebilir
};

#endif

