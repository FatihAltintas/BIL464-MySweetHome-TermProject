#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"

class Camera : public Device {
private:
    bool motionDetected;
    int resolutionMP;

public:
    Camera(int id, const string& name, int resolutionMP);

    void setMotionDetected(bool status);
    bool isMotionDetected() const;

    // Prototype & Config Copy
    Device* clone() const override;
    void copyConfigFrom(const Device* other) override;

    // Main Operation
    void operate() override;
};

#endif