#include "../include/TV.h"
#include <iostream>

TV::TV(int id, const std::string& name) : Device(id, name), channel(1), volume(10) {}

void TV::setChannel(int ch) { channel = ch; }
void TV::setVolume(int vol) { volume = vol; }

Device* TV::clone() const { return new TV(*this); }

void TV::printStatus() const {
    std::cout << "[TV] ID: " << id << ", Name: " << name
              << ", Pwr: " << (isPowered ? "ON" : "OFF")
              << ", Ch: " << channel << ", Vol: " << volume << std::endl;
}