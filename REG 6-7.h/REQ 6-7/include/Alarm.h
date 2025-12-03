#ifndef ALARM_H
#define ALARM_H

#include "Device.h"

// Alarm cihazini temsil eden sinif
class Alarm : public Device {
public:
    // Alarm varsayilan olarak ON baslayabilir
    Alarm(const std::string& n, int i)
        : Device(n, i) {
        isActive = true;   // Sistem acilir acilmaz aktif
    }

    virtual Device* clone() const override {
        return new Alarm(*this);
    }

    // Alarm kullanici tarafindan kapatilamaz (REQ6 ozel durumu)
    virtual void powerOff() override {
        std::cout << name << " cannot be turned OFF by user!" << std::endl;
    }
};

#endif

