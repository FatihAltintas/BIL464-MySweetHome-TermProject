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

    // MSHSystem ile uyumlu olmasi icin ismini 'saveState' yaptik
    void saveState(HomeMemento* m);
    
    // Geri alma
    HomeMemento* undo();
};

#endif