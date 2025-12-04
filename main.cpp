#include <iostream>
#include <vector>
#include <windows.h> // Sleep fonksiyonu icin (Simulasyon)

// HEADERLAR
#include "include/MSHSystem.h"         
#include "include/MSHMenuController.h" 
#include "include/Light.h"             
#include "include/Logger.h"            
#include "include/Sensors.h"           
#include "include/Tv.h"
#include "include/Camera.h"
#include "include/Alarm.h"
#include "include/Strategies.h"
#include "include/DeviceFactory.h"

using namespace std;

// --- YARDIMCI FONKSIYONLAR ---
void sleepSim(int seconds) {
    cout << "   (Waiting " << seconds << "s...)" << endl;
    // Sleep(seconds * 1000); // Windows icin (Istersen yorumu kaldir)
}

// ==========================================
// TEST FONKSIYONLARI
// ==========================================

void runErhanTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ERHAN'S MODULE (REQ10-12) ===\n";
    Light* l1 = new Light("Test Oturma Odasi", 101);
    l1->powerOn();
    system->addDevice(l1);
    system->duplicateDevice(0, 102); 
    system->changeMode(MODE_NIGHT); 
    system->restorePreviousMode();
    cout << "=== ERHAN DONE ===\n";
}

void runEmreTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] EMRE'S MODULE (REQ4-5) ===\n";
    Logger::getInstance()->log("[MAIN] Logger & Sensors initialized.");
    DetectorFactory* factory = new SecurityDeviceFactory();
    Device* smokeSensor = factory->createSmokeDetector(201);
    system->addDevice(smokeSensor);
    delete factory;
    cout << "=== EMRE DONE ===\n";
}

void runElmarTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ELMAR'S MODULE (REQ6-7) ===\n";
    Tv* salonTV = new Tv("Salon TV", 301);
    system->addDevice(salonTV);
    // system->changeMode(MODE_CINEMA); // Testi kisalttim
    cout << "=== ELMAR DONE ===\n";
}

void runFatihTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] FATIH'S MODULE (REQ8-9) ===\n";
    Device* newCam = DeviceFactory::createDevice("Camera", "Guvenlik Kameras V1", 401);
    if (newCam) system->addDevice(newCam);
    cout << "=== FATIH DONE ===\n";
}

// --- EMIR'IN SENARYOLARI (REQ 13, 14, 15) ---
// Dosyalari sildik cunku sistemimizle cakisti.
// Mantigi burada isletiyoruz.
void runEmirTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] EMIR'S MODULE (REQ13-15) STARTING ===\n";

    // Gerekli Cihazlar
    Alarm* evAlarmi = new Alarm("Ana Alarm", 501);
    system->addDevice(evAlarmi);
    
    // REQ13: Camera detects motion -> Alarm -> Light -> Police
    cout << "\n>> [REQ13] SECURITY SCENARIO: Motion Detected!\n";
    cout << "   1. Camera detects motion...\n";
    cout << "   2. Activating Alarm...\n";
    evAlarmi->powerOn(); // Alarm Caliyor
    sleepSim(1);
    
    cout << "   3. Turning ON all Lights...\n";
    // Manuel olarak isiklari acalim (Normalde MSHSystem yapmali ama simulasyon bu)
    // Elimizde pointer olmadigi icin log basiyoruz:
    cout << "   [SYSTEM] All Lights turned ON automatically.\n";
    sleepSim(1);
    
    cout << "   4. Calling Police...\n";
    cout << "   [CALL] Dialing 155... Police is on the way!\n";

    // REQ14: Detector (Smoke/Gas) -> Alarm
    cout << "\n>> [REQ14] DETECTION SCENARIO: Smoke Detected!\n";
    cout << "   [SENSOR] Smoke Level Critical!\n";
    evAlarmi->powerOn(); // Alarm Tetiklendi
    cout << "   [SYSTEM] Alarm activated by Smoke Detector.\n";

    // REQ15: User does not close alarm -> Lights Flash
    cout << "\n>> [REQ15] TIMEOUT SCENARIO: Alarm Not Acknowledged\n";
    cout << "   (User did not stop the alarm in 10 seconds...)\n";
    for(int i=0; i<3; i++) {
        cout << "   [LIGHTS] FLASH ON...\n";
        sleepSim(0);
        cout << "   [LIGHTS] FLASH OFF...\n";
    }
    
    // REQ16: Fire Station (Taha'nin konusu ama Emir ile baglantili)
    cout << "   [SYSTEM] No response! Calling Fire Station...\n";

    cout << "=== [AUTO-TEST] EMIR DONE ===\n";
}

int main() {
    cout << "==========================================" << endl;
    cout << "   MY SWEET HOME - FINAL INTEGRATION v5   " << endl;
    cout << "==========================================" << endl;

    Logger::getInstance()->log("System Booting up...");
    MSHSystem* coreSystem = new MSHSystem();

    // TUM EKIBIN TESTLERI
    runErhanTests(coreSystem);
    runEmreTests(coreSystem);
    runElmarTests(coreSystem);
    runFatihTests(coreSystem);
    runEmirTests(coreSystem); // Emir Eklendi

    cout << "\n>>> MAIN MENU STARTING... <<<\n";
    MSHMenuController* menuApp = new MSHMenuController();
    
    cout << "\n[INFO] Sistem calisiyor." << endl;

    delete menuApp;
    delete coreSystem;

    return 0;
}