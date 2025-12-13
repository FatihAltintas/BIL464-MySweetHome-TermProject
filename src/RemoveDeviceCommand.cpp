#include "RemoveDeviceCommand.h"
#include <iostream>
#include <limits>

using namespace std;

// Constructor
RemoveDeviceCommand::RemoveDeviceCommand(MSHSystem* sys) : system(sys) {}

// Destructor
RemoveDeviceCommand::~RemoveDeviceCommand() {}

// Execute: Kullanicidan ID alip silme islemini yapar
void RemoveDeviceCommand::execute() {
    int id;
    cout << "\n--- CIHAZ SILME ISLEMI ---\n";
    cout << "Silinecek Cihazin ID'sini giriniz: ";
    
    if (cin >> id) {
        // MSHSystem uzerinden silme islemini cagir
        system->removeDevice(id);
        // Not: Basarili/Basarisiz bilgisini MSHSystem ekrana/loga yaziyor zaten.
    } else {
        cout << "[HATA] Gecersiz giris! Sayi girmelisiniz.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Bekleme
    cout << "Devam etmek icin Enter'a basin...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Onceki inputtan kalani temizle
    cin.get(); // Bekle
}

string RemoveDeviceCommand::getDescription() const {
    return "Cihaz Sil (Remove Device)";
}