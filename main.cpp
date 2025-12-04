#include <iostream>
#include "include/MSHSystem.h"         // SENIN SİSTEMİN (Backend)
#include "include/MSHMenuController.h" // AYBERK'İN MENÜSÜ (Frontend - İsmi değiştirdik)
#include "include/Light.h"

using namespace std;

// Senin test kodlarını bir fonksiyona aldık ki main temiz kalsın
void runErhanTests(MSHSystem* system) {
    cout << "\n=== [AUTO-TEST] ERHAN'S MODULE (REQ10-12) STARTING ===\n";
    
    // Test Cihazı Ekle
    Light* l1 = new Light("Test Oturma Odasi", 101);
    l1->powerOn();
    system->addDevice(l1);

    // REQ10 Testi
    system->duplicateDevice(0, 102); 

    // REQ11 Testi
    system->changeMode("Night Mode");

    // REQ12 Testi
    system->restorePreviousMode();
    
    cout << "=== [AUTO-TEST] COMPLETED SUCCESSFULLY ===\n\n";
}

int main() {
    cout << "==========================================" << endl;
    cout << "   MY SWEET HOME - INTEGRATED SYSTEM v1   " << endl;
    cout << "==========================================" << endl;

    // 1. ANA SİSTEMİ BAŞLAT (Senin yazdığın beyin)
    MSHSystem* coreSystem = new MSHSystem();

    // 2. OTOMATİK TESTLERİ ÇALIŞTIR (Senin modül kanıtın)
    runErhanTests(coreSystem);

    // 3. MENÜ SİSTEMİNİ BAŞLAT (Ayberk'in yazdığı arayüz)
    cout << ">>> MAIN MENU STARTING... <<<\n";
    
    // Ayberk'in menüsü başlatılıyor
    MSHMenuController* menuApp = new MSHMenuController();
    
    // NOT: Ayberk menü döngüsünü Constructor içinde başlatmış olabilir.
    // Veya 'run()' diye bir fonksiyonu varsa onu çağırmalıyız.
    // Şimdilik nesneyi oluşturmak menüyü hazırlayacaktır.
    
    // --- BURAYA DİKKAT ---
    // Eğer Ayberk'in kodunda menüyü ekranda tutan bir döngü yoksa program hemen kapanır.
    // Menüyü ekranda tutmak için geçici bir durdurma koyalım:
    cout << "\n[INFO] Sistem calisiyor. Cikis icin Ctrl+C yapabilirsiniz." << endl;
    // int dummy; cin >> dummy; // Programın kapanmasını engellemek için

    // Temizlik
    delete menuApp;
    delete coreSystem;

    return 0;
}