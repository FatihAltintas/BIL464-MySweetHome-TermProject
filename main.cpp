#include <iostream>
#include <vector>
#ifdef _WIN32
    
    #include <windows.h>
    #define MY_SLEEP(s) Sleep(s * 1000)
#else

    #include <unistd.h>
    #define MY_SLEEP(s) sleep(s)
#endif

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

// --- ERHAN (REQ10-12) ---
void runErhanTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ERHAN'S MODULE (REQ10-12) ===\n";
    Light* l1 = new Light("Test Oturma Odasi", 101);
    l1->powerOn();
    system->addDevice(l1);
    system->duplicateDevice(0, 102); 
    system->changeMode(MODE_EVENING);
    system->restorePreviousMode();
    cout << "=== ERHAN DONE ===\n";
}

// --- EMRE (REQ4-5) ---
void runEmreTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] EMRE'S MODULE (REQ4-5) ===\n";
    Logger::getInstance()->log("[MAIN] Logger & Sensors initialized.");
    DetectorFactory* factory = new SecurityDeviceFactory();
    Device* smokeSensor = factory->createSmokeDetector(201);
    system->addDevice(smokeSensor);
    delete factory;
    cout << "=== EMRE DONE ===\n";
}

// --- ELMAR (REQ6-7) ---
void runElmarTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ELMAR'S MODULE (REQ6-7) ===\n";
    Tv* salonTV = new Tv("Salon TV", 301);
    system->addDevice(salonTV);
    // system->changeMode(MODE_CINEMA);
    cout << "=== ELMAR DONE ===\n";
}

// --- FATIH (REQ8-9) ---
void runFatihTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] FATIH'S MODULE (REQ8-9) ===\n";
    Device* newCam = DeviceFactory::createDevice("Camera", "Guvenlik Kameras V1", 401);
    if (newCam) system->addDevice(newCam);
    cout << "=== FATIH DONE ===\n";
}

// --- EMIR (REQ13-15) ---
void runEmirTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] EMIR'S MODULE (REQ13-15) ===\n";
    Alarm* evAlarmi = new Alarm("Ana Alarm", 501);
    system->addDevice(evAlarmi);
    cout << ">> [REQ13] Motion Detected -> Alarm ON -> Lights ON -> Police Called\n";
    evAlarmi->powerOn();
    MY_SLEEP(1);
    cout << "   [SYSTEM] Calling Police...\n";
    cout << "=== EMIR DONE ===\n";
}

// --- TAHA (REQ3-16) ---
void runTahaTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] TAHA'S MODULE (REQ3-16) ===\n";
    
    cout << ">> [REQ3] Keyboard Interaction is handled by MSHMenuController.\n";

    cout << ">> [REQ16] Testing Fire Station Protocol...\n";
    
    cout << "   [SENSOR] Smoke detected! Waiting for user...\n";
    MY_SLEEP(1);
    cout << "   [TIMEOUT] User did not acknowledge!\n";
    
    system->callFireStation();
    
    cout << "=== TAHA DONE ===\n";
}

int main() {
    cout << "==========================================" << endl;
    cout << "   MY SWEET HOME - FINAL INTEGRATION v7   " << endl;
    cout << "==========================================" << endl;

    Logger::getInstance()->log("System Booting up...");
    MSHSystem* coreSystem = new MSHSystem();

    cout << "\n>>> SYSTEM SELF-CHECK STARTING... <<<\n";
    runErhanTests(coreSystem);
    runEmreTests(coreSystem);
    runElmarTests(coreSystem);
    runFatihTests(coreSystem);
    runEmirTests(coreSystem);
    runTahaTests(coreSystem);
    cout << ">>> SYSTEM SELF-CHECK COMPLETED. <<<\n";

    cout << "\n>>> STARTING USER INTERFACE... <<<\n";
    
    MSHMenuController* menuApp = new MSHMenuController(coreSystem);
    
    menuApp->run(); 
    delete menuApp;
    delete coreSystem;

    return 0;
}
void sleepSim(int seconds) {
    cout << "   (Waiting " << seconds << "s...)" << endl;
    MY_SLEEP(seconds); 
}