#include "Camera.h"
#include <iostream>

Camera::Camera(int id, const string& name, int resolutionMP)
    : Device(name), motionDetected(false), resolutionMP(resolutionMP) {
    this->id = id;
}

void Camera::setMotionDetected(bool status) {
    if (state != ACTIVE) return; // Kapalıysa veya bozuksa algılamaz

    motionDetected = status;
    if (motionDetected) {
        cout << "[ALARM] Camera " << id << " detected MOTION!" << endl;
        notifyObservers(); // Sistem Yöneticisine haber ver
    }
}

bool Camera::isMotionDetected() const { return motionDetected; }

Device* Camera::clone() const { return new Camera(*this); }

void Camera::copyConfigFrom(const Device* other) {
    Device::copyConfigFrom(other);
    const Camera* otherCam = dynamic_cast<const Camera*>(other);
    if(otherCam) {
        this->resolutionMP = otherCam->resolutionMP;
        cout << "[Camera] Resolution settings copied." << endl;
    }
}

void Camera::operate() {
    cout << "[Camera] ID: " << id << ", Name: " << name
         << ", Power: " << (state == ACTIVE ? "ON" : "OFF")
         << ", Res: " << resolutionMP << "MP"
         << ", Motion: " << (motionDetected ? "YES" : "NO") << endl;
}