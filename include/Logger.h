#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>

// REQ 4: Loglama sistemi (Singleton Pattern)
class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;

    // Private Constructor
    Logger();

    std::string getCurrentTime();

    // Singleton Kurallarý
    Logger(const Logger&);
    Logger& operator=(const Logger&);

public:
    ~Logger();
    static Logger* getInstance();
    void log(std::string message);
};

#endif // LOGGER_H