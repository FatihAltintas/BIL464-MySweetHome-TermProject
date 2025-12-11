#include "../include/StateCaretaker.h"
#include <iostream>

using namespace std;

StateCaretaker::StateCaretaker() {}

StateCaretaker::~StateCaretaker() {
    for (size_t i = 0; i < historyStack.size(); ++i) {
        delete historyStack[i];
    }
    historyStack.clear();
}

void StateCaretaker::saveMemento(HomeMemento* m) {
    historyStack.push_back(m);
    cout << "[MEMENTO] State saved to history. Stack size: " << historyStack.size() << endl;
}

HomeMemento* StateCaretaker::undo() {
    if (historyStack.empty()) {
        cout << "[WARNING] No previous state in history!" << endl;
        return NULL;
    }
    
    // LIFO (Last In First Out)
    HomeMemento* lastState = historyStack.back();
    historyStack.pop_back();
    return lastState;
}