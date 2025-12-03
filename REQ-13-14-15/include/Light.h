#ifndef LIGHT_H
#define LIGHT_H

#include "Device.h"

class Light : public Device {
private:
    int brightness;
    string color;

public:
    // Constructor ID'yi alır ama Base class sadece name ister
    Light(int id, const string& name, int brightness, const string& color);
    
    // Prototype Pattern (REQ8.5)
    Device* clone() const override; 

    // Configuration Transfer (REQ10)
    void copyConfigFrom(const Device* other) override;

    // Device Base Class'tan gelen saf sanal fonksiyon
    void operate() override;

    // Işığa özel ayarlar
    void setBrightness(int level);
    void setColor(const string& newColor);
};

#endif // LIGHT_H