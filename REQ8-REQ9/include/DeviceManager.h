#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include "Device.h"
#include "Strategies.h"
#include "DeviceFactory.h"
#include <vector>

// DeviceManager hem yönetici hem de bir Gözlemcidir (IObserver)
class DeviceManager : public IObserver {
private:
    vector<Device*> devices; // REQ8.4: Cihaz listesi
    int nextId;
    INotificationStrategy* notificationStrategy; // REQ9.3: Strategy

public:
    DeviceManager();
    ~DeviceManager();

    // UI Ýþlemleri
    void addDeviceUI();
    void removeDeviceUI();
    void listDevices();

    // Strateji
    void setNotificationStrategy(INotificationStrategy* strategy);

    // Simülasyon
    void simulateFailure(int id);

    // REQ9.2: Gözlemci Metodu (Arýza yakalama)
    void update(Device* device);
};

#endif