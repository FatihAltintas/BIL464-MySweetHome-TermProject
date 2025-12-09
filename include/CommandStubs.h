#ifndef COMMANDSTUBS_H
#define COMMANDSTUBS_H

#include "IMenuCommand.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class StubCommand : public IMenuCommand {
private:
    string description;

public:
    StubCommand(const string& desc) : description(desc) {}

    void execute() {
        cout << "\n[INFO] Bu ozellik henuz aktif degil: " << description << endl;
        cout << "Devam etmek icin [Enter] tusuna basin..." << endl;
        
        // Bekleme yapalim
        cin.ignore(10000, '\n');
        cin.get();
    }

    string getDescription() const {
        return description;
    }
};

#endif