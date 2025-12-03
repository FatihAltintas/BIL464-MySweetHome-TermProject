#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

// PROJEDEKİ ORTAK DOSYAYI ÇAĞIRIYORUZ
#include "Device.h"


// 1. LOGGER 

class TahaLogger {
private:
    static TahaLogger* instance;
    TahaLogger() {} 

public:
    static TahaLogger* getInstance() {
        if (instance == nullptr) {
            instance = new TahaLogger();
        }
        return instance;
    }

    void log(const std::string& msg) {
        std::time_t now = std::time(nullptr);
        char buf[100];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        std::cout << "[TAHA-LOG - " << buf << "]: " << msg << std::endl;
    }
};
TahaLogger* TahaLogger::instance = nullptr;


// 2. SECURITY SYSTEM (Benim Görevim: REQ16)

class SecuritySystem {
private:
    std::vector<Device*> connectedDevices; 

public:
    void addDevice(Device* d) {
        connectedDevices.push_back(d);
    }

    void callFireStation() {
        std::cout << "\n!!! ALARM !!! Calling Fire Station..." << std::endl;
        TahaLogger::getInstance()->log("CRITICAL: Fire Station Called"); 
    }

    void handleEmergency() {
        TahaLogger::getInstance()->log("Smoke/Gas Detected. Waiting for user acknowledgement...");
        std::cout << "WARNING: Hazard Detected! Press 'A' to Acknowledge within 3 seconds..." << std::endl;

        bool userAcknowledged = false;
        // 2 saniye bekleme
        std::this_thread::sleep_for(std::chrono::seconds(2));

        if (!userAcknowledged) {
            std::cout << "Timeout reached. No acknowledgement." << std::endl;
            TahaLogger::getInstance()->log("State changed to EMERGENCY. Turning off non-essential devices.");
            
            // Fatih'in Device yapısına uygun kapatma döngüsü
            for (Device* d : connectedDevices) {
                // Eğer isActive public ise:
                // d->powerOff(); 
                std::cout << " -> Device power off signal sent to: " << d->getName() << std::endl;
            }
            callFireStation();
        }
    }
};


// 3. COMMAND PATTERN (Benim Görevim: REQ3)

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class AddDeviceCommand : public Command {
public:
    void execute() override {
        std::cout << "Executing: Add Device Process..." << std::endl;
    }
};

class EmergencyCommand : public Command {
private:
    SecuritySystem* securitySystem;
public:
    EmergencyCommand(SecuritySystem* sys) : securitySystem(sys) {}
    void execute() override {
        securitySystem->handleEmergency();
    }
};


// 4. MENU HANDLER (Invoker)

class MenuHandler {
private:
    std::map<char, Command*> commands;

public:
    ~MenuHandler() {
        for (auto const& pair : commands) {
            delete pair.second;
        }
    }

    void setCommand(char key, Command* cmd) {
        commands[key] = cmd;
    }

    void pressButton(char key) {
        if (commands.find(key) != commands.end()) {
            std::string logMsg = "User pressed key: ";
            logMsg += key;
            TahaLogger::getInstance()->log(logMsg);
            commands[key]->execute();
        }
        else {
            std::cout << "Invalid Command! Key: " << key << std::endl;
            TahaLogger::getInstance()->log("Invalid key pressed.");
        }
    }
};