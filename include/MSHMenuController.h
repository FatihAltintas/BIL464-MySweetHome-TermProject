#ifndef MSHMENUCONTROLLER_H  
#define MSHMENUCONTROLLER_H  

#include "MenuHandler.h"
#include "ShowManualCommand.h"
#include "AddDeviceCommand.h"
#include "ChangeModeCommand.h"
#include "ShowAboutCommand.h"
#include "CommandStubs.h"

class MSHMenuController {
private:
    bool isRunning;
    MenuHandler menuHandler;

public:
     MSHMenuController() : isRunning(true) {
        menuHandler.registerCommand(1, new ShowStatusCommand());

        menuHandler.registerCommand(2, new AddDeviceCommand()); 

        menuHandler.registerCommand(3, new RemoveDeviceCommand());

        menuHandler.registerCommand(4, new PowerOnCommand());

        menuHandler.registerCommand(5, new PowerOffCommand());

        menuHandler.registerCommand(6, new ChangeModeCommand());

        menuHandler.registerCommand(7, new ChangeStateCommand());

        menuHandler.registerCommand(8, new ShowManualCommand());

        menuHandler.registerCommand(9, new ShowAboutCommand());
    }

    void run() {
        int choice;
        while (isRunning) {
            menuHandler.displayMenu();

            if (!(std::cin >> choice)) {
                std::cout << "HATALI GIRIS! Sayi girmelisiniz." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n'); 
                continue;
            }

            if (choice == 10) {
                shutdown();
            } else {
                menuHandler.executeCommand(choice);
            }
        }
    }

    void shutdown() {
        std::cout << "Sistem kapatiliyor... Gule gule!" << std::endl;
        isRunning = false;
    }
};

#endif