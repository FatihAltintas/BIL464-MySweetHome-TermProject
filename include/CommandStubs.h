#ifndef COMMANDSTUBS_H
#define COMMANDSTUBS_H

#include "IMenuCommand.h"
#include <iostream>

class ShowStatusCommand : public IMenuCommand {
public:
    void execute()  {
        std::cout << "[LOG] Ev durumu gosteriliyor... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const  { return "Ev Durumunu Goster (Status)"; }
};

class RemoveDeviceCommand : public IMenuCommand {
public:
    void execute()  {
        std::cout << "[LOG] Cihaz silme menusu... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const  { return "Cihaz Sil (Remove Device)"; }
};


class PowerOnCommand : public IMenuCommand {
public:
    void execute()  {
        std::cout << "[LOG] Cihaz acma islemi... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const  { return "Cihazi Ac (Power On)"; }
};

class PowerOffCommand : public IMenuCommand {
public:
    void execute() {
        std::cout << "[LOG] Cihaz kapatma islemi... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const  { return "Cihazi Kapat (Power Off)"; }
};

class ChangeStateCommand : public IMenuCommand {
public:
    void execute()  {
        std::cout << "[LOG] Durum degistirme islemi... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const { return "Durum Degistir (Change State)"; }
};

#endif