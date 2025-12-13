#include "Alarm.h"
#include "Logger.h"

using namespace std;

// Constructor
Alarm::Alarm(const string& n, int i) : Device(n) {
    setId(i);
}

// Destructor
Alarm::~Alarm() {}

// Clone (Prototype)
Device* Alarm::clone() const {
    return new Alarm(*this);
}

// Operate
void Alarm::operate() {
    Logger::getInstance()->log("[Alarm] Monitoring status... Security Active.");
}

// Durum Goster (Override)
void Alarm::displayStatus() {
    // Once standart bilgiyi yaz
    Device::displayStatus();
    
    // Detay goster
    if (getState() == ACTIVE) {
        cout << "   -> Detail: ZONE SECURE. Monitoring movement." << endl;
    }
}