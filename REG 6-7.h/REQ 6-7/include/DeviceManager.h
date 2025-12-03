#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <vector>
#include <iostream>
#include "Device.h"
#include "Light.h"
#include "TV.h"
#include "Camera.h"
#include "Alarm.h"

class DeviceManager {
    std::vector<Device*> devices;
    int nextId;

public:
    DeviceManager() : nextId(1) {}

    ~DeviceManager() {
        for (size_t i = 0; i < devices.size(); ++i) {
            delete devices[i];
        }
    }

    Device* addLight(const std::string& name) {
        Device* d = new Light(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* addTV(const std::string& name) {
        Device* d = new TV(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* addCamera(const std::string& name) {
        Device* d = new Camera(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* addAlarm(const std::string& name) {
        Device* d = new Alarm(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* findById(int id) {
        for (size_t i = 0; i < devices.size(); ++i) {
            if (devices[i]->getId() == id) {
                return devices[i];
            }
        }
        return NULL;
    }

    void listDevices() const {
        if (devices.empty()) {
            std::cout << "  Kayitli cihaz yok." << std::endl;
            return;
        }
        for (size_t i = 0; i < devices.size(); ++i) {
            std::cout << "  [" << devices[i]->getId() << "] "
                      << devices[i]->getName()
                      << " - " << (devices[i]->getStatus() ? "ON" : "OFF")
                      << std::endl;
        }
    }

    // REQ6: Power ON
    void powerOnDevice(int id) {
        Device* d = findById(id);
        if (!d) {
            std::cout << "  Gecersiz cihaz ID!" << std::endl;
            return;
        }
        if (d->getStatus()) {
            std::cout << "  Cihaz zaten ON." << std::endl;
            return;
        }
        d->powerOn();
    }

    // REQ6: Power OFF
    void powerOffDevice(int id) {
        Device* d = findById(id);
        if (!d) {
            std::cout << "  Gecersiz cihaz ID!" << std::endl;
            return;
        }
        if (!d->getStatus()) {
            std::cout << "  Cihaz zaten OFF." << std::endl;
            return;
        }
        d->powerOff();  // Alarm ise override edilmiş fonksiyon çalışır
    }

    const std::vector<Device*>& getDevices() const {
        return devices;
    }
};

#endif

