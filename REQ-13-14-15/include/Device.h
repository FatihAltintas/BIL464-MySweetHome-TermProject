
#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Forward Declaration
class Device;

// =============================================================
// REQ9 - OBSERVER INTERFACE
// =============================================================
class IObserver {
public:
    virtual ~IObserver() {}
    // Cihazda bir deðiþiklik olduðunda bu fonksiyon tetiklenecek
    virtual void update(Device* device) = 0;
};

// Cihaz Durumlarý (REQ9 LLR-9.1)
enum DeviceState { ACTIVE, INACTIVE, FAILED };

// =============================================================
// DEVICE BASE CLASS (Tüm Grubun Kullanacaðý Ana Sýnýf)
// =============================================================
class Device {
protected:
    string name;
    int id;
    DeviceState state; // isActive yerine state kullanýyoruz (Daha kapsamlý)

    // REQ9: Bizi dinleyen yöneticilerin listesi
    vector<IObserver*> observers;

public:
    // Constructor
    Device(const string& n) : name(n), id(0), state(INACTIVE) {}
    virtual ~Device() {}

    // ---------------------------------------------------------
    // SAF SANAL FONKSÝYONLAR (Alt sýnýflar doldurmak zorunda)
    // ---------------------------------------------------------

    // REQ8.5: Prototype Pattern (Her cihaz kendini kopyalayabilmeli)
    virtual Device* clone() const = 0;

    // Cihaza özgü iþlem (Operate)
    virtual void operate() = 0;

    // ---------------------------------------------------------
    // ORTAK FONKSÝYONLAR
    // ---------------------------------------------------------

    // REQ10: Configuration Transfer (Ayarlarý kopyalamak için)
    virtual void copyConfigFrom(const Device* other) {
        if (other) {
            this->name = other->name;
            // ID kopyalanmaz, unique kalýr.
            cout << "[LOG] Config copied from " << other->name << endl;
        }
    }

    // Güç Yönetimi (State'i günceller ve notify eder)
    virtual void powerOn() {
        if (state != FAILED) {
            state = ACTIVE;
            cout << name << " is ON." << endl;
            notifyObservers();
        }
        else {
            cout << name << " is FAILED. Cannot power on." << endl;
        }
    }

    virtual void powerOff() {
        if (state != FAILED) {
            state = INACTIVE;
            cout << name << " is OFF." << endl;
            notifyObservers();
        }
    }

    // REQ9.1: Arýza veya durum deðiþikliðini manuel set etmek için
    void setState(DeviceState newState) {
        state = newState;
        notifyObservers(); // Durum deðiþti, haber ver!
    }

    // Getter & Setter
    DeviceState getState() const { return state; }
    string getName() const { return name; }
    int getId() const { return id; }
    void setId(int newId) { id = newId; }

    // ---------------------------------------------------------
    // OBSERVER MEKANÝZMASI (REQ9)
    // ---------------------------------------------------------

    void attach(IObserver* observer) {
        observers.push_back(observer);
    }

    void detach(IObserver* observer) {
        for (vector<IObserver*>::iterator it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObservers() {
        for (size_t i = 0; i < observers.size(); ++i) {
            if (observers[i]) observers[i]->update(this);
        }
    }
};

#endif
