#ifndef CHANGEMODECOMMAND_H
#define CHANGEMODECOMMAND_H

#include "IMenuCommand.h"
#include <iostream>

class ChangeModeCommand : public IMenuCommand {
public:
    void execute() override {
        std::cout << "\n--- MOD SECIMI ---" << std::endl;
        std::cout << "[N] Normal" << std::endl;
        std::cout << "[E] Emergency" << std::endl;
        std::cout << "[P] Panic" << std::endl;
        std::cout << "[C] Child Lock" << std::endl;
        std::cout << "Seciminiz: ";
        
        char mode;
        std::cin >> mode;
        std::cout << "[LOG] Mod degistirildi: " << mode << std::endl;
    }

    std::string getDescription() const override {
        return "Mod Degistir";
    }
};

#endif