#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include "IMenuCommand.h"
#include <map>


class MenuHandler {
private:
    std::map<int, IMenuCommand*> commands;

public:
    // Destructor
    ~MenuHandler();

    // Komut kaydetme
    void registerCommand(int key, IMenuCommand* command);

    // Menuyu ekrana basma
    void displayMenu();

    // Secilen komutu calistirma
    void executeCommand(int choice);
};

#endif