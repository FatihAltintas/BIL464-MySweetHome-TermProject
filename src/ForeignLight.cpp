#include "ForeignLight.h"
#include "Logger.h" // Loglama yapalim ki calistigini gorelim

using namespace std;

ForeignLight::ForeignLight(const string& m) : model(m) {}

ForeignLight::~ForeignLight() {}

void ForeignLight::turnOn220V() {
    Logger::getInstance()->log("[ForeignLight] " + model + " -> 220V POWER ACILDI (Different Connector)");
}

void ForeignLight::turnOff220V() {
    Logger::getInstance()->log("[ForeignLight] " + model + " -> 220V POWER KAPATILDI");
}

string ForeignLight::getModelName() const {
    return model;
}