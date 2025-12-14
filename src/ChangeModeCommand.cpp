#include "ChangeModeCommand.h"
#include "ModeManager.h" // MODE_NORMAL, MODE_CINEMA vb.
#include <iostream>
#include <limits>
#include <cctype> // toupper fonksiyonu icin

using namespace std;

// Constructor
ChangeModeCommand::ChangeModeCommand(MSHSystem* sys) : system(sys) {}

// Destructor
ChangeModeCommand::~ChangeModeCommand() {}

// Execute: Mod degistirme menusu
void ChangeModeCommand::execute() {
    char choice;
    cout << "\n--- [6] CHANGE MODE ---\n";
    cout << "(N)ormal\n";
    cout << "(E)vening\n";
    cout << "(P)arty\n";
    cout << "(C)inema\n";
    cout << "Select Mode: ";

    if (cin >> choice) {
        choice = toupper(choice); // Kucuk harf girilirse buyut
        
        switch (choice) {
            case 'N': system->changeMode(MODE_NORMAL); break;
            case 'E': system->changeMode(MODE_EVENING); break;
            case 'P': system->changeMode(MODE_PARTY); break;
            case 'C': system->changeMode(MODE_CINEMA); break;
            default: cout << "[ERROR] Invalid Option!\n";
        }
    } else {
        cout << "[HATA] Gecersiz giris.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Bekleme
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string ChangeModeCommand::getDescription() const {
    return "Change Mode - (N)ormal, (E)vening, (P)arty, (C)inema";
}