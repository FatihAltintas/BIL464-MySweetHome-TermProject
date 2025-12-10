#ifndef CHANGESTATECOMMAND_H
#define CHANGESTATECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

class ChangeStateCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    ChangeStateCommand(MSHSystem* sys) : system(sys) {}

    void execute() {
        char choice;
        cout << "\n--- [7] CHANGE STATE ---\n";
        cout << "(N)ormal\n";
        cout << "(H)igh Performance\n";
        cout << "(L)ow Power\n";
        cout << "(S)leep\n";
        cout << "(P)revious one (UNDO)\n"; 
        cout << "Select State: ";

        if (cin >> choice) {
            choice = toupper(choice);
            switch (choice) {
                case 'N': 
                    cout << ">> State set to NORMAL.\n"; 
                    break;
                case 'H': 
                    cout << ">> State set to HIGH PERFORMANCE.\n"; 
                    break;
                case 'L': 
                    cout << ">> State set to LOW POWER.\n"; 
                    
                    break;
                case 'S': 
                    cout << ">> State set to SLEEP.\n"; 
                    
                    system->changeMode(MODE_EVENING); 
                    break;
                case 'P': 
                    cout << ">> Restoring Previous State...\n";
                    system->restorePreviousMode();
                    break;
                default: cout << "[ERROR] Invalid Option!\n";
            }
        } else {
            cin.clear(); cin.ignore(10000, '\n');
        }
        cout << "Press Enter to continue...";
        cin.ignore(10000, '\n'); cin.get();
    }

    string getDescription() const { return "Change State - (N, H, L, S, P)"; }
};

#endif