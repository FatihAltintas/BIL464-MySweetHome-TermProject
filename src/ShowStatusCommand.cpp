#include "ShowStatusCommand.h"
#include <iostream>
#include <limits> // numeric_limits icin

using namespace std;

// Constructor
ShowStatusCommand::ShowStatusCommand(MSHSystem* sys) : system(sys) {}

// Destructor
ShowStatusCommand::~ShowStatusCommand() {}

// Komutu Calistir
void ShowStatusCommand::execute() {
    // MSHSystem uzerinden listeleme fonksiyonunu cagir
    if (system) {
        system->listDevices();
    } else {
        cout << "HATA: Sistem baglantisi yok!" << endl;
    }

    // Kullanicinin okumasi icin beklet
    cout << "\nDevam etmek icin Enter'a basin...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Menudeki Ismi
string ShowStatusCommand::getDescription() const {
    return "Ev Durumu (Status)";
}