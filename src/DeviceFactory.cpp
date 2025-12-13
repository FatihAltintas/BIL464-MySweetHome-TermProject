#include "DeviceFactory.h"
#include "Light.h"
#include "Tv.h"
#include "Camera.h"
#include "LightAdapter.h" // <--- YENI: Adapter sinifi
#include "ForeignLight.h" // <--- YENI: Yabanci cihaz sinifi
#include "Logger.h" 

using namespace std;

Device* DeviceFactory::createDevice(const string& type, const string& name, int id) {
    Device* newDevice = NULL;

    if (type == "Light") {
        newDevice = new Light(name, id);
    }
    else if (type == "Tv") {
        newDevice = new Tv(name, id);
    }
    else if (type == "Camera") {
        newDevice = new Camera(name, id);
    }
    else if (type == "ForeignLight") {
        // --- ADAPTER PATTERN IMPLEMENTASYONU ---
        // 1. Once bizim sisteme uyumsuz olan yabanci cihazi uretiyoruz
        ForeignLight* cinMaliIsik = new ForeignLight(name);
        
        // 2. Sonra onu Adapter ile sarmalayip 'Device' haline getiriyoruz
        newDevice = new LightAdapter(cinMaliIsik, id);
        
        Logger::getInstance()->log("Factory: Created ForeignLight and wrapped with Adapter.");
    }

    // Loglama ve Kontrol
    if (newDevice != NULL) {
        Logger::getInstance()->log("Factory created device: " + type + " -> " + name);
    } else {
        Logger::getInstance()->log("Factory ERROR: Unknown device type requested (" + type + ")");
    }

    return newDevice;
}