#ifndef SHOWMANUALCOMMAND_H
#define SHOWMANUALCOMMAND_H

#include "IMenuCommand.h"
#include <iostream>
#include <limits>

class ShowManualCommand : public IMenuCommand {
public:
    void execute() override {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        loadManualText();
        waitForKeyInput();
    }

    std::string getDescription() const override {
        return "Kullanim Kilavuzu (Help)";
    }

private:
    void loadManualText() {
        std::cout << "========================================" << std::endl;
        std::cout << "      MY SWEET HOME - KULLANIM KILAVUZU " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Cihaz eklemek icin ilgili menuyu kullanin." << std::endl;
        std::cout << "2. Mod degisimi icin kodlari (N, E, P, C) girin." << std::endl;
        std::cout << "3. Cikis icin 10 tusuna basin." << std::endl;
        std::cout << "========================================" << std::endl;
    }

    void waitForKeyInput() {
        std::cout << "\nAna menuye donmek icin [Enter] tusuna basin...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cin.get();
    }
};

#endif