#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"
#include <iostream>
#include <string>


class Light : public Device {
private:
    int brightness;
    std::string color;

public:
    Light(const std::string& n, int i); // Constructor
    virtual ~Light();                   // Destructor

    // Prototype Pattern (REQ10)
    Device* clone() const;              

    // Islevler
    void operate();
    void setBrightness(int b);
    
    
    void displayStatus(); 
};

#endif