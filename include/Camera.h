#ifndef CAMERA_H
#define CAMERA_H

#include "Device.h"
#include <iostream>
#include <string>

// Header dosyasinda sadece tanimlar kaldi
class Camera : public Device {
public:
    Camera(const std::string& n, int i); // Constructor
    virtual ~Camera();                   // Destructor

    // Prototype Pattern (REQ10)
    Device* clone() const;

    // Islevler
    void operate();
    
    // Listeleme detaylari icin
    void displayStatus();
};

#endif