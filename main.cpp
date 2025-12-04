#include <iostream>
#include "include/MSHSystem.h"         
#include "include/MSHMenuController.h" 
#include "include/Light.h"             
#include "include/Logger.h"            
#include "include/Sensors.h"           
#include "include/Tv.h"
#include "include/Camera.h"
#include "include/Alarm.h"

// FATIH'IN DOSYALARI
#include "include/Strategies.h"
#include "include/DeviceFactory.h"

using namespace std;

// --- ERHAN (REQ10-12) ---
void runErhanTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ERHAN'S MODULE (REQ10-12) STARTING ===\n";
    Light* l1 = new Light("Test Oturma Odasi", 101);
    l1->powerOn();
    system->addDevice(l1);
    system->duplicateDevice(0, 102); 
    system->changeMode(MODE_NIGHT); // Enum kullanimi
    system->restorePreviousMode();
    cout << "=== [AUTO-TEST] ERHAN DONE ===\n";
}

// --- EMRE (REQ4-5) ---
void runEmreTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] EMRE'S MODULE (REQ4-5) STARTING ===\n";
    Logger::getInstance()->log("[MAIN] Emre's module initialized.");
    DetectorFactory* factory = new SecurityDeviceFactory();
    Device* smokeSensor = factory->createSmokeDetector(201);
    system->addDevice(smokeSensor);
    cout << "=== [AUTO-TEST] EMRE DONE ===\n";
    delete factory;
}

// --- ELMAR (REQ6-7) ---
void runElmarTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ELMAR'S MODULE (REQ6-7) STARTING ===\n";
    Tv* salonTV = new Tv("Salon TV", 301);
    system->addDevice(salonTV);
    cout << ">> Testing Cinema Mode:\n";
    system->changeMode(MODE_CINEMA); 
    cout << "=== [AUTO-TEST] ELMAR DONE ===\n";
}

// --- FATIH (REQ8-9) ---
void runFatihTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] FATIH'S MODULE (REQ8-9) STARTING ===\n";

    // REQ8: Infrastructure to add new device (Factory Kullanimi)
    cout << ">> Testing Device Factory (REQ8)...\n";
    Device* newCam = DeviceFactory::createDevice("Camera", "Guvenlik Kamerasi X", 401);
    if (newCam) {
        system->addDevice(newCam);
    }

    // REQ9: Failure Notification (Strategy Kullanimi)
    cout << ">> Testing Failure Notification (REQ9)...\n";
    
    // Strategy olustur (SMS ile bildirim)
    NotificationStrategy* smsStrategy = new SMSStrategy();
    
    // Senaryo: Cihaz bozuluyor ve strateji calisiyor
    // (Normalde bunu cihaza set etmemiz lazim ama Device.h'i bozmamak icin manuel simule edelim)
    
    bool deviceFailed = true; // Simule edilmis ariza
    if (deviceFailed) {
        smsStrategy->notify("Guvenlik Kamerasi X arizalandi! (FAIL STATE)");
        // Gercek hayatta: newCam->setState(FAILED);
    }

    delete smsStrategy;
    cout << "=== [AUTO-TEST] FATIH DONE ===\n";
}

int main() {
    cout << "==========================================" << endl;
    cout << "   MY SWEET HOME - INTEGRATED SYSTEM v4   " << endl;
    cout << "==========================================" << endl;

    Logger::getInstance()->log("System Booting up...");
    MSHSystem* coreSystem = new MSHSystem();

    runErhanTests(coreSystem);
    runEmreTests(coreSystem);
    runElmarTests(coreSystem);
    runFatihTests(coreSystem); // Fatih eklendi

    cout << "\n>>> MAIN MENU STARTING... <<<\n";
    MSHMenuController* menuApp = new MSHMenuController();
    
    cout << "\n[INFO] Sistem calisiyor." << endl;

    delete menuApp;
    delete coreSystem;

    return 0;
}