#ifndef POWEROFFCOMMAND_H
#define POWEROFFCOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class PowerOffCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    PowerOffCommand(MSHSystem* sys);
    virtual ~PowerOffCommand();

    void execute();
    std::string getDescription() const;
};

#endif