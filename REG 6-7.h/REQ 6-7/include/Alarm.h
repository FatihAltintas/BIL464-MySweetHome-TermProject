#ifndef ALARM_H
#define ALARM_H

#include "Device.h"

// Alarm cihazını temsil eden sınıf
class Alarm : public Device {
public:
    Alarm(const string& n)
        : Device(n) {
        // Sistem açıldığında alarm inaktif, istersen ACTIVE yapabilirsin
        // state = ACTIVE;
    }

    virtual Device* clone() const override {
        return new Alarm(*this);
    }

    virtual void operate() override {
        cout << "[Alarm] " << name << " is monitoring." << endl;
    }

    // Kullanıcı tarafından kapatılamasın (REQ6 özel durum)
    virtual void powerOff() override {
        cout << name << " cannot be turned OFF by user!" << endl;
        // state aynı kalır, notify yok
    }
};

#endif
