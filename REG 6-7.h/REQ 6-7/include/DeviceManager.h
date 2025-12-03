#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include "Device.h"
#include "Light.h"
#include "TV.h"
#include "Camera.h"
#include "Alarm.h"

inline string deviceStateToString(DeviceState s) {
    switch (s) {
        case ACTIVE:   return "ACTIVE";
        case INACTIVE: return "INACTIVE";
        case FAILED:   return "FAILED";
        default:       return "UNKNOWN";
    }
}

// REQ6 + REQ9: Cihazları yöneten ve onları gözleyen sınıf
class DeviceManager : public IObserver {
    vector<Device*> devices;
    int nextId;

public:
    DeviceManager() : nextId(1) {}

    ~DeviceManager() {
        for (size_t i = 0; i < devices.size(); ++i) {
            if (devices[i]) {
                devices[i]->detach(this);
                delete devices[i];
            }
        }
    }

    // Ortak kayıt fonksiyonu
    Device* registerDevice(Device* d) {
        if (!d) return NULL;
        d->setId(nextId++);
        d->attach(this);           // REQ9: DeviceManager cihazı gözler
        devices.push_back(d);
        return d;
    }

    Device* addLight(const string& name) {
        return registerDevice(new Light(name));
    }

    Device* addTV(const string& name) {
        return registerDevice(new TV(name));
    }

    Device* addCamera(const string& name) {
        return registerDevice(new Camera(name));
    }

    Device* addAlarm(const string& name) {
        return registerDevice(new Alarm(name));
    }

    Device* findById(int id) {
        for (size_t i = 0; i < devices.size(); ++i) {
            if (devices[i]->getId() == id)
                return devices[i];
        }
        return NULL;
    }

    void listDevices() const {
        if (devices.empty()) {
            cout << "  Kayitli cihaz yok." << endl;
            return;
        }
        for (size_t i = 0; i < devices.size(); ++i) {
            cout << "  [" << devices[i]->getId() << "] "
                 << devices[i]->getName()
                 << " - " << deviceStateToString(devices[i]->getState())
                 << endl;
        }
    }

    // REQ6: Power ON
    void powerOnDevice(int id) {
        Device* d = findById(id);
        if (!d) {
            cout << "  Gecersiz cihaz ID!" << endl;
            return;
        }
        if (d->getState() == ACTIVE) {
            cout << "  Cihaz zaten ACTIVE." << endl;
            return;
        }
        d->powerOn();   // state ACTIVE olur, notifyObservers() tetiklenir
    }

    // REQ6: Power OFF
    void powerOffDevice(int id) {
        Device* d = findById(id);
        if (!d) {
            cout << "  Gecersiz cihaz ID!" << endl;
            return;
        }
        if (d->getState() == INACTIVE) {
            cout << "  Cihaz zaten INACTIVE." << endl;
            return;
        }
        d->powerOff();  // Alarm için override edilmiş olabilir
    }

    const vector<Device*>& getDevices() const {
        return devices;
    }

    // REQ9: Observer arabirimi — cihaz durumu değiştiğinde çağrılır
    virtual void update(Device* device) override {
        if (!device) return;
        cout << "[OBS] DeviceManager: "
             << device->getName()
             << " state changed to "
             << deviceStateToString(device->getState())
             << endl;
    }
};

#endif
