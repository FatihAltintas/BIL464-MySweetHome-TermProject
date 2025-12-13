#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include "Device.h"
#include <string>

class DeviceFactory {
public:
    // Static metod oldugu icin nesne olusturmadan cagrilabilir
    static Device* createDevice(const std::string& type, const std::string& name, int id);
};

#endif