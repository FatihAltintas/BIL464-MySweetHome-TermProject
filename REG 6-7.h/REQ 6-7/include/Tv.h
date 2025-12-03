#ifndef TV_H
#define TV_H

#include "Device.h"

// TV cihazini temsil eden sinif
class TV : public Device {
public:
    TV(const std::string& n, int i)
        : Device(n, i) {}

    virtual Device* clone() const override {
        return new TV(*this);
    }

    // Ileride kanal, ses vb. ozellikler eklenebilir
};

#endif

