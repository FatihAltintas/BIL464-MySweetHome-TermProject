#ifndef TV_H
#define TV_H

#include "Device.h"
#include <iostream>
#include <string>


class Tv : public Device {
public:
    Tv(const std::string& n, int i); // Constructor
    virtual ~Tv();                   // Destructor

    // Prototype Pattern (REQ10)
    Device* clone() const;

    // Islevler
    void operate();
    
    // Listeleme detaylari icin
    void displayStatus();
};

#endif