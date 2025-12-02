#include <iostream>
#include "Logger.h"
#include "Sensors.h"

using namespace std;

int main() {
    cout << "--- MSH SYSTEM STARTING ---\n" << endl;

    // 1. Logger Testi
    Logger::getInstance()->log("System initialized.");

    // 2. Factory Testi
    DetectorFactory* factory = new SecurityDeviceFactory();
    Device* smokeSensor = factory->createSmokeDetector(101);

    smokeSensor->powerOn();
    smokeSensor->powerOff(); // Uyari vermeli (Kapatilamaz)

    // 3. Light ve Clone Testi
    Light* l1 = new Light(201, "Salon Isigi", 80);
    l1->powerOn();

    Device* l2 = l1->clone();
    l2->setID(202);
    l2->powerOn();

    // Temizlik
    delete factory;
    delete smokeSensor;
    delete l1;
    delete l2;

    cout << "\n--- SYSTEM SHUTDOWN ---" << endl;
    system("pause");
    return 0;
}