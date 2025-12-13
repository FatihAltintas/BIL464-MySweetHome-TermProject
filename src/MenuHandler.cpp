#include "MenuHandler.h"
#include <iostream>
#include <string>

using namespace std;

// Destructor: Hafizadaki komut nesnelerini temizler
MenuHandler::~MenuHandler() {
    for (std::map<int, IMenuCommand*>::iterator it = commands.begin(); it != commands.end(); ++it) {
        delete it->second;
    }
    commands.clear();
}

// Komut Kaydet
void MenuHandler::registerCommand(int key, IMenuCommand* command) {
    commands[key] = command;
}

// Menuyu Listele
void MenuHandler::displayMenu() {
    cout << "\n========================================" << endl;
    cout << "        MY SWEET HOME (MSH) MENU        " << endl;
    cout << "========================================" << endl;
    
    // Const Iterator ile dolasiyoruz (Okuma amacli)
    for (std::map<int, IMenuCommand*>::const_iterator it = commands.begin(); it != commands.end(); ++it) {
        cout << "[" << it->first << "] " << it->second->getDescription() << endl;
    }
    
    cout << "----------------------------------------" << endl;
    // Not: "Seciminiz: " yazisini Controller'a biraktik ama burada kalsa da sorun olmaz.
    // Tutarlilik icin Controller yapiyor zaten.
}

// Komutu Calistir
void MenuHandler::executeCommand(int choice) {
    std::map<int, IMenuCommand*>::iterator it = commands.find(choice);
    
    if (it != commands.end()) {
        it->second->execute();
    } else {
        cout << "Gecersiz secim!" << endl;
    }
}