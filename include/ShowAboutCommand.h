#ifndef SHOWABOUTCOMMAND_H
#define SHOWABOUTCOMMAND_H

#include "IMenuCommand.h"
#include <iostream>
#include <limits>

class ShowAboutCommand : public IMenuCommand {
public:
    void execute() override {
        std::cout << "\n--- GELISTIRICILER ---" << std::endl;
        std::cout << "EMIR RIDVAN AKTAS" << std::endl;
        std::cout << "AYBERK DOGAN" << std::endl;
        std::cout << "FATIH ALTINTAS" << std::endl;
        std::cout << "ERHAN BULBUL" << std::endl;
        std::cout << "TAHA IBRAHIM BAG" << std::endl;
        std::cout << "HUSEYIN EMRE ALAN" << std::endl;
        std::cout << "ELMAR OSMANOV" << std::endl;

        std::cout << "\nAna menuye donmek icin [Enter] tusuna basin...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    std::string getDescription() const override {
        return "Hakkinda (About)";
    }
};

#endif