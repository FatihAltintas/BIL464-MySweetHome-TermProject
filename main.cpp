#include <iostream>
#include <vector>
#include <string>
#include "Device.h"

using namespace std;

// =================== MODE TYPE (REQ7) ===================

enum ModeType {
    MODE_NORMAL,
    MODE_NIGHT,
    MODE_PARTY,
    MODE_CINEMA
};

string modeToString(ModeType m) {
    switch (m) {
        case MODE_NORMAL: return "Normal";
        case MODE_NIGHT:  return "Night";
        case MODE_PARTY:  return "Party";
        case MODE_CINEMA: return "Cinema";
        default:          return "Unknown";
    }
}

// =================== TUREYEN CIHAZ SINIFLARI ===================

// Light
class Light : public Device {
public:
    Light(const std::string& n, int i) : Device(n, i) {}

    // Prototype pattern zorunlu:
    virtual Device* clone() const {
        return new Light(*this);
    }
};

// TV
class TV : public Device {
public:
    TV(const std::string& n, int i) : Device(n, i) {}

    virtual Device* clone() const {
        return new TV(*this);
    }
};

// Camera
class Camera : public Device {
public:
    Camera(const std::string& n, int i) : Device(n, i) {}

    virtual Device* clone() const {
        return new Camera(*this);
    }
};

// Alarm (kapatılamayan cihaz örneği)
class Alarm : public Device {
public:
    Alarm(const std::string& n, int i) : Device(n, i) {
        // Alarm varsayılan ON başlayabilir
        isActive = true;
    }

    virtual Device* clone() const {
        return new Alarm(*this);
    }

    // Kullanıcı tarafından kapatılmasın:
    virtual void powerOff() override {
        std::cout << name << " cannot be turned OFF by user!" << std::endl;
    }
};

// =================== DEVICE MANAGER (REQ6) ===================

class DeviceManager {
    std::vector<Device*> devices;
    int nextId;

public:
    DeviceManager() : nextId(1) {}

    ~DeviceManager() {
        for (size_t i = 0; i < devices.size(); ++i) {
            delete devices[i];
        }
    }

    Device* addLight(const std::string& name) {
        Device* d = new Light(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* addTV(const std::string& name) {
        Device* d = new TV(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* addCamera(const std::string& name) {
        Device* d = new Camera(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* addAlarm(const std::string& name) {
        Device* d = new Alarm(name, nextId++);
        devices.push_back(d);
        return d;
    }

    Device* findById(int id) {
        for (size_t i = 0; i < devices.size(); ++i) {
            if (devices[i]->getId() == id) {
                return devices[i];
            }
        }
        return NULL;
    }

    void listDevices() const {
        if (devices.empty()) {
            cout << "  Kayitli cihaz yok." << endl;
            return;
        }
        for (size_t i = 0; i < devices.size(); ++i) {
            cout << "  [" << devices[i]->getId() << "] "
                 << devices[i]->getName()
                 << " - " << (devices[i]->getStatus() ? "ON" : "OFF")
                 << endl;
        }
    }

    // REQ6: Power ON
    void powerOnDevice(int id) {
        Device* d = findById(id);
        if (!d) {
            cout << "  Gecersiz cihaz ID!" << endl;
            return;
        }
        if (d->getStatus()) {
            cout << "  Cihaz zaten ON." << endl;
            return;
        }
        d->powerOn();
        // Burada log dosyası yazılabilir (LLR-7 vs.)
    }

    // REQ6: Power OFF
    void powerOffDevice(int id) {
        Device* d = findById(id);
        if (!d) {
            cout << "  Gecersiz cihaz ID!" << endl;
            return;
        }
        if (!d->getStatus()) {
            cout << "  Cihaz zaten OFF." << endl;
            return;
        }
        // Alarm gibi cihazlar powerOff override etmiş olabilir
        d->powerOff();
        // Burada da log yazılabilir
    }

    const std::vector<Device*>& getDevices() const {
        return devices;
    }
};

// =================== MODE MANAGER (REQ7) ===================

class ModeManager {
    ModeType currentMode;

public:
    ModeManager() : currentMode(MODE_NORMAL) {}

    ModeType getCurrentMode() const {
        return currentMode;
    }

    std::string getModeName() const {
        return modeToString(currentMode);
    }

    void setMode(ModeType m, DeviceManager& dm) {
        if (m == currentMode) {
            cout << "  Zaten bu moddasiniz: " << getModeName() << endl;
            return;
        }
        currentMode = m;
        applyMode(dm);
        cout << "  Mod degistirildi: " << getModeName() << endl;
    }

    // REQ7'nin davranış kısmı (basit, anlaşılır)
    void applyMode(DeviceManager& dm) {
        const std::vector<Device*>& devs = dm.getDevices();

        for (size_t i = 0; i < devs.size(); ++i) {
            Device* d = devs[i];
            string n = d->getName();

            if (currentMode == MODE_NORMAL) {
                // Normal: kullanıcının bıraktığı gibi kalsın.
            }
            else if (currentMode == MODE_NIGHT) {
                // Night: sadece LivingRoom ON, TV OFF
                if (n == "LivingRoomLight") {
                    d->powerOn();
                } else {
                    // Alarm kapatmaya çalışırsak override edilmiş powerOff çalışır
                    d->powerOff();
                }
            }
            else if (currentMode == MODE_PARTY) {
                // Party: tüm cihazlar ON (örnek)
                d->powerOn();
            }
            else if (currentMode == MODE_CINEMA) {
                // Cinema: sadece TV ON, diğerleri OFF
                if (n.find("TV") != string::npos) {
                    d->powerOn();
                } else {
                    d->powerOff();
                }
            }
        }
    }
};

// =================== MENU & YARDIMCI FONKSIYONLAR ===================

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

// =================== MAIN ===================

int main() {
    DeviceManager dm;
    ModeManager mm;

    // Başlangıç için örnek cihazlar
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

