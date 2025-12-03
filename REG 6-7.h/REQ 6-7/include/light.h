#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

// Light cihazini temsil eden sinif
class Light : public Device {
public:
    // Kurucu fonksiyon: isim ve ID alir, base class'a gecer
    Light(const std::string& n, int i)
        : Device(n, i) {}

    // Prototype pattern: bu nesnenin kopyasini uretir
    virtual Device* clone() const override {
        return new Light(*this);
    }

    // Istersek ileride Light'a ozel davranis ekleyebiliriz
    // (su an icin Device'in powerOn/powerOff fonksiyonlarini kullaniyoruz)
};

#endif

