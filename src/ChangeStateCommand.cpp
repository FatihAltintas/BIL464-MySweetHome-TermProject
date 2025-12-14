#include "ChangeStateCommand.h"
#include "ModeManager.h" // Enum degerleri icin gerekli
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

// Constructor
ChangeStateCommand::ChangeStateCommand(MSHSystem* sys) : system(sys) {}

// Destructor
ChangeStateCommand::~ChangeStateCommand() {}

// Execute: Durum Degistirme Menusu
void ChangeStateCommand::execute() {
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
                // Memento Pattern Devrede: Undo
                system->restorePreviousMode();
                break;
            default: cout << "[ERROR] Invalid Option!\n";
        }
    } else {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // Bekleme
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();
}

string ChangeStateCommand::getDescription() const {
    return "Change State - (N, H, L, S, P)";
}