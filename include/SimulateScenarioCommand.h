#ifndef SIMULATESCENARIOCOMMAND_H
#define SIMULATESCENARIOCOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class SimulateScenarioCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    SimulateScenarioCommand(MSHSystem* sys);
    virtual ~SimulateScenarioCommand();

    void execute();
    std::string getDescription() const;
};

#endif