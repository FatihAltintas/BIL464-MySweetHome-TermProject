#include <iostream>
#include "ModeManager.h"

using namespace std;

void printMenu() {
    cout << endl;
    cout << "===== MY SWEET HOME (MSH) =====" << endl;
    cout << "1) Show Home Status" << endl;
    cout << "2) Add Device" << endl;
    cout << "3) Power ON Device" << endl;
    cout << "4) Power OFF Device" << endl;
    cout << "5) Change Mode" << endl;
    cout << "0) Exit" << endl;
    cout << "Seciminiz: ";
}

void showStatus(const ModeManager& mm, const DeviceManager& dm) {
    cout << endl;
    cout << "=== HOME STATUS ===" << endl;
    cout << "Current Mode: " << mm.getModeName() << endl;
    cout << "Devices:" << endl;
    dm.listDevices();
    cout << "===================" << endl;
}

void addDeviceMenu(DeviceManager& dm) {
    cout << endl;
    cout << "Cihaz tipi secin:" << endl;
    cout << "1) Light" << endl;
    cout << "2) TV" << endl;
    cout << "3) Camera" << endl;
    cout << "4) Alarm" << endl;
    cout << "Secim: ";
    int c;
    cin >> c;

    string name;
    cout << "Cihaz ismi: ";
    cin >> name;

    if (c == 1) {
        dm.addLight(name);
        cout << "Light eklendi." << endl;
    } else if (c == 2) {
        dm.addTV(name);
        cout << "TV eklendi." << endl;
    } else if (c == 3) {
        dm.addCamera(name);
        cout << "Camera eklendi." << endl;
    } else if (c == 4) {
        dm.addAlarm(name);
        cout << "Alarm eklendi." << endl;
    } else {
        cout << "Gecersiz cihaz tipi!" << endl;
    }
}

void changeModeMenu(ModeManager& mm, DeviceManager& dm) {
    cout << endl;
    cout << "Mod secin:" << endl;
    cout << "1) Normal" << endl;
    cout << "2) Night" << endl;
    cout << "3) Party" << endl;
    cout << "4) Cinema" << endl;
    cout << "Secim: ";
    int c;
    cin >> c;

    ModeType m;
    if (c == 1)      m = MODE_NORMAL;
    else if (c == 2) m = MODE_NIGHT;
    else if (c == 3) m = MODE_PARTY;
    else if (c == 4) m = MODE_CINEMA;
    else {
        cout << "Gecersiz mod secimi!" << endl;
        return;
    }

    mm.setMode(m, dm);
}

int main() {
    DeviceManager dm;
    ModeManager mm;

    // Baslangic cihazlari
    dm.addLight("LivingRoomLight");
    dm.addTV("MainTV");
    dm.addCamera("DoorCam");
    dm.addAlarm("MainAlarm");

    bool running = true;
    while (running) {
        printMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            showStatus(mm, dm);
            break;
        case 2:
            addDeviceMenu(dm);
            break;
        case 3: {
            cout << "Power ON icin cihaz ID girin: ";
            int id; cin >> id;
            dm.powerOnDevice(id);
            break;
        }
        case 4: {
            cout << "Power OFF icin cihaz ID girin: ";
            int id; cin >> id;
            dm.powerOffDevice(id);
            break;
        }
        case 5:
            changeModeMenu(mm, dm);
            break;
        case 0:
            running = false;
            cout << "Sistem kapatiliyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }

    return 0;
}

