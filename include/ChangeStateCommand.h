#ifndef CHANGESTATECOMMAND_H
#define CHANGESTATECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class ChangeStateCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    ChangeStateCommand(MSHSystem* sys);
    virtual ~ChangeStateCommand();

    void execute();
    std::string getDescription() const;
};

#endif