#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <string>

// Strategy Interface
class NotificationStrategy {
public:
    // Sanal destructor (Guvenli bellek yonetimi icin sart)
    virtual ~NotificationStrategy();
    
    // Saf sanal fonksiyon (Arayuz)
    virtual void notify(const std::string& message) = 0;
};

// Concrete Strategy 1: SMS
class SMSStrategy : public NotificationStrategy {
public:
    virtual ~SMSStrategy();
    void notify(const std::string& message);
};

// Concrete Strategy 2: Alarm
class AlarmStrategy : public NotificationStrategy {
public:
    virtual ~AlarmStrategy();
    void notify(const std::string& message);
};

#endif