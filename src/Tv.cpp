#include "Tv.h"
#include "Logger.h"

using namespace std;

// Constructor
Tv::Tv(const string& n, int i) : Device(n) {
    setId(i);
    
}

// Destructor
Tv::~Tv() {}

// Clone (Prototype)
Device* Tv::clone() const {
    return new Tv(*this);
}

// Operate
void Tv::operate() {
    Logger::getInstance()->log("[TV] Operating... Displaying content on screen.");
}

// Durum Goster (Override)
void Tv::displayStatus() {
    // Once standart ID ve Isim bilgisini yazdir
    Device::displayStatus();
    
    // Altina TV'ye ozel detay ekle
    if (getState() == ACTIVE) {
        cout << "   -> Detail: Input Source: HDMI1, Volume: 25" << endl;
    }
}