#ifndef CHANGEMODECOMMAND_H
#define CHANGEMODECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include "ModeManager.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

class ChangeModeCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    ChangeModeCommand(MSHSystem* sys) : system(sys) {}

    void execute() {
        char choice;
        cout << "\n--- [6] CHANGE MODE ---\n";
        cout << "(N)ormal\n";
        cout << "(E)vening\n";
        cout << "(P)arty\n";
        cout << "(C)inema\n";
        cout << "Select Mode: ";

        if (cin >> choice) {
            choice = toupper(choice);
            switch (choice) {
                case 'N': system->changeMode(MODE_NORMAL); break;
                case 'E': system->changeMode(MODE_EVENING); break;
                case 'P': system->changeMode(MODE_PARTY); break;
                case 'C': system->changeMode(MODE_CINEMA); break;
                default: cout << "[ERROR] Invalid Option!\n";
            }
        } else {
            cin.clear(); cin.ignore(10000, '\n');
        }
        cout << "Press Enter to continue...";
        cin.ignore(10000, '\n'); cin.get();
    }

    string getDescription() const { return "Change Mode - (N)ormal, (E)vening, (P)arty, (C)inema"; }
};

#endif