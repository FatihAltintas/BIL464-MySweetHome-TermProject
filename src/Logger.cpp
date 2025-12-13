#include "Logger.h"

using namespace std;

// Static degiskeni baslat (Singleton icin sart)
// C++98 standardinda nullptr yerine 0 veya NULL kullanilir.
Logger* Logger::instance = 0;

// Constructor
Logger::Logger() {
    logFile.open("MSH_Log.txt", ios::app);
}

// Destructor
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Get Instance
Logger* Logger::getInstance() {
    if (!instance) {
        instance = new Logger();
    }
    return instance;
}

// Log Fonksiyonu
void log(const string& message) {
    // Bu kisim asagidaki sinif fonksiyonuna aittir
}

// Sinif icindeki log fonksiyonunun govdesi
void Logger::log(const string& message) {
    if (logFile.is_open()) {
        logFile << "[LOG] " << message << endl;
    }
    // Konsola da yazdiralim
    cout << "[LOG] " << message << endl;
}