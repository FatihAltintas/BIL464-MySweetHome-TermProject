#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <iostream>
#include <string>

using namespace std;

class NotificationStrategy {
public:
    virtual ~NotificationStrategy() {}
    virtual void notify(const string& message) = 0;
};

class SMSStrategy : public NotificationStrategy {
public:
    void notify(const string& message) {
        cout << "[SMS SENT] " << message << endl;
    }
};

class AlarmStrategy : public NotificationStrategy {
public:
    void notify(const string& message) {
        cout << "[ALARM SOUNDING] BEEP! BEEP! " << message << endl;
    }
};

#endif