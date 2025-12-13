#include "ShowManualCommand.h"
#include <iostream>
#include <limits>
#include <cstdlib> // system() fonksiyonu icin

using namespace std;

// Destructor
ShowManualCommand::~ShowManualCommand() {}

// Execute
void ShowManualCommand::execute() {
    // Ekran temizleme (Platforma gore)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    loadManualText();
    waitForKeyInput();
}

// Menu Aciklamasi
string ShowManualCommand::getDescription() const {
    return "Kullanim Kilavuzu (Help)";
}

// Yardimci Fonksiyon: Metni Yazdir
void ShowManualCommand::loadManualText() {
    cout << "========================================" << endl;
    cout << "      MY SWEET HOME - KULLANIM KILAVUZU " << endl;
    cout << "========================================" << endl;
    cout << "1. Cihaz eklemek icin ilgili menuyu kullanin." << endl;
    cout << "2. Mod degisimi icin kodlari (N, E, P, C) girin." << endl;
    cout << "3. Cikis icin 10 tusuna basin." << endl;
    cout << "========================================" << endl;
}

// Yardimci Fonksiyon: Bekle
void ShowManualCommand::waitForKeyInput() {
    cout << "\nAna menuye donmek icin [Enter] tusuna basin...";
    // Onceki input buffer'i temizle
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}