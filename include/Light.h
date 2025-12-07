#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

class Light : public Device {
private:
    int brightness;
    string color;

public:
    Light(const string& n, int i) : Device(n), brightness(100), color("White") {
        setId(i); 
    }
    ~Light() {
        
    }

    Device* clone() const {
        return new Light(*this);
    }

    void operate() {
        cout << "[Light] Operating... (Lighting up the room)" << endl;
    }

    void setBrightness(int b) { brightness = b; }
    
    void showInfo() const {
        cout << "   -> Light Info: Color=" << color << ", Brightness=" << brightness << "%" << endl;
    }
};

#endif