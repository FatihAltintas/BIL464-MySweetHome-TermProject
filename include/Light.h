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
    // DUZELTME: Constructor hem 'string' hem 'int' (ID) alacak sekilde ayarlandi.
    // Device(n) cagiriliyor, ID ise setId(i) ile ataniyor.
    Light(const string& n, int i) : Device(n), brightness(100), color("White") {
        setId(i); 
    }

    // Prototype Pattern (REQ10)
    Device* clone() const {
        return new Light(*this);
    }

    // Observer Pattern (REQ9) uyumlulugu
    void operate() {
        cout << "[Light] Operating... (Lighting up the room)" << endl;
    }

    void setBrightness(int b) { brightness = b; }
    
    void showInfo() const {
        cout << "   -> Light Info: Color=" << color << ", Brightness=" << brightness << "%" << endl;
    }
};

#endif