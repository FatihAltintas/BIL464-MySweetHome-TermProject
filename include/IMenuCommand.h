#ifndef IMENUCOMMAND_H
#define IMENUCOMMAND_H

#include <string>

class IMenuCommand {
public:
    // Destructor tanimi (Govdesi cpp'de)
    virtual ~IMenuCommand();
    
    // Saf sanal fonksiyonlar (Arayuz)
    virtual void execute() = 0; 
    virtual std::string getDescription() const = 0; 
};

#endif