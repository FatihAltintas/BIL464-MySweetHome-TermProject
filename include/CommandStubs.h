#ifndef COMMANDSTUBS_H
#define COMMANDSTUBS_H

#include "IMenuCommand.h"
#include <string>

class StubCommand : public IMenuCommand {
private:
    std::string description;

public:
    StubCommand(const std::string& desc);
    virtual ~StubCommand();

    // Arayuzden gelen fonksiyonlar
    void execute();
    std::string getDescription() const;
};

#endif