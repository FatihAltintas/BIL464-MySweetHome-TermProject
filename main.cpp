#include "include/MSHSystem.h"
#include "include/Light.h"
#include <iostream>

int main() {
    std::cout << "=== MY SWEET HOME - REQ10, REQ11, REQ12 TEST ===" << std::endl;

    MSHSystem* system = new MSHSystem();

    Light* l1 = new Light("Living Room Light", 101);
    l1->powerOn(); 
    system->addDevice(l1);

    std::cout << "\n*** TEST REQ10: Prototype Cloning ***" << std::endl;
    system->duplicateDevice(0, 102); 
    
    system->listDevices(); 

    std::cout << "\n*** TEST REQ11: Saving State ***" << std::endl;
    system->changeMode("Night Mode"); 
    
    system->listDevices(); 

    std::cout << "\n*** TEST REQ12: Restoring State ***" << std::endl;
    system->restorePreviousMode(); 

    system->listDevices(); 

    delete system;
    return 0;
}