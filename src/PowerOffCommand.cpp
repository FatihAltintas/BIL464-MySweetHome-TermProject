#include "PowerOffCommand.h"
#include "Device.h" 
#include <iostream>
#include <limits>

using namespace std;

// Constructor
PowerOffCommand::PowerOffCommand(MSHSystem* sys) : system(sys) {}

// Destructor
PowerOffCommand::~PowerOffCommand() {}

// Execute
void PowerOffCommand::execute() {
    int id;
    cout << "\n>> Kapatilacak Cihaz ID'sini giriniz: ";
    
    if (cin >> id) {
        Device* d = system->getDevice(id);
        if (d) {
            d->powerOff(); // Cihazin kapatma fonksiyonunu cagir
            // Not: Loglama Device::powerOff icinde yapiliyor.
        } else {
            cout << "[HATA] Cihaz bulunamadi!\n";
        }
    } else {
        cout << "[HATA] Gecersiz giris. Sayi girmelisiniz.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Bekleme
    cout << "Devam etmek icin Enter'a basin...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string PowerOffCommand::getDescription() const {
    return "Cihaz Kapat (Power Off)";
}