#include "Camera.h"
#include "Logger.h"

using namespace std;

// Constructor
Camera::Camera(const string& n, int i) : Device(n) {
    setId(i);
}

// Destructor
Camera::~Camera() {}

// Clone (Prototype)
Device* Camera::clone() const {
    return new Camera(*this);
}

// Operate
void Camera::operate() {
    Logger::getInstance()->log("[Camera] Operating... Recording video footage.");
}

// Durum Goster (Override)
void Camera::displayStatus() {
    // Once standart bilgiyi yaz
    Device::displayStatus();
    
    // Aktifse detay goster
    if (getState() == ACTIVE) {
        cout << "   -> Detail: Status: Recording, Resolution: 1080p" << endl;
    }
}