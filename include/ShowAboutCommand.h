#ifndef SHOWABOUTCOMMAND_H
#define SHOWABOUTCOMMAND_H

#include "IMenuCommand.h"
#include <string>

class ShowAboutCommand : public IMenuCommand {
public:
    virtual ~ShowAboutCommand(); // Destructor

    void execute();
    std::string getDescription() const;
};

#endif