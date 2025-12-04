#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <map>
#include <iostream>
#include "IMenuCommand.h"

class MenuHandler {
private:
    std::map<int, IMenuCommand*> commands;

public:
    ~MenuHandler() {
        for (auto const& [key, val] : commands) {
            delete val;
        }
        commands.clear();
    }

    void registerCommand(int id, IMenuCommand* cmd) {
        commands[id] = cmd;
    }

    void displayMenu() {
        std::cout << "\n========================================" << std::endl;
        std::cout << "          MY SWEET HOME (MSH)" << std::endl;
        std::cout << "========================================" << std::endl;
        
        for (auto const& [key, val] : commands) {
            std::cout << "[" << key << "] " << val->getDescription() << std::endl;
        }
        
        if (commands.find(10) == commands.end()) {
             std::cout << "[10] Kapat (Shutdown)" << std::endl;
        }

        std::cout << "========================================" << std::endl;
        std::cout << "Seciminiz: ";
    }

    void executeCommand(int choice) {
        if (commands.find(choice) != commands.end()) {
            commands[choice]->execute();
        } else {
            std::cout << "HATALI GIRIS! Gecerli bir secenek giriniz." << std::endl;
        }
    }
};

#endif