#include "Device.h"
#include "Logger.h" // Durum degisimlerini loglamak icin

using namespace std;

// Constructor
Device::Device(const string& n) : name(n), id(0), state(INACTIVE) {
    // Baslangicta ID 0 ve durum INACTIVE
}

// Destructor
Device::~Device() {
    // Observer listesini temizlemeye gerek yok, sadece pointer tutuyoruz
    observers.clear();
}

// Config Kopyalama
void Device::copyConfigFrom(const Device* other) {
    if (other) {
        this->name = other->name + "_Copy";
        this->state = other->state;
        // ID kopyalanmaz, yeni cihaz yeni ID alir
    }
}

// Guc Acma
void Device::powerOn() {
    if (state != ACTIVE) {
        state = ACTIVE;
        Logger::getInstance()->log(name + " is turned ON.");
        notifyObservers();
    }
}

// Guc Kapatma
void Device::powerOff() {
    // Kritik cihaz kontrolü (Dedektörler override edecek ama base class izin verir)
    if (state != INACTIVE) {
        state = INACTIVE;
        Logger::getInstance()->log(name + " is turned OFF.");
        notifyObservers();
    }
}

// Durum Yazdirma
void Device::displayStatus() {
    string stateStr;
    switch (state) {
        case ACTIVE: stateStr = "ON"; break;
        case INACTIVE: stateStr = "OFF"; break;
        case FAILED: stateStr = "FAILED"; break;
        default: stateStr = "UNKNOWN"; break;
    }
    cout << "ID: " << id << " | Device: " << name << " | Status: " << stateStr << endl;
}

// Setter: State
void Device::setState(DeviceState newState) {
    if (state != newState) {
        state = newState;
        notifyObservers();
    }
}

// Getter: State
DeviceState Device::getState() const {
    return state;
}

// Getter: Name
string Device::getName() const {
    return name;
}

// Getter: ID
int Device::getId() const {
    return id;
}

// Setter: ID
void Device::setId(int newId) {
    this->id = newId;
}

// Observer: Ekle
void Device::attach(IObserver* observer) {
    observers.push_back(observer);
}

// Observer: Cikar
void Device::detach(IObserver* observer) {
    // Vector icinden pointer silme islemi (Remove-Erase idiom)
    for (size_t i = 0; i < observers.size(); ++i) {
        if (observers[i] == observer) {
            observers.erase(observers.begin() + i);
            return;
        }
    }
}

// Observer: Bildir
void Device::notifyObservers() {
    for (size_t i = 0; i < observers.size(); ++i) {
        observers[i]->update(this);
    }
}

// Kritik Cihaz Kontrolü (Varsayilan Hayir)
bool Device::isCritical() const {
    return false;
}