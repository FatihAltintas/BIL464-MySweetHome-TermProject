#ifndef CHANGEMODECOMMAND_H
#define CHANGEMODECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class ChangeModeCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    ChangeModeCommand(MSHSystem* sys);
    virtual ~ChangeModeCommand();

    void execute();
    std::string getDescription() const;
};

#endif