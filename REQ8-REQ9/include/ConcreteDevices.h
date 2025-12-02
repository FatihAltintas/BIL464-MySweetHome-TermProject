#ifndef CONCRETE_DEVICES_H
#define CONCRETE_DEVICES_H

#include "Device.h"

// ---------------------------------------------------------
// LIGHT (Iþýk Sýnýfý)
// ---------------------------------------------------------
class Light : public Device {
private:
    int brightness;
    string color;
public:
    Light(string n, int b = 100, string c = "White") : Device(n), brightness(b), color(c) {}

    // REQ8.5: Prototype Pattern (Clone)
    Device* clone() const {
        return new Light(*this);
    }

    // REQ10 uyumlu config kopyalama
    void copyConfigFrom(const Device* other) {
        Device::copyConfigFrom(other);
        const Light* l = dynamic_cast<const Light*>(other);
        if (l) {
            this->brightness = l->brightness;
            this->color = l->color;
        }
    }

    void operate() {
        cout << name << " (" << color << ", %" << brightness << ") aydinlatiyor." << endl;
    }
};

// ---------------------------------------------------------
// CAMERA (Kamera Sýnýfý)
// ---------------------------------------------------------
class Camera : public Device {
private:
    string resolution;
public:
    Camera(string n, string res = "1080p") : Device(n), resolution(res) {}

    Device* clone() const {
        return new Camera(*this);
    }

    void operate() {
        cout << name << " (" << resolution << ") kayit aliyor." << endl;
    }
};

// ---------------------------------------------------------
// ADAPTER PATTERN (REQ8.6)
// ---------------------------------------------------------

// Uyumsuz 3. Parti Cihaz
class ChineseLight {
public:
    void cin_ac() { cout << "Cin mali isik acildi (nihao)." << endl; }
};

// Adapter Sýnýfý
class ExternalLightAdapter : public Device {
private:
    ChineseLight* externalDevice;
public:
    ExternalLightAdapter(string n) : Device(n) {
        externalDevice = new ChineseLight();
    }
    ~ExternalLightAdapter() {
        delete externalDevice;
    }

    Device* clone() const {
        return new ExternalLightAdapter(name);
    }

    void operate() {
        // Adaptee metodunu çaðýrýyoruz
        externalDevice->cin_ac();
    }

    // Adapter için powerOn override edilebilir
    void powerOn() {
        Device::powerOn();
        externalDevice->cin_ac();
    }
};

#endif