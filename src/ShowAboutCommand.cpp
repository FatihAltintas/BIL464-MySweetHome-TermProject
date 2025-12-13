#include "ShowAboutCommand.h"
#include <iostream>
#include <limits> // numeric_limits icin

using namespace std;

// Destructor
ShowAboutCommand::~ShowAboutCommand() {}

// Execute
void ShowAboutCommand::execute() {
    cout << "\n--- GELISTIRICILER ---" << endl;
    cout << "EMIR RIDVAN AKTAS" << endl;
    cout << "AYBERK DOGAN" << endl;
    cout << "FATIH ALTINTAS" << endl;
    cout << "ERHAN BULBUL" << endl;
    cout << "TAHA IBRAHIM BAG" << endl;
    cout << "HUSEYIN EMRE ALAN" << endl;
    cout << "ELMAR OSMANOV" << endl;

    cout << "\nAna menuye donmek icin [Enter] tusuna basin...";
    // Input temizleme ve bekleme
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string ShowAboutCommand::getDescription() const {
    return "Hakkinda (About)";
}