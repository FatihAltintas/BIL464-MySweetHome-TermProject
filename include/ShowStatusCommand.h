#ifndef SHOWSTATUSCOMMAND_H
#define SHOWSTATUSCOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <iostream>

class ShowStatusCommand : public IMenuCommand {
private:
    MSHSystem* system;
public:
    ShowStatusCommand(MSHSystem* sys) : system(sys) {}

    void execute() {
        system->listDevices();
        cout << "\nDevam etmek icin Enter'a basin...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    string getDescription() const { return "Ev Durumu (Status)"; }
};
#endif