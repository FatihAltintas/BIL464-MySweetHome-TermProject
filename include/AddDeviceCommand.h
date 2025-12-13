#ifndef ADDDEVICECOMMAND_H
#define ADDDEVICECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class AddDeviceCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    AddDeviceCommand(MSHSystem* sys);
    virtual ~AddDeviceCommand();

    void execute();
    std::string getDescription() const;
};

#endif