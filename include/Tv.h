#ifndef TV_H
#define TV_H

#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

class Tv : public Device {
public:
    // DUZELTME: Constructor artik hem 'string' hem 'int' (ID) aliyor
    Tv(const string& n, int i) : Device(n) {
        setId(i); // ID'yi ayarliyoruz
    }

    // Prototype (REQ10)
    Device* clone() const {
        return new Tv(*this);
    }

    // Abstract fonksiyonu dolduruyoruz
    void operate() {
        cout << "[TV] Displaying content..." << endl;
    }
};

#endif