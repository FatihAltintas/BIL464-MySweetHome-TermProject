#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include "Device.h"
#include "DeviceFactory.h"

// SystemManager, REQ9 gereği bir Observer'dır.
class SystemManager : public IObserver {
private:
    static SystemManager* instance;
    std::vector<Device*> devices;
    
    string systemStatus;     
    bool alarmState;              

    SystemManager();

public:
    static SystemManager* getInstance();
    ~SystemManager();

    // IObserver'dan gelen update fonksiyonu (REQ9)
    void update(Device* device) override;

    void addDevice(Device* device);
    void removeDevice(int deviceId);
    void listDevices() const;
    Device* getDevice(int id);
    
    // Tüm cihazları çalıştırır (Polimorfizm)
    void runCycle(); 
};

#endif