#include "PowerOnCommand.h"
#include "Device.h" // Device fonksiyonlarini (powerOn) kullanmak icin
#include <iostream>
#include <limits>

using namespace std;

PowerOnCommand::PowerOnCommand(MSHSystem* sys) : system(sys) {}

PowerOnCommand::~PowerOnCommand() {}

void PowerOnCommand::execute() {
    int id;
    cout << "\n>> Acilacak Cihaz ID'sini giriniz: ";
    
    if (cin >> id) {
        Device* d = system->getDevice(id);
        if (d) {
            d->powerOn(); // Cihazin kendi powerOn fonksiyonunu cagir
            // Not: Basarili mesaji ve loglama Device::powerOn icinde yapiliyor.
        } else {
            cout << "[HATA] Bu ID ile cihaz bulunamadi!\n";
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

string PowerOnCommand::getDescription() const {
    return "Cihaz Ac (Power On)";
}