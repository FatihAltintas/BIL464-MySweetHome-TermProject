#ifndef IMENUCOMMAND_H
#define IMENUCOMMAND_H

#include <string>
#include <iostream>

// UML'de belirtilen Interface
class IMenuCommand {
public:
    virtual ~IMenuCommand() {}
    
    // Her komutun kendi işini yapacağı fonksiyon
    virtual void execute() = 0; 

    // Menüde gösterilecek açıklama (Örn: "Cihaz Ekle")
    virtual std::string getDescription() const = 0; 
};

#endif