#ifndef SHOWMANUALCOMMAND_H
#define SHOWMANUALCOMMAND_H

#include "IMenuCommand.h"
#include <string>

class ShowManualCommand : public IMenuCommand {
public:
    virtual ~ShowManualCommand(); // Destructor (Guvenlik icin)

    void execute();
    std::string getDescription() const;

private:
    void loadManualText();
    void waitForKeyInput();
};

#endif