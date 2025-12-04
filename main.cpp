#include <iostream>
#include "include/MSHSystem.h"         // ERHAN (System & ModeManager)
#include "include/MSHMenuController.h" // AYBERK (Menu)
#include "include/Light.h"             // ERHAN (Light)
#include "include/Logger.h"            // EMRE (Logger)
#include "include/Sensors.h"           // EMRE (Sensors)

// ELMAR'IN DOSYALARI (Include klasörüne taşıdığını varsayıyorum)
// Dosya adları büyük/küçük harf duyarlıdır, klasöründekiyle aynı olmalı.
#include "include/Tv.h"      
#include "include/Camera.h"
#include "include/Alarm.h"

using namespace std;

// --- ERHAN'IN TESTLERİ (REQ10-12) ---
void runErhanTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ERHAN'S MODULE (REQ10-12) STARTING ===\n";
    
    // Test Cihazı
    Light* l1 = new Light("Test Oturma Odasi", 101);
    l1->powerOn();
    system->addDevice(l1);

    // REQ10: Klonlama
    system->duplicateDevice(0, 102); 

    // REQ11: Mod Değişimi (DÜZELTİLDİ: String yerine Enum kullanıldı)
    // "Night Mode" -> MODE_NIGHT
    system->changeMode(MODE_NIGHT);

    // REQ12: Geri Alma
    system->restorePreviousMode();
    
    cout << "=== [AUTO-TEST] ERHAN DONE ===\n";
}

// --- EMRE'NİN TESTLERİ (REQ4-5) ---
void runEmreTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] EMRE'S MODULE (REQ4-5) STARTING ===\n";
    
    // REQ4: Logger
    Logger::getInstance()->log("[MAIN] Emre's module initialized.");
    
    // REQ5: Factory Pattern
    DetectorFactory* factory = new SecurityDeviceFactory();
    Device* smokeSensor = factory->createSmokeDetector(201);
    
    // Cihazı çalıştır ve ekle
    smokeSensor->operate();
    system->addDevice(smokeSensor);
    
    cout << "=== [AUTO-TEST] EMRE DONE ===\n";
    
    // Temizlik
    delete factory;
}

// --- ELMAR'IN TESTLERİ (REQ6-7) ---
void runElmarTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ELMAR'S MODULE (REQ6-7) STARTING ===\n";
    
    // REQ6: Yeni Cihazlar (TV, Camera)
    // Elmar'ın dosyalarını include klasörüne attıysan burası çalışır
    // Constructor'larını (isim, id) şeklinde düzelttiğini varsayıyorum.
    
    Tv* salonTV = new Tv("Salon TV", 301);
    salonTV->powerOff(); // Başlangıçta kapalı olsun
    system->addDevice(salonTV);

    Camera* kapiKamerasi = new Camera("Dis Kapi Kamerasi", 302);
    system->addDevice(kapiKamerasi);

    // REQ7: Sinema Modu Testi (DÜZELTİLDİ: String yerine Enum)
    cout << ">> Testing Cinema Mode (TVs should turn ON, Lights OFF):\n";
    system->changeMode(MODE_CINEMA); 
    
    cout << "=== [AUTO-TEST] ELMAR DONE ===\n";
}

int main() {
    cout << "==========================================" << endl;
    cout << "   MY SWEET HOME - INTEGRATED SYSTEM v3   " << endl;
    cout << "==========================================" << endl;

    // 1. Loglama Başlat
    Logger::getInstance()->log("System Booting up...");

    // 2. Ana Sistem Başlat
    MSHSystem* coreSystem = new MSHSystem();

    // 3. BÜTÜN MODÜLLERİ TEST ET
    runErhanTests(coreSystem);
    runEmreTests(coreSystem);
    runElmarTests(coreSystem);

    // 4. MENÜYÜ BAŞLAT (Ayberk)
    cout << "\n>>> MAIN MENU STARTING... <<<\n";
    MSHMenuController* menuApp = new MSHMenuController();
    
    cout << "\n[INFO] Sistem calisiyor. Menuden islem yapabilirsiniz." << endl;
    // Konsolun hemen kapanmaması için basit bir durdurucu (Opsiyonel)
    // char c; cin >> c; 

    // Temizlik
    delete menuApp;
    delete coreSystem;

    return 0;
}