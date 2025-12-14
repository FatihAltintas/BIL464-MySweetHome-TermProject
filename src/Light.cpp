#include "Light.h"
#include "Logger.h" // Loglama

using namespace std;

// Constructor
// Baslangic degerleri: Parlaklik %100, Renk White
Light::Light(const string& n, int i) : Device(n), brightness(100), color("White") {
    setId(i);
}

// Destructor
Light::~Light() {}

// REQ10: Clone (Prototype)
// Kendisinin kopyasini olusturup pointer olarak doner
Device* Light::clone() const {
    return new Light(*this);
}

// Operate: Isigi yakma eylemi
void operate() {
    // Logger kullanimi
}

void Light::operate() {
    Logger::getInstance()->log("[Light] Operating... Lighting up the room.");
}

// Parlaklik ayari
void Light::setBrightness(int b) {
    if (b >= 0 && b <= 100) {
        brightness = b;
        // Detay sevisyesinde loglama yapilabilir
        // Logger::getInstance()->log(name + " brightness set to " + to_string(b));
    }
}

// Durum Goster (Device sinifindan override edildi)
void Light::displayStatus() {
    // Once ana sinifin standart ciktisini (ID, Isim, ON/OFF) yazdir
    Device::displayStatus();
    
    // Sonra kendine ozgu detaylari altina ekle
    cout << "   -> Detail: Color=" << color << ", Brightness=" << brightness << "%" << endl;
}