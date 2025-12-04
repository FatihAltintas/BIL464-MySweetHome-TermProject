#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "IMenuCommand.h"
#include "Device.h"
#include <iostream>

class AddDeviceCommand : public IMenuCommand {
public:
    void execute()  {
        showDeviceSubMenu();
        int choice;
        std::cin >> choice;
        
        std::cout << "[LOG] " << choice << " nolu cihaz secimi alindi. (Henuz implemente edilmedi)" << std::endl;
    }

    std::string getDescription() const  {
        return "Cihaz Ekle / Yonet";
    }

private:
    void showDeviceSubMenu() {

        std::cout << "\n--- CIHAZ TURU SECIN ---" << std::endl;
        std::cout << "[1] Light" << std::endl;
        std::cout << "[2] Detector" << std::endl;
        std::cout << "[3] Camera" << std::endl;
        std::cout << "[4] TV" << std::endl;
        std::cout << "Seciminiz: ";
    }
};

#endif