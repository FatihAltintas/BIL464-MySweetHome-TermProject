#ifndef REMOVEDEVICECOMMAND_H
#define REMOVEDEVICECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <iostream>
#include <limits>

using namespace std;

class RemoveDeviceCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    RemoveDeviceCommand(MSHSystem* sys) : system(sys) {}

    void execute() {
        int id;
        cout << "--- CIHAZ SILME ISLEMI ---\n";
        cout << "Silinecek Cihazin ID'sini giriniz: ";
        
        if (cin >> id) {
            system->removeDevice(id); 
        } else {
            cout << "[HATA] Gecersiz giris! Sayi girmelisiniz.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Devam etmek icin Enter'a basin...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    string getDescription() const {
        return "Cihaz Sil (Remove Device)";
    }
};

#endif