#ifndef STATECARETAKER_H
#define STATECARETAKER_H

#include "HomeMemento.h"
#include <vector>

class StateCaretaker {
private:
    std::vector<HomeMemento*> historyStack;

public:
    StateCaretaker();
    ~StateCaretaker();

    
    void saveState(HomeMemento* m);
    
    // Geri alma
    HomeMemento* undo();
};

#endif