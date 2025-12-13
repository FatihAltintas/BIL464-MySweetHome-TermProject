#include "LightAdapter.h"
#include "Logger.h"
#include <iostream>

using namespace std;

LightAdapter::LightAdapter(ForeignLight* dev, int id) : Device("Adapter_" + dev->getModelName()) {
    this->foreignDevice = dev;
    setId(id);
}

LightAdapter::~LightAdapter() {
    if (foreignDevice) delete foreignDevice;
}

Device* LightAdapter::clone() const {
    // Adapter clonelamak biraz karisiktir, basite indirgiyoruz
    // Yeni bir ForeignLight olusturup yeni Adapter donduruyoruz
    return new LightAdapter(new ForeignLight(foreignDevice->getModelName()), getId());
}

void LightAdapter::operate() {
    // Operasyonel mantik
}

// ADAPTERIN SIHRI BURADA:
// Bizim sistem 'powerOn' cagiriyor, Adapter arkada 'turnOn220V' cagiriyor.
void LightAdapter::powerOn() {
    if (getState() != ACTIVE) {
        setState(ACTIVE);
        foreignDevice->turnOn220V(); // Adapte edilen cagri
    }
}

void LightAdapter::powerOff() {
    if (getState() != INACTIVE) {
        setState(INACTIVE);
        foreignDevice->turnOff220V(); // Adapte edilen cagri
    }
}

void LightAdapter::displayStatus() {
    Device::displayStatus();
    cout << "   -> [ADAPTER ACTIVE] Connected to foreign device: " << foreignDevice->getModelName() << endl;
}