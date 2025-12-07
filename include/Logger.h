#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Logger {
private:
    static Logger* instance;
    ofstream logFile;

    Logger() {
        logFile.open("MSH_Log.txt", ios::app);
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
        cout << "[LOG] " << message << endl; 
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};



#endif