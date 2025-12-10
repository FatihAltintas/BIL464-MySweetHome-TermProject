#ifndef MSHMENUCONTROLLER_H
#define MSHMENUCONTROLLER_H

#include "MenuHandler.h"
#include "MSHSystem.h"
#include "RemoveDeviceCommand.h"
#include "ShowStatusCommand.h"
#include "AddDeviceCommand.h"
#include "PowerOnCommand.h"
#include "PowerOffCommand.h"
#include "CommandStubs.h"
#include "ShowManualCommand.h"
#include "ShowAboutCommand.h"
#include "ChangeModeCommand.h"
#include "ChangeStateCommand.h"


#include <iostream>
#include <limits>

using namespace std;

class MSHMenuController {
private:
    bool isRunning;
    MenuHandler menuHandler;
    MSHSystem* system; 
public:
    
    MSHMenuController(MSHSystem* sys) : isRunning(true), system(sys) {
        
        
        menuHandler.registerCommand(1, new ShowStatusCommand(system)); 
        menuHandler.registerCommand(2, new AddDeviceCommand(system));
        menuHandler.registerCommand(3, new RemoveDeviceCommand(system));
        menuHandler.registerCommand(4, new PowerOnCommand(system)); 
        menuHandler.registerCommand(5, new PowerOffCommand(system));
        
       
        menuHandler.registerCommand(6, new ChangeModeCommand(system));
        menuHandler.registerCommand(7, new ChangeStateCommand(system));
        menuHandler.registerCommand(8, new ShowManualCommand());
        menuHandler.registerCommand(9, new ShowAboutCommand());
        menuHandler.registerCommand(10, new StubCommand("Cikis")); 
    }

    void run() {
        int choice = 0;
        while (choice != 10) {
            menuHandler.displayMenu();
            if (!(cin >> choice)) {
                cout << "Hata: Sayi giriniz.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            if (choice == 10) break;
            menuHandler.executeCommand(choice);
        }
    }
};

#endif