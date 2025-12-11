#include <iostream>
#include "include/MSHSystem.h"
#include "include/Light.h"

using namespace std;

int main() {
    cout << "==========================================" << endl;
    cout << "      ERHAN BULBUL - INDIVIDUAL MODULE    " << endl;
    cout << "      REQ10, REQ11, REQ12 TEST SYSTEM     " << endl;
    cout << "==========================================" << endl;

    // 1. Sistemi Ayaga Kaldir
    MSHSystem* system = new MSHSystem();

    // 2. Test Cihazi Ekle (Base Class Testi)
    cout << "\n>>> [INIT] Creating Initial Device...\n";
    Light* l1 = new Light("Oturma Odasi Isigi", 101);
    l1->powerOn(); // Acik baslasin
    system->addDevice(l1);

    // 3. REQ10 TESTI: Prototype Pattern (Klonlama)
    // Beklenti: Ayni ayarlarda yeni bir cihaz olusmali
    cout << "\n>>> [REQ10] TESTING PROTOTYPE PATTERN (CLONING)...\n";
    system->duplicateDevice(0, 102); 
    system->listDevices();

    // 4. REQ11 TESTI: Memento Pattern (Save State)
    // Beklenti: Mod degisince eski durum hafizaya atilmali
    cout << "\n>>> [REQ11] TESTING MEMENTO SAVE (CHANGE MODE)...\n";
    system->changeMode("Child Lock"); // Ornek olarak cocuk kilidi (her seyi kapatir)
    system->listDevices();

    // 5. REQ12 TESTI: Memento Pattern (Undo/Restore)
    // Beklenti: Geri alinca isiklar tekrar acilmali
    cout << "\n>>> [REQ12] TESTING MEMENTO RESTORE (UNDO)...\n";
    system->restorePreviousMode();
    system->listDevices();

    // Temizlik
    delete system;

    cout << "\n=== INDIVIDUAL TEST COMPLETED SUCCESSFULLY ===\n";
    return 0;
}
