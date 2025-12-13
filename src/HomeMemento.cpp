#include "HomeMemento.h"

// Constructor implementation
HomeMemento::HomeMemento(ModeType m) {
    this->mode = m;
}

// Getter implementation
ModeType HomeMemento::getMode() const {
    return this->mode;
}