#include "Light.h"
#include <iostream>

Light::Light(int id, const string& name, int brightness, const string& color)
    : Device(name), brightness(brightness), color(color) {
    this->id = id; // ID base constructor'da olmadığı için burada atanır
}

Device* Light::clone() const {
    return new Light(*this);
}

void Light::copyConfigFrom(const Device* other) {
    // Base config (isim vb.) kopyala
    Device::copyConfigFrom(other);

    // Kendi tipimizde mi kontrol et
    const Light* otherLight = dynamic_cast<const Light*>(other);
    if (otherLight) {
        this->brightness = otherLight->brightness;
        this->color = otherLight->color;
        cout << "[Light] Brightness and Color copied." << endl;
    }
}

void Light::operate() {
    // Eski printStatus mantığı burada çalışır
    cout << "[Light] ID: " << id 
         << ", Name: " << name
         << ", State: " << (state == ACTIVE ? "ON" : (state == FAILED ? "ERROR" : "OFF"))
         << ", Color: " << color 
         << ", Level: " << brightness << "%" << endl;
}

void Light::setBrightness(int level) {
    brightness = level;
    // Parlaklık değişimi bir durum güncellemesi sayılabilir, observer'a haber verelim
    notifyObservers();
}

void Light::setColor(const string& newColor) {
    color = newColor;
    notifyObservers();
}