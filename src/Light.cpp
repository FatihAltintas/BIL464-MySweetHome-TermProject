#include "../include/Light.h"

using namespace std;

// Constructor Uygulamasi
Light::Light(const string& n, int i) : Device(n), brightness(100), color("White") {
    setId(i);
}

Light::~Light() {}

// REQ10: Clone Uygulamasi
Device* Light::clone() const {
    return new Light(*this);
}

void Light::operate() {
    cout << "[Light] Operating... (Lighting up the room)" << endl;
}

void Light::setBrightness(int b) {
    brightness = b;
}

void Light::showInfo() const {
    cout << "   -> Light Info: Color=" << color << ", Brightness=" << brightness << "%" << endl;
}
