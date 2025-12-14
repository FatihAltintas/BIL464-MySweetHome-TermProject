#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <fstream>



class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;

    // Private Constructor (Singleton)
    Logger();

public:
    // Global erisim noktasi
    static Logger* getInstance();

    // Loglama fonksiyonu
    void log(const std::string& message);

    // Destructor
    ~Logger();
};

#endif