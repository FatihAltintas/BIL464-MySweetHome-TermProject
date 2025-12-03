#include "Logger.h"
#include <ctime>
#include <vector>

// Static deðiþken baþlatma
Logger* Logger::instance = nullptr;

// Constructor: Dosyayý açar
Logger::Logger() {
    logFile.open("msh_log.txt", std::ios::app);
    if (logFile.is_open()) {
        std::cout << "[SYSTEM] Log file system initialized." << std::endl;
    }
}

// Destructor: Dosyayý kapatýr
Logger::~Logger() {
    if (logFile.is_open()) {
        // Dosya kapanmadan son log'u atamayabiliriz, direkt kapatalým
        logFile.close();
        std::cout << "[SYSTEM] Log file closed." << std::endl;
    }
}

// Singleton Eriþim
Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

// --- HATA VEREN KISIM BURASIYDI, DÜZELTÝLDÝ ---
std::string Logger::getCurrentTime() {
    time_t now = time(0);
    struct tm timeInfo;
    char buffer[80];

    // Visual Studio'nun istediði 'localtime_s' (Güvenli Versiyon) kullanýldý
    errno_t err = localtime_s(&timeInfo, &now);

    if (err == 0) {
        strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &timeInfo);
        return std::string(buffer);
    }

    return "TIME_ERROR";
}

// Loglama Fonksiyonu
void Logger::log(std::string message) {
    if (logFile.is_open()) {
        std::string logEntry = "[" + getCurrentTime() + "] " + message;
        logFile << logEntry << std::endl;
        std::cout << "[LOG] " << logEntry << std::endl;
    }
}

// VCR001 Uyarýlarýný Susturmak Ýçin Boþ Fonksiyonlar
Logger::Logger(const Logger&) {}
Logger& Logger::operator=(const Logger&) { return *this; }