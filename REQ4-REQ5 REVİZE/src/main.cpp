#include <iostream>
#include "Logger.h"
#include "Sensors.h"

using namespace std;

// Basit bir Observer Testi (REQ 9 Testi)
class SimpleObserver : public IObserver {
public:
    void update(Device* device) override {
        cout << ">>> OBSERVER NOTIFICATION: " << device->getName()
            << " state changed! <<<" << endl;
    }
};

int main() {
    cout << "--- MSH SYSTEM STARTING (INTEGRATION TEST) ---\n" << endl;

    // 1. Logger Testi
    Logger::getInstance()->log("System initialized with NEW Device.h Structure.");

    // 2. Factory Testi (Dedektörler)
    DetectorFactory* factory = new SecurityDeviceFactory();

    Device* smokeSensor = factory->createSmokeDetector(101);

    // Observer Testi (Arkadaþýnýn eklediði yeni özelliði test ediyoruz)
    SimpleObserver* obs = new SimpleObserver();
    smokeSensor->attach(obs); // Dedektöre gözlemci ekle

    // Açma Testi
    smokeSensor->powerOn(); // Observer tetiklenmeli

    // Operate Testi (Yeni fonksiyon)
    smokeSensor->operate();

    // Kapatma Testi (Dedektör olduðu için KAPANMAMALI)
    cout << "\n[TEST] Trying to turn off Smoke Detector..." << endl;
    smokeSensor->powerOff();

    // 3. Light ve Clone Testi
    cout << "\n[TEST] Prototype Pattern (Light Cloning)..." << endl;

    Light* l1 = new Light(201, "Salon Isigi", 80);
    l1->powerOn();

    // Klonlama
    Device* l2 = l1->clone();
    l2->setId(202); // Yeni Base Class'ta setId var, onu kullanýyoruz
    l2->powerOn();

    // Temizlik
    delete factory;
    delete smokeSensor;
    delete l1;
    delete l2;
    delete obs;

    cout << "\n--- SYSTEM SHUTDOWN ---" << endl;
    system("pause");
    return 0;
}