#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light : public Device {
private:
    int brightness;
    std::string color;

public:
    Light(const std::string& n, int i) : Device(n, i), brightness(100), color("White") {}

    virtual Device* clone() const {
        return new Light(*this);
    }

    void setBrightness(int b) { brightness = b; }
    
    void showInfo() const {
        std::cout << "   -> Light Info: Color=" << color << ", Brightness=" << brightness << "%" << std::endl;
    }
};

#endif