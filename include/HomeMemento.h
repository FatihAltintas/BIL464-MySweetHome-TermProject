#ifndef HOMEMEMENTO_H
#define HOMEMEMENTO_H

#include "ModeManager.h" // ModeType tanimi icin gerekli

class HomeMemento {
private:
    ModeType mode; // Sadece modu sakliyoruz (Basit ve etkili)

public:
    // Constructor: Durumu kaydeder
    HomeMemento(ModeType m);

    // Getter: Kaydedilen modu geri verir
    ModeType getMode() const;
};

#endif