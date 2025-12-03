#ifndef ALARM_H
#define ALARM_H

#include "Device.h"

class Alarm : public Device {
public:
    Alarm(int id) : Device("General Alarm") {
        this->id = id;
    }

    Device* clone() const override { return new Alarm(*this); }
    
    void operate() override {
        cout << "[ALARM DEVICE] ID: " << id 
             << " Status: " << (state == ACTIVE ? "SOUNDING!" : "Silent") << endl;
    }
};

#endif