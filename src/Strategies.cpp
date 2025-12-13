#include "Strategies.h"
#include "Logger.h"
#include <iostream>

using namespace std;

// --- NotificationStrategy ---
// Abstract class destructor implementation
NotificationStrategy::~NotificationStrategy() {}


// --- SMSStrategy ---
SMSStrategy::~SMSStrategy() {}

void SMSStrategy::notify(const string& message) {
    // Hem logluyoruz hem ekrana yaziyoruz
    Logger::getInstance()->log("[Strategy] Sending SMS: " + message);
    cout << "   >>> [SMS SENT] " << message << endl;
}


// --- AlarmStrategy ---
AlarmStrategy::~AlarmStrategy() {}

void AlarmStrategy::notify(const string& message) {
    Logger::getInstance()->log("[Strategy] Triggering Alarm: " + message);
    cout << "   >>> [ALARM SOUNDING] BEEP! BEEP! " << message << endl;
}