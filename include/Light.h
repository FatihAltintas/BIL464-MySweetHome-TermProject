#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"
#include <iostream>
#include <string>

// Header dosyasinda sadece "Benim boyle fonksiyonlarim var" diyoruz.
class Light : public Device {
private:
    int brightness;
    std::string color;

public:
    Light(const std::string& n, int i); // Constructor tanimi
    virtual ~Light();                   // Destructor

    Device* clone() const;              // REQ10
    void operate();
    void setBrightness(int b);
    void showInfo() const;
};

#endif