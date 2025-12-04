#ifndef COMMANDSTUBS_H
#define COMMANDSTUBS_H

#include "IMenuCommand.h"
#include <iostream>

class ShowStatusCommand : public IMenuCommand {
public:
    void execute() override {
        std::cout << "[LOG] Ev durumu gosteriliyor... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const override { return "Ev Durumunu Goster (Status)"; }
};

class RemoveDeviceCommand : public IMenuCommand {
public:
    void execute() override {
        std::cout << "[LOG] Cihaz silme menusu... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const override { return "Cihaz Sil (Remove Device)"; }
};


class PowerOnCommand : public IMenuCommand {
public:
    void execute() override {
        std::cout << "[LOG] Cihaz acma islemi... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const override { return "Cihazi Ac (Power On)"; }
};

class PowerOffCommand : public IMenuCommand {
public:
    void execute() override {
        std::cout << "[LOG] Cihaz kapatma islemi... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const override { return "Cihazi Kapat (Power Off)"; }
};

class ChangeStateCommand : public IMenuCommand {
public:
    void execute() override {
        std::cout << "[LOG] Durum degistirme islemi... (Henuz implemente edilmedi)" << std::endl;
    }
    std::string getDescription() const override { return "Durum Degistir (Change State)"; }
};

#endif