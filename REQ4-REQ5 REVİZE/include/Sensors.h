#ifndef SENSORS_H
#define SENSORS_H

#include "Device.h"
#include "Logger.h"

// ==========================================
// 1. NORMAL CÝHAZLAR (Light, Camera)
// ==========================================

class Light : public Device {
private:
    int brightness;
public:
    // YENÝ BASE CLASS UYUMU:
    // Base class sadece 'name' alýyor. ID'yi içeride 'setId' ile veya direkt atýyoruz.
    Light(int id, const string& name, int brightness)
        : Device(name), brightness(brightness) {
        this->id = id; // Device sýnýfýndaki protected 'id' deðiþkenini güncelliyoruz
    }

    // Prototype (Clone)
    Device* clone() const override {
        return new Light(*this);
    }

    // YENÝ: Device.h'ta 'operate' zorunlu kýlýnmýþ, ekliyoruz.
    void operate() override {
        Logger::getInstance()->log("Light is operating at " + to_string(brightness) + "% brightness.");
    }

    // Override ederek LOGLAMA ekliyoruz
    void powerOn() override {
        Device::powerOn(); // State'i ACTIVE yapar ve Observer'larý uyarýr
        Logger::getInstance()->log("Light turned ON: " + getName());
    }

    void powerOff() override {
        Device::powerOff(); // State'i INACTIVE yapar
        Logger::getInstance()->log("Light turned OFF: " + getName());
    }
};

class Camera : public Device {
public:
    Camera(int id, const string& name) : Device(name) {
        this->id = id;
    }

    Device* clone() const override {
        return new Camera(*this);
    }

    // Zorunlu operate fonksiyonu
    void operate() override {
        Logger::getInstance()->log("Camera is recording...");
    }

    void powerOn() override {
        Device::powerOn();
        Logger::getInstance()->log("Camera System Activated: " + getName());
    }

    void powerOff() override {
        Device::powerOff();
        Logger::getInstance()->log("Camera System Deactivated: " + getName());
    }
};

// ==========================================
// 2. DEDEKTÖRLER (Abstract Factory Ürünleri)
// ==========================================

class SmokeDetector : public Device {
public:
    SmokeDetector(int id) : Device("Smoke Detector") {
        this->id = id;
    }

    void operate() override {
        Logger::getInstance()->log("Smoke Detector is sniffing for smoke particles...");
    }

    void powerOn() override {
        Device::powerOn();
        Logger::getInstance()->log("SECURITY: Smoke Detector Activated.");
    }

    // REQ KURALI: Dedektörler kapatýlamaz!
    void powerOff() override {
        // Base class powerOff ÇAÐRILMAZ.
        Logger::getInstance()->log("SECURITY WARNING: User tried to turn off Smoke Detector! Operation blocked.");
        cout << "[SECURITY ALERT] Cannot turn off Smoke Detector manually!" << endl;
    }

    Device* clone() const override { return new SmokeDetector(*this); }
};

class GasDetector : public Device {
public:
    GasDetector(int id) : Device("Gas Detector") {
        this->id = id;
    }

    void operate() override {
        Logger::getInstance()->log("Gas Detector is measuring air quality...");
    }

    void powerOn() override {
        Device::powerOn();
        Logger::getInstance()->log("SECURITY: Gas Detector Activated.");
    }

    // REQ KURALI: Dedektörler kapatýlamaz!
    void powerOff() override {
        Logger::getInstance()->log("SECURITY WARNING: User tried to turn off Gas Detector! Operation blocked.");
        cout << "[SECURITY ALERT] Cannot turn off Gas Detector manually!" << endl;
    }

    Device* clone() const override { return new GasDetector(*this); }
};

// ==========================================
// 3. ABSTRACT FACTORY PATTERN
// ==========================================

class DetectorFactory {
public:
    virtual SmokeDetector* createSmokeDetector(int id) = 0;
    virtual GasDetector* createGasDetector(int id) = 0;
    virtual ~DetectorFactory() {}
};

class SecurityDeviceFactory : public DetectorFactory {
public:
    SmokeDetector* createSmokeDetector(int id) override {
        Logger::getInstance()->log("Factory creating Smoke Detector (ID: " + to_string(id) + ")");
        return new SmokeDetector(id);
    }

    GasDetector* createGasDetector(int id) override {
        Logger::getInstance()->log("Factory creating Gas Detector (ID: " + to_string(id) + ")");
        return new GasDetector(id);
    }
};

#endif // SENSORS_H