#ifndef TV_H
#define TV_H

#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

class Tv : public Device {
public:
    Tv(const string& n, int i) : Device(n) {
        setId(i); 
    }

    Device* clone() const {
        return new Tv(*this);
    }

    void operate() {
        cout << "[TV] Displaying content..." << endl;
    }
};

#endif