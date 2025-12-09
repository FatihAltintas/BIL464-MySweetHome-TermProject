#ifndef POWERONCOMMAND_H
#define POWERONCOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <iostream>
#include <limits>

using namespace std;

class PowerOnCommand : public IMenuCommand {
private:
    MSHSystem* system; 
public:
    PowerOnCommand(MSHSystem* sys) : system(sys) {}

    void execute() {
        int id;
        cout << ">> Acilacak Cihaz ID'sini giriniz: ";
        if (cin >> id) {
            Device* d = system->getDevice(id);
            if (d) {
                d->powerOn();
            } else {
                cout << "[HATA] Bu ID ile cihaz bulunamadi!\n";
            }
        } else {
            cout << "[HATA] Gecersiz giris.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Devam etmek icin Enter'a basin...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    string getDescription() const { return "Cihaz Ac (Power On)"; }
};
#endif