#ifndef SHOWSTATUSCOMMAND_H
#define SHOWSTATUSCOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class ShowStatusCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    ShowStatusCommand(MSHSystem* sys);
    virtual ~ShowStatusCommand();

    void execute();
    std::string getDescription() const;
};

#endif