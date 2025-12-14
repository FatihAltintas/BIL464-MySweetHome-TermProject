#include "MSHMenuController.h"


#include "ShowStatusCommand.h"
#include "AddDeviceCommand.h"
#include "RemoveDeviceCommand.h"
#include "PowerOnCommand.h"
#include "PowerOffCommand.h"
#include "ChangeModeCommand.h"
#include "ChangeStateCommand.h"
#include "ShowManualCommand.h"
#include "ShowAboutCommand.h"
#include "CommandStubs.h" // Cikis komutu icin Stub
#include "SimulateScenarioCommand.h"

#include <iostream>
#include <limits>

using namespace std;

// Constructor: Komutlari MenuHandler'a kaydeder
MSHMenuController::MSHMenuController(MSHSystem* sys) : isRunning(true), system(sys) {
    // 1. Durum Goster
    menuHandler.registerCommand(1, new ShowStatusCommand(system)); 
    
    // 2. Cihaz Ekle
    menuHandler.registerCommand(2, new AddDeviceCommand(system));
    
    // 3. Cihaz Sil
    menuHandler.registerCommand(3, new RemoveDeviceCommand(system));
    
    // 4. Cihaz Ac
    menuHandler.registerCommand(4, new PowerOnCommand(system)); 
    
    // 5. Cihaz Kapat
    menuHandler.registerCommand(5, new PowerOffCommand(system));
    
    // 6. Mod Degistir
    menuHandler.registerCommand(6, new ChangeModeCommand(system));
    
    // 7. Durum Degistir (Undo)
    menuHandler.registerCommand(7, new ChangeStateCommand(system));
    
    // 8. Kullanim Kilavuzu
    menuHandler.registerCommand(8, new ShowManualCommand());
    
    // 9. Hakkinda
    menuHandler.registerCommand(9, new ShowAboutCommand());
    
    // 10. Cikis (Stub Command ile)
    menuHandler.registerCommand(10, new StubCommand("Cikis")); 

    // 11. Acil Durum Simulasyonu (YENI)
    
    menuHandler.registerCommand(11, new SimulateScenarioCommand(system));
}

// Ana Dongu (Run)
void MSHMenuController::run() {
    int choice = 0;
    
    // 10 secilene kadar don (Cikis)
    while (choice != 10) {
        menuHandler.displayMenu();
        
        cout << "Seciminiz: ";
        if (!(cin >> choice)) {
            cout << "HATA: Lutfen bir sayi giriniz.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        if (choice == 10) {
            cout << "Cikis yapiliyor..." << endl;
            break;
        }
        
        // Komutu calistir
        menuHandler.executeCommand(choice);
    }
}