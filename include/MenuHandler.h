#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include "IMenuCommand.h"
#include <map>
#include <iostream>
#include <string>

class MenuHandler {
private:
    std::map<int, IMenuCommand*> commands;

public:
    ~MenuHandler() {
        // C++98 Uyumlu map temizleme (Iterator kullanarak)
        for (std::map<int, IMenuCommand*>::iterator it = commands.begin(); it != commands.end(); ++it) {
            delete it->second;
        }
        commands.clear();
    }

    void registerCommand(int key, IMenuCommand* command) {
        commands[key] = command;
    }

    void displayMenu() {
        std::cout << "\n========================================\n";
        std::cout << "        MY SWEET HOME (MSH) MENU        \n";
        std::cout << "========================================\n";
        
        for (std::map<int, IMenuCommand*>::const_iterator it = commands.begin(); it != commands.end(); ++it) {
            std::cout << "[" << it->first << "] " << it->second->getDescription() << std::endl;
        }
        std::cout << "----------------------------------------\n";
        std::cout << "Seciminiz: ";
    }

    void executeCommand(int choice) {
        std::map<int, IMenuCommand*>::iterator it = commands.find(choice);
        
        if (it != commands.end()) {
            it->second->execute();
        } else {
            std::cout << "Gecersiz secim!\n";
        }
    }
};

#endif