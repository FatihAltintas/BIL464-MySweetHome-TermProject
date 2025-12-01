#ifndef STATECARETAKER_H
#define STATECARETAKER_H

#include "HomeMemento.h"
#include <vector>
#include <iostream>

class StateCaretaker {
private:
    std::vector<HomeMemento*> historyStack;

public:
    ~StateCaretaker() {
        for (size_t i = 0; i < historyStack.size(); ++i) {
            delete historyStack[i];
        }
        historyStack.clear();
    }

    void saveMemento(HomeMemento* m) {
        historyStack.push_back(m);
        std::cout << "[MEMENTO] State saved to history. Stack size: " << historyStack.size() << std::endl;
    }

    HomeMemento* undo() {
        if (historyStack.empty()) {
            std::cout << "[WARNING] No previous state in history!" << std::endl;
            return NULL;
        }
        
        HomeMemento* lastState = historyStack.back();
        historyStack.pop_back();
        return lastState;
    }
};

#endif