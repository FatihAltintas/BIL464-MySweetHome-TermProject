#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Singleton Logger (C++98 Uyumlu)
class Logger {
private:
    static Logger* instance;
    ofstream logFile;

    // Constructor Private
    Logger() {
        logFile.open("MSH_Log.txt", ios::app); // Dosyaya ekleme modu
    }

public:
    static Logger* getInstance() {
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const string& message) {
        if (logFile.is_open()) {
            logFile << "[LOG] " << message << endl;
        }
        cout << "[LOG] " << message << endl; // Ekrana da bas
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

// Static degiskenin baslatilmasi (Header-only implementasyon icin inline hilesi yerine cpp kullanilmali ama hizli cozum icin burasi boyle kalsin)
// Eger linker hatasi alirsak bunu cpp dosyasina tasiriz.
// Simdilik hata vermemesi icin su anlik main icinde tanimlayacagiz, burada extern yapalim:
// Veya basitlik adina static instance'i NULL baslatalim:
// (C++98'de header icinde static init sorun olabilir, en temizi src/Logger.cpp kullanmaktir ama hizli cozum:)
/* 
   Not: src/Logger.cpp dosyasini Emre'den almistik. 
   O dosyanin icinde "Logger* Logger::instance = 0;" yaziyorsa sorun yok.
*/

#endif