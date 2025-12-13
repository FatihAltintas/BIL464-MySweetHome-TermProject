#include "StateCaretaker.h"
#include "Logger.h" // Loglama icin

using namespace std;

StateCaretaker::StateCaretaker() {
    // Constructor
}

StateCaretaker::~StateCaretaker() {
    // Hafiza temizligi: Stack icindeki tum Memento'lari silmeliyiz
    for (size_t i = 0; i < historyStack.size(); ++i) {
        if (historyStack[i]) {
            delete historyStack[i];
        }
    }
    historyStack.clear();
}

void StateCaretaker::saveState(HomeMemento* m) {
    historyStack.push_back(m);
    
    // cout yerine Logger kullaniyoruz
    string msg = "Snapshot saved. History Stack Size: " + to_string(historyStack.size());
    Logger::getInstance()->log(msg);
}

HomeMemento* StateCaretaker::undo() {
    if (historyStack.empty()) {
        Logger::getInstance()->log("WARNING: Cannot Undo. History is empty!");
        return NULL;
    }
    
    // LIFO (Last In First Out) Mantigi
    HomeMemento* lastState = historyStack.back();
    historyStack.pop_back();
    
    Logger::getInstance()->log("Undo operation successful. Returning to previous state.");
    return lastState;
}