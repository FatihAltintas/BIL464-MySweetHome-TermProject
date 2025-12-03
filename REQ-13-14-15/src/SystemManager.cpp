#include "../include/SystemManager.h"

SystemManager* SystemManager::instance = NULL;

SystemManager::SystemManager() {
    systemStatus = "INACTIVE"; 
    hazardCondition = false;
    alarmState = false;
    blinkTimer = 0;
    lightsToggleState = false;
}

SystemManager* SystemManager::getInstance() {
    if (instance == NULL) instance = new SystemManager();
    return instance;
}

void SystemManager::addDevice(Device* device) {
    if (device) devices.push_back(device);
}

void SystemManager::addBulkDevices(const std::string& type, int quantity) {
    if (quantity <= 0) return;
    int startId = devices.size() + 1;
    Device* master = DeviceFactory::createDevice(type, startId);
    if (!master) return;
    
    addDevice(master);
    for (int i = 1; i < quantity; ++i) {
        Device* clone = master->clone();
        clone->setId(startId + i);
        addDevice(clone);
    }
}

void SystemManager::removeDevice(int deviceId) {
     for (std::vector<Device*>::iterator it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getId() == deviceId) {
            delete *it;
            devices.erase(it);
            return;
        }
    }
}

void SystemManager::listDevices() const {
    std::cout << "\n--- Status Report ---" << std::endl;
    std::cout << "System Status: " << systemStatus << std::endl;
    for (size_t i = 0; i < devices.size(); ++i) devices[i]->printStatus();
    std::cout << "---------------------\n" << std::endl;
}

// --- EKSİK OLAN IMPLEMENTASYON BURAYA EKLENDİ ---
Device* SystemManager::getDevice(int id) {
    for (size_t i = 0; i < devices.size(); ++i) {
        if (devices[i]->getId() == id) {
            return devices[i];
        }
    }
    return NULL;
}

// --- MANTIK KODLARI ---

void SystemManager::setSystemStatus(const std::string& status) {
    systemStatus = status;
    std::cout << "[CMD] System Security Status changed to: " << status << std::endl;
    if (status == "INACTIVE") {
        stopAlarm();
    }
}

void SystemManager::triggerAlarm() {
    if (alarmState) return;
    alarmState = true;
    for (size_t i = 0; i < devices.size(); ++i) {
        Alarm* alarm = dynamic_cast<Alarm*>(devices[i]);
        if (alarm) alarm->turnOn();
    }
    std::cout << "!!! ALARM TRIGGERED !!!" << std::endl;
}

void SystemManager::stopAlarm() {
    alarmState = false;
    hazardCondition = false;
    blinkTimer = 0;
    for (size_t i = 0; i < devices.size(); ++i) {
        Alarm* alarm = dynamic_cast<Alarm*>(devices[i]);
        if (alarm) alarm->turnOff();
    }
    std::cout << "--- Alarm Stopped ---" << std::endl;
}

void SystemManager::turnOnAllLights() {
    for (size_t i = 0; i < devices.size(); ++i) {
        Light* light = dynamic_cast<Light*>(devices[i]);
        if (light) light->turnOn();
    }
}

void SystemManager::toggleAllLights() {
    lightsToggleState = !lightsToggleState;
    for (size_t i = 0; i < devices.size(); ++i) {
        Light* light = dynamic_cast<Light*>(devices[i]);
        if (light) {
            if (lightsToggleState) light->turnOn();
            else light->turnOff();
        }
    }
    std::cout << "[Visual Alarm] Lights Toggled " << (lightsToggleState ? "ON" : "OFF") << std::endl;
}

void SystemManager::callPolice() {
    std::cout << "!!! EMERGENCY !!! Calling Police Station..." << std::endl;
}

void SystemManager::runCycle(int elapsedMs) {
    // Hazard Check
    bool smokeFound = false;
    bool gasFound = false;

    for (size_t i = 0; i < devices.size(); ++i) {
        SmokeDetector* sd = dynamic_cast<SmokeDetector*>(devices[i]);
        if (sd && sd->isSmokeDetected()) smokeFound = true;

        GasDetector* gd = dynamic_cast<GasDetector*>(devices[i]);
        if (gd && gd->isGasDetected()) gasFound = true;
    }

    if (smokeFound || gasFound) {
        hazardCondition = true;
        triggerAlarm();
    }

    // Security Check
    if (systemStatus == "ACTIVE") {
        bool motionFound = false;
        for (size_t i = 0; i < devices.size(); ++i) {
            Camera* cam = dynamic_cast<Camera*>(devices[i]);
            if (cam && cam->isMotionDetected()) {
                motionFound = true;
                break;
            }
        }

        if (motionFound) {
            std::cout << ">> Security Breach Detected!" << std::endl;
            triggerAlarm();      
            turnOnAllLights();   
            callPolice();        
        }
    }

    // Blink Logic
    if (alarmState) {
        blinkTimer += elapsedMs;
        if (blinkTimer >= 1000) {
            toggleAllLights(); 
            blinkTimer = 0;    
        }
    } else {
        blinkTimer = 0;
    }
}

SystemManager::~SystemManager() {
    for (size_t i = 0; i < devices.size(); ++i) delete devices[i];
    devices.clear();
}