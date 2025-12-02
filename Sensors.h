#ifndef SENSORS_H
#define SENSORS_H

#include "Device.h"
#include "Logger.h"

// ==========================================
// 1. NORMAL CÝHAZLAR (Light, TV, Camera)
// ==========================================

// IÞIK SINIFI
class Light : public Device {
private:
    int brightness;
public:
    Light(int id, const std::string& name, int brightness)
        : Device(name, id), brightness(brightness) {
    }

    // LLR 7: Prototype Pattern (Klonlama)
    Device* clone() const override {
        return new Light(*this); // Copy Constructor ile kopyalar
    }

    // Açýlma sýrasýnda log atalým
    void powerOn() override {
        Device::powerOn(); // Base class iþlemini yap (isActive = true)
        Logger::getInstance()->log("Light turned ON: " + getName());
    }
};

// KAMERA SINIFI
class Camera : public Device {
public:
    Camera(int id, const std::string& name) : Device(name, id) {}

    Device* clone() const override {
        return new Camera(*this);
    }

    void powerOn() override {
        Device::powerOn();
        Logger::getInstance()->log("Camera system activated: " + getName());
    }
};

// ==========================================
// 2. DEDEKTÖRLER (Abstract Factory Ürünleri)
// ==========================================

// DUMAN DEDEKTÖRÜ
class SmokeDetector : public Device {
public:
    SmokeDetector(int id) : Device("Smoke Detector", id) {}

    // LLR 8: Kritik Cihaz Kýsýtlamasý (Kapatýlamaz!)
    void powerOff() override {
        Logger::getInstance()->log("SECURITY WARNING: User tried to turn off Smoke Detector! Operation blocked.");
        std::cout << "[SECURITY] Cannot turn off Smoke Detector!" << std::endl;
    }

    Device* clone() const override { return new SmokeDetector(*this); }
};

// GAZ DEDEKTÖRÜ
class GasDetector : public Device {
public:
    GasDetector(int id) : Device("Gas Detector", id) {}

    // LLR 8: Kritik Cihaz Kýsýtlamasý
    void powerOff() override {
        Logger::getInstance()->log("SECURITY WARNING: User tried to turn off Gas Detector! Operation blocked.");
        std::cout << "[SECURITY] Cannot turn off Gas Detector!" << std::endl;
    }

    Device* clone() const override { return new GasDetector(*this); }
};

// ==========================================
// 3. ABSTRACT FACTORY PATTERN (LLR 2)
// ==========================================

// Soyut Fabrika Arayüzü
class DetectorFactory {
public:
    virtual SmokeDetector* createSmokeDetector(int id) = 0;
    virtual GasDetector* createGasDetector(int id) = 0;
    virtual ~DetectorFactory() {}
};

// Somut Fabrika (Gerçek Üretici)
class SecurityDeviceFactory : public DetectorFactory {
public:
    // Duman dedektörü üretir ve loglar
    SmokeDetector* createSmokeDetector(int id) override {
        Logger::getInstance()->log("Factory created a new Smoke Detector (ID: " + std::to_string(id) + ")");
        return new SmokeDetector(id);
    }

    // Gaz dedektörü üretir ve loglar
    GasDetector* createGasDetector(int id) override {
        Logger::getInstance()->log("Factory created a new Gas Detector (ID: " + std::to_string(id) + ")");
        return new GasDetector(id);
    }
};

#endif // SENSORS_H