#ifndef ALARM_H
#define ALARM_H

#include "Device.h"
#include <iostream>
#include <string>

using namespace std;

class Alarm : public Device {
public:
    Alarm(const string& n, int i) : Device(n) {
        setId(i);
    }

    Device* clone() const {
        return new Alarm(*this);
    }

    void operate() {
        cout << "[Alarm] Monitoring status..." << endl;
    }
};

#endif