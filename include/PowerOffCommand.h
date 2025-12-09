#ifndef POWEROFFCOMMAND_H
#define POWEROFFCOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <iostream>

using namespace std;

class PowerOffCommand : public IMenuCommand {
private:
    MSHSystem* system;
public:
    PowerOffCommand(MSHSystem* sys) : system(sys) {}

    void execute() {
        int id;
        cout << ">> Kapatilacak Cihaz ID'sini giriniz: ";
        if (cin >> id) {
            Device* d = system->getDevice(id);
            if (d) {
                d->powerOff();
            } else {
                cout << "[HATA] Cihaz bulunamadi!\n";
            }
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Devam etmek icin Enter'a basin...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    string getDescription() const { return "Cihaz Kapat (Power Off)"; }
};
#endif