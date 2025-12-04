#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <iostream>
#include <string>

using namespace std;

// Strategy Interface
class NotificationStrategy {
public:
    virtual ~NotificationStrategy() {}
    virtual void notify(const string& message) = 0;
};

// Concrete Strategy 1: SMS
class SMSStrategy : public NotificationStrategy {
public:
    void notify(const string& message) {
        cout << "[SMS SENT] " << message << endl;
    }
};

// Concrete Strategy 2: Alarm
class AlarmStrategy : public NotificationStrategy {
public:
    void notify(const string& message) {
        cout << "[ALARM SOUNDING] BEEP! BEEP! " << message << endl;
    }
};

#endif