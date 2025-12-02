#include "DeviceManager.h"
#include <iostream>

using namespace std;

DeviceManager::DeviceManager() : nextId(1) {
    // Varsayýlan strateji: Log
    notificationStrategy = new LogStrategy();
}

DeviceManager::~DeviceManager() {
    for (size_t i = 0; i < devices.size(); ++i) {
        delete devices[i]; // REQ8.8: Bellek temizliði
    }
    if (notificationStrategy) delete notificationStrategy;
}

void DeviceManager::setNotificationStrategy(INotificationStrategy* strategy) {
    if (notificationStrategy) delete notificationStrategy;
    notificationStrategy = strategy;
    cout << ">> Bildirim stratejisi guncellendi." << endl;
}

// REQ8.2 & REQ8.5: Cihaz Ekleme (Factory + Prototype)
void DeviceManager::addDeviceUI() {
    cout << "\n--- CIHAZ EKLEME ---" << endl;
    cout << "1. Isik\n2. Kamera\n3. Harici Isik (Adapter)\nSecim: ";
    int type; cin >> type;

    cout << "Kac adet? ";
    int qty; cin >> qty;

    // 1. Ýlk nesneyi Factory ile yarat
    Device* prototype = DeviceFactory::createDevice(type);
    if (!prototype) { cout << "Gecersiz secim." << endl; return; }

    // Prototipi ekle
    prototype->setId(nextId++);
    prototype->attach(this); // Kendimizi observer olarak ekliyoruz
    devices.push_back(prototype);
    cout << "-> ID-" << prototype->getId() << " olusturuldu." << endl;

    // 2. Geri kalanlarý Prototype (Clone) ile kopyala
    for (int i = 1; i < qty; ++i) {
        Device* clone = prototype->clone();
        clone->copyConfigFrom(prototype); // Ayarlarý kopyala
        clone->setId(nextId++);
        clone->attach(this);
        devices.push_back(clone);
        cout << "-> ID-" << clone->getId() << " kopyalandi (Prototype)." << endl;
    }
}

// REQ8.7: Listeleme
void DeviceManager::listDevices() {
    cout << "\n--- CIHAZ LISTESI ---" << endl;
    for (size_t i = 0; i < devices.size(); ++i) {
        string statusStr = (devices[i]->getState() == ACTIVE) ? "ON" :
            (devices[i]->getState() == FAILED) ? "FAILED" : "OFF";

        cout << "ID: " << devices[i]->getId()
            << " | " << devices[i]->getName()
            << " | Durum: " << statusStr << endl;
    }
}

// REQ8.8: Silme
void DeviceManager::removeDeviceUI() {
    listDevices();
    cout << "Silinecek ID: ";
    int id; cin >> id;

    for (vector<Device*>::iterator it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getId() == id) {
            delete* it; // Heap'ten sil
            devices.erase(it); // Vectorden sil
            cout << "Cihaz silindi." << endl;
            return;
        }
    }
    cout << "Bulunamadi." << endl;
}

void DeviceManager::simulateFailure(int id) {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getId() == id) {
            cout << "\n[SIMULASYON] Cihaz bozuluyor..." << endl;
            devices[i]->setState(FAILED); // Bu iþlem update() fonksiyonunu tetikler
            return;
        }
    }
}

// REQ9.2 & REQ9.5: Arýza Bildirimi
void DeviceManager::update(Device* device) {
    if (device->getState() == FAILED) {
        string msg = "ARIZA: Cihaz ID-" + to_string(device->getId()) + " (" + device->getName() + ")";
        notificationStrategy->sendNotification(msg);
    }
}