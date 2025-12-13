#ifndef MSHMENUCONTROLLER_H
#define MSHMENUCONTROLLER_H

#include "MenuHandler.h"
#include "MSHSystem.h"

// Header dosyasinda 'using namespace std' kullanilmaz.
class MSHMenuController {
private:
    bool isRunning;
    MenuHandler menuHandler;
    MSHSystem* system; 

public:
    // Constructor
    MSHMenuController(MSHSystem* sys);

    // Ana donguyu calistiran fonksiyon
    void run();
};

#endif