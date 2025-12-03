#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include <ctime>

Logger* Logger::instance = nullptr;

Logger::Logger() {
    logFile.open("msh_log.txt", std::ios::app);
    if (logFile.is_open()) {
        std::cout << "[SYSTEM] Log file system initialized." << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
        std::cout << "[SYSTEM] Log file closed." << std::endl;
    }
}

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

std::string Logger::getCurrentTime() {
    time_t now = time(0);
    struct tm timeInfo;
    char buffer[80];
    if (localtime_s(&timeInfo, &now) == 0) {
        strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &timeInfo);
        return std::string(buffer);
    }
    return "TIME_ERROR";
}

void Logger::log(std::string message) {
    if (logFile.is_open()) {
        std::string logEntry = "[" + getCurrentTime() + "] " + message;
        logFile << logEntry << std::endl;
        std::cout << "[LOG] " << logEntry << std::endl;
    }
}

Logger::Logger(const Logger&) {}
Logger& Logger::operator=(const Logger&) { return *this; }