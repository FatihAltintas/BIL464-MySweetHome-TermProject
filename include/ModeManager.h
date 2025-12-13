#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include <string>
#include <iostream>

// Header dosyasinda 'using namespace std' kullanmiyoruz.
// Kod karmasasini onlemek icin std:: kullaniyoruz.

enum ModeType {
    MODE_NORMAL,
    MODE_EVENING, 
    MODE_PARTY,
    MODE_CINEMA
};

enum SystemStateType {
    STATE_NORMAL,
    STATE_HIGH_PERF,
    STATE_LOW_POWER,
    STATE_SLEEP
};

// Fonksiyonun sadece imzasi (govdesi cpp'ye gitti)
std::string modeToString(ModeType m);

#endif