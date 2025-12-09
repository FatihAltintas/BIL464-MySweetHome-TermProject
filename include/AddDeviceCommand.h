#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include "DeviceFactory.h"
#include <iostream>
#include <string>

using namespace std;

class AddDeviceCommand : public IMenuCommand {
private:
    MSHSystem* system;
public:
    AddDeviceCommand(MSHSystem* sys) : system(sys) {}

    void execute() {
        int typeChoice, id;
        string name;
        
        cout << "--- CIHAZ EKLEME SIHIRBAZI ---\n";
        cout << "Tur Secin: [1] Light, [2] TV, [3] Camera\nSecim: ";
        cin >> typeChoice;
        
        cout << "ID Giriniz (Orn: 505): ";
        cin >> id;
        cout << "Isim Giriniz (Bosluksuz, Orn: Mutfak_Isigi): ";
        cin >> name;

        Device* d = NULL;
        if (typeChoice == 1) d = DeviceFactory::createDevice("Light", name, id);
        else if (typeChoice == 2) d = DeviceFactory::createDevice("Tv", name, id);
        else if (typeChoice == 3) d = DeviceFactory::createDevice("Camera", name, id);

        if (d) {
            system->addDevice(d);
            cout << "[BASARILI] Cihaz eklendi!\n";
        } else {
            cout << "[HATA] Gecersiz secim.\n";
        }
        
        cout << "Devam...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    string getDescription() const { return "Cihaz Ekle"; }
};
#endif