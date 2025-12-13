#include "CommandStubs.h"
#include <iostream>
#include <limits> // numeric_limits icin

using namespace std;

StubCommand::StubCommand(const string& desc) : description(desc) {}

StubCommand::~StubCommand() {}

void StubCommand::execute() {
    cout << "\n[INFO] Bu ozellik henuz aktif degil: " << description << endl;
    cout << "Devam etmek icin [Enter] tusuna basin..." << endl;
    
    // Onceki islemden kalan 'Enter' karakterini temizle
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); // Kullanicidan tus bekle
}

string StubCommand::getDescription() const {
    return description;
}