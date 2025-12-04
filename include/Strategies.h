#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <iostream>
#include <string>
using namespace std;

// REQ9.3: Strategy Pattern Interface
class INotificationStrategy {
public:
    virtual ~INotificationStrategy() {}
    virtual void sendNotification(string message) = 0;
};

// Concrete Strategy 1: SMS
class SMSStrategy : public INotificationStrategy {
public:
    void sendNotification(string message) {
        // REQ9.4: Simülasyon mesajý
        cout << "[SMS GONDERILDI]: " << message << endl;
    }
};

// Concrete Strategy 2: Alarm
class AlarmStrategy : public INotificationStrategy {
public:
    void sendNotification(string message) {
        cout << "[ALARM CALIYOR]: DIKKAT! " << message << endl;
    }
};

// Concrete Strategy 3: Log
class LogStrategy : public INotificationStrategy {
public:
    void sendNotification(string message) {
        cout << "[LOG KAYDI]: " << message << endl;
    }
};

#endif