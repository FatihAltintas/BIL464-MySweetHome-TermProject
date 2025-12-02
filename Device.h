#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

// Abstract Base Class
// TUM GRUP KODLARINI BU SINIFTAN TURETECEK
class Device {
protected:
    std::string name;
    int id;
    bool isActive;

public:
    // Constructor
    Device(const std::string& n, int i) : name(n), id(i), isActive(false) {}
    virtual ~Device() {}

    // --- ENTEGRASYON ICIN KRITIK NOKTALAR ---

    // 1. Prototype Pattern (Her cihaz kendini kopyalayabilmeli)
    virtual Device* clone() const = 0;

    // 2. Configuration Transfer (Ayarlari kopyalamak icin)
    virtual void copyConfigFrom(const Device* other) {
        if (other) {
            this->name = other->name;
            // ID kopyalanmaz, unique kalir.
            std::cout << "[LOG] Config copied from " << other->name << std::endl;
        }
    }

    // 3. Standart Acma/Kapama Komutlari
    virtual void powerOn() {
        isActive = true;
        std::cout << name << " is ON." << std::endl;
    }

    virtual void powerOff() {
        isActive = false;
        std::cout << name << " is OFF." << std::endl;
    }

    // Getter & Setter
    bool getStatus() const { return isActive; }
    std::string getName() const { return name; }
    void setID(int newId) { id = newId; }
};

#endif