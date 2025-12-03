#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

// Light cihazını temsil eden sınıf
class Light : public Device {
public:
    // Sadece isim alıyoruz, ID sonradan DeviceManager tarafından set edilir
    Light(const string& n)
        : Device(n) {}

    // Prototype pattern
    virtual Device* clone() const override {
        return new Light(*this);
    }

    // Cihaza özgü davranış (örnek)
    virtual void operate() override {
        cout << "[Light] " << name << " is operating." << endl;
    }
};

#endif
