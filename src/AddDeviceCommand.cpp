#include "AddDeviceCommand.h"
#include "DeviceFactory.h" 
#include "Sensors.h" 
#include <iostream>
#include <limits>
#include <vector> // Vektor kullanimi icin

using namespace std;

AddDeviceCommand::AddDeviceCommand(MSHSystem* sys) : system(sys) {}

AddDeviceCommand::~AddDeviceCommand() {}

void AddDeviceCommand::execute() {
    int typeChoice, id, quantity = 1;
    string name;
    
    cout << "\n--- CIHAZ EKLEME SIHIRBAZI ---\n";
    cout << "Tur Secin:\n";
    cout << "[1] Light\n";
    cout << "[2] TV\n";
    cout << "[3] Camera\n";
    cout << "[4] Smoke Detector\n";
    cout << "[5] Gas Detector\n";
    // Alt menu mantigi oldugu icin burada Foreign Light'i gostermiyoruz, Light icinde soracagiz.
    cout << "Secim: ";
    
    if (!(cin >> typeChoice)) {
        cout << "[HATA] Lutfen sayi giriniz!\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return;
    }
    
    cout << "Baslangic ID Giriniz (Orn: 101): ";
    if (!(cin >> id)) {
        cout << "[HATA] Gecersiz ID!\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); return;
    }

    cout << "Kac Adet Eklenecek?: ";
    cin >> quantity;
    if (quantity < 1) quantity = 1;

    cout << "Isim Giriniz (Orn: Salon_Isigi): ";
    cin >> name;

    // --- 1. ILK CIHAZIN URETILMESI ---
    Device* prototypeDevice = NULL;
    
    // Light Secildiyse Alt Menu (Adapter Pattern)
    if (typeChoice == 1) {
        int modelChoice;
        cout << "\n   >>> Isik Modeli Secin:\n";
        cout << "   [1] Standart Model\n";
        cout << "   [2] Foreign Model (China Model)\n";
        cout << "   Secim: ";
        cin >> modelChoice;

        if (modelChoice == 2) prototypeDevice = DeviceFactory::createDevice("ForeignLight", name, id);
        else prototypeDevice = DeviceFactory::createDevice("Light", name, id);
    }
    else if (typeChoice == 2) prototypeDevice = DeviceFactory::createDevice("Tv", name, id);
    else if (typeChoice == 3) prototypeDevice = DeviceFactory::createDevice("Camera", name, id);
    else if (typeChoice == 4 || typeChoice == 5) {
        DetectorFactory* sensorFactory = new SecurityDeviceFactory();
        if (typeChoice == 4) prototypeDevice = sensorFactory->createSmokeDetector(id);
        else if (typeChoice == 5) prototypeDevice = sensorFactory->createGasDetector(id);
        delete sensorFactory; 
    }

    // --- 2. PROTOTYPE PATTERN (COGALTMA) ---
    if (prototypeDevice) {
        // İlk cihazı ekle
        system->addDevice(prototypeDevice);
        cout << "[BASARILI] " << name << " #" << id << " eklendi.\n";

        // Geriye kalanlari CLONE ile uret (Prototype Pattern)
        for (int i = 1; i < quantity; ++i) {
            int newId = id + i;
            
            // MAGIC IS HERE: clone() fonksiyonu
            Device* clonedDevice = prototypeDevice->clone();
            
            // Yeni ID ve Isim ver
            clonedDevice->setId(newId);
            // Isimlerin karismamasi icin sonuna numara ekleyebiliriz veya ayni birakabiliriz
            // Senaryoda "Light 2...10" diyor.
            
            system->addDevice(clonedDevice);
            cout << "[BASARILI] " << name << " #" << newId << " (Kopyalandi/Cloned)\n";
        }
        
        if (quantity > 1) {
             cout << ">> TOPLAM " << quantity << " CIHAZ EKLENDI.\n";
        }

    } else {
        cout << "[HATA] Cihaz uretilemedi.\n";
    }
    
    cout << "\nDevam etmek icin Enter'a basin...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string AddDeviceCommand::getDescription() const {
    return "Cihaz Ekle";
}