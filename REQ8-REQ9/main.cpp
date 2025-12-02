#include <iostream>
#include "DeviceManager.h"

int main() {
    DeviceManager manager;
    int choice;

    do {
        cout << "\n=== MY SWEET HOME (REQ 8-9) ===" << endl;
        cout << "1. Cihaz Ekle" << endl;
        cout << "2. Cihazlari Listele" << endl;
        cout << "3. Cihaz Sil" << endl;
        cout << "4. Strateji Degistir (SMS/Alarm/Log)" << endl;
        cout << "5. Ariza Simule Et" << endl;
        cout << "0. Cikis" << endl;
        cout << "Secim: ";
        cin >> choice;

        switch (choice) {
        case 1: manager.addDeviceUI(); break;
        case 2: manager.listDevices(); break;
        case 3: manager.removeDeviceUI(); break;
        case 4: {
            cout << "1:SMS, 2:Alarm, 3:Log -> ";
            int s; cin >> s;
            if (s == 1) manager.setNotificationStrategy(new SMSStrategy());
            else if (s == 2) manager.setNotificationStrategy(new AlarmStrategy());
            else manager.setNotificationStrategy(new LogStrategy());
            break;
        }
        case 5:
            cout << "ID Gir: ";
            int id; cin >> id;
            manager.simulateFailure(id);
            break;
        }
    } while (choice != 0);

    return 0;
}