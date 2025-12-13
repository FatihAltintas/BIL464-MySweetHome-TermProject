#ifndef POWERONCOMMAND_H
#define POWERONCOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class PowerOnCommand : public IMenuCommand {
private:
    MSHSystem* system; 

public:
    PowerOnCommand(MSHSystem* sys);
    virtual ~PowerOnCommand();

    void execute();
    std::string getDescription() const;
};

#endif