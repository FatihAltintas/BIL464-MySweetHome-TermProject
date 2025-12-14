#include "SimulateScenarioCommand.h"
#include <iostream>
#include <limits>
#include <thread> 
#include <chrono>

using namespace std;

SimulateScenarioCommand::SimulateScenarioCommand(MSHSystem* sys) : system(sys) {}

SimulateScenarioCommand::~SimulateScenarioCommand() {}

void SimulateScenarioCommand::execute() {
    int scenarioChoice;
    cout << "\n--- ACIL DURUM SIMULASYONU ---\n";
    cout << "[1] Hirsiz/Guvenlik İhlali (Motion Detected)\n";
    cout << "[2] Yangin Alarmi (Smoke Detected)\n";
    cout << "[3] Saglik Acil Durumu (Medical Emergency)\n";
    cout << "Senaryo Seciniz: ";

    if (cin >> scenarioChoice) {
        cout << "\n>>> SIMULASYON BASLATILIYOR...\n";
        
        if (scenarioChoice == 1) {
            // Hirsiz Senaryosu (REQ 13)
            cout << ">> [SENSOR] Hareket Algilandi! (Motion Sensor)\n";
            cout << ">> [ALARM]  ALARM CALIYOR! WEE-WOO WEE-WOO!\n";
            cout << ">> [LIGHT]  Tum isiklar acildi (Guvenlik modu).\n";
            cout << ">> [SYSTEM] 155 POLIS ARANIYOR... (Calling Police)\n";
            cout << ">> [INFO]   Polis ekipleri yonlendirildi.\n";
        }
        else if (scenarioChoice == 2) {
            // Yangin Senaryosu (REQ 16)
            cout << ">> [SENSOR] Duman Algilandi! (Smoke Detector)\n";
            cout << ">> [ALARM]  YANGIN ALARMI AKTIF!\n";
            cout << ">> [SYSTEM] Sprinkler sistemi devreye girdi.\n";
            cout << ">> [SYSTEM] 110 ITFAIYE ARANIYOR... (Calling Fire Station)\n";
            cout << ">> [INFO]   Konum bilgisi paylasildi.\n";
        }
        else if (scenarioChoice == 3) {
            // Saglik Senaryosu
            cout << ">> [USER]   Acil yardim butonu aktif!\n";
            cout << ">> [SYSTEM] Kullanici nabiz verisi kritik.\n";
            cout << ">> [SYSTEM] 112 AMBULANS ARANIYOR... (Calling Ambulance)\n";
            cout << ">> [INFO]   Saglik ekiplerine kapi kodu gonderildi.\n";
        }
        else {
            cout << "[HATA] Gecersiz senaryo.\n";
        }
    } else {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nSimulasyon tamamlandi. Devam etmek icin Enter...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string SimulateScenarioCommand::getDescription() const {
    return "Acil Durum (Police/Fire/Ambulance)";
}