#ifndef LIGHTADAPTER_H
#define LIGHTADAPTER_H

#include "Device.h"
#include "ForeignLight.h"

// Adapter: Device sinifindan turiyecek ama icinde ForeignLight tutacak
class LightAdapter : public Device {
private:
    ForeignLight* foreignDevice;

public:
    LightAdapter(ForeignLight* dev, int id);
    virtual ~LightAdapter();

    // Device'in fonksiyonlarini override ediyoruz
    Device* clone() const;
    void operate();
    void powerOn();  // Cevirici islevi gorecek
    void powerOff(); // Cevirici islevi gorecek
    
    void displayStatus();
};

#endif