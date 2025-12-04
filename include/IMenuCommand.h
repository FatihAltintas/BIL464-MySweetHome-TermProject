#ifndef IMENUCOMMAND_H
#define IMENUCOMMAND_H

#include <string>
#include <iostream>

class IMenuCommand {
public:
    virtual ~IMenuCommand() {}
    
    virtual void execute() = 0; 

    virtual std::string getDescription() const = 0; 
};

#endif