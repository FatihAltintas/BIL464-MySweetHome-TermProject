#ifndef REMOVEDEVICECOMMAND_H
#define REMOVEDEVICECOMMAND_H

#include "IMenuCommand.h"
#include "MSHSystem.h"
#include <string>

class RemoveDeviceCommand : public IMenuCommand {
private:
    MSHSystem* system;

public:
    RemoveDeviceCommand(MSHSystem* sys);
    virtual ~RemoveDeviceCommand();

    void execute();
    std::string getDescription() const;
};

#endif