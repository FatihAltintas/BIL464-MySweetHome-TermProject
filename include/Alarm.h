#ifndef ALARM_H
#define ALARM_H

#include "Device.h"
#include <iostream>
#include <string>

class Alarm : public Device {
public:
    Alarm(const std::string& n, int i); // Constructor
    virtual ~Alarm();                   // Destructor

    // Prototype Pattern (REQ10)
    Device* clone() const;

    // Islevler
    void operate();
    
    // Listeleme detaylari icin
    void displayStatus();
};

#endif