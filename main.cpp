#include <iostream>
#include "include/MSHSystem.h"         // ERHAN (System)
#include "include/MSHMenuController.h" // AYBERK (Menu)
#include "include/Light.h"             // ERHAN (Light)
#include "include/Logger.h"            // EMRE (Logger - REQ4)
#include "include/Sensors.h"           // EMRE (Sensors - REQ5)

using namespace std;

// --- ERHAN'IN TESTLERİ ---
void runErhanTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ERHAN'S MODULE (REQ10-12) STARTING ===\n";
    Light* l1 = new Light("Test Oturma Odasi", 101);
    l1->powerOn();
    system->addDevice(l1);
    system->duplicateDevice(0, 102); 
    system->changeMode("Night Mode");
    system->restorePreviousMode();
    cout << "=== [AUTO-TEST] ERHAN DONE ===\n";
}

// --- EMRE'NİN TESTLERİ (REQ4-5) ---
void runEmreTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] EMRE'S MODULE (REQ4-5) STARTING ===\n";
    
    // REQ4: Logger Testi
    // Emre'nin Logger'i Singleton ise boyle cagirilir:
    Logger::getInstance()->log("[MAIN] Emre's module initialized.");
    
    // REQ5: Sensor/Detector Testi (Factory Kullanimi)
    // Emre'nin kodundaki Factory yapisina gore:
    DetectorFactory* factory = new SecurityDeviceFactory();
    
    // Duman sensoru olustur
    Device* smokeSensor = factory->createSmokeDetector(201);
    smokeSensor->operate(); // Calistigini gorelim
    
    // Sisteme ekle
    system->addDevice(smokeSensor);
    
    cout << "=== [AUTO-TEST] EMRE DONE ===\n";
    
    // Temizlik
    delete factory;
}

int main() {
    cout << "==========================================" << endl;
    cout << "   MY SWEET HOME - INTEGRATED SYSTEM v2   " << endl;
    cout << "==========================================" << endl;

    // 1. Loglama Başlat (Emre)
    Logger::getInstance()->log("System Booting up...");

    // 2. Ana Sistem Başlat (Erhan)
    MSHSystem* coreSystem = new MSHSystem();

    // 3. Modül Testleri
    runErhanTests(coreSystem);
    runEmreTests(coreSystem);

    // 4. Menü Başlat (Ayberk)
    cout << "\n>>> MAIN MENU STARTING... <<<\n";
    MSHMenuController* menuApp = new MSHMenuController();
    
    cout << "\n[INFO] Sistem calisiyor. Cikis icin Ctrl+C yapabilirsiniz." << endl;

    // Temizlik
    delete menuApp;
    delete coreSystem;

    return 0;
}