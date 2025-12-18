#ifndef CHANGESTATECOMMAND_H
#define CHANGESTATECOMMAND_H
/*
Bu dosya, kullanıcının sistemin durumunu (State/Mode) değiştirmesini
ve Geri Al (Undo) işlemini yapmasını sağlayan komutun tanımıdır.
Bu sınıf, Command Pattern'daki "Concrete Command" (Somut Komut) rolündedir.
*/    
#include "IMenuCommand.h" // Base Class (Interface) - Polimorfizm
#include "MSHSystem.h" // Receiver (Alıcı) - İşlemi asıl yapacak olan sınıf
#include <string>

// Bu sınıfın görevi: Menüden "7" seçildiğinde devreye girmek ve
// MSHSystem üzerindeki changeMode() veya restorePreviousMode() 
//  fonksiyonlarını tetiklemektir.
class ChangeStateCommand : public IMenuCommand {  
private:

//sistemin kopyası üzerinde değil, bellekteki
// GERÇEK sistem üzerinde değişiklik yapmak istiyoruz.
    MSHSystem* system;

public:
    ChangeStateCommand(MSHSystem* sys);

    // bu bir alt sınıf. Eğer bir ChangeStateCommand nesnesini
    // IMenuCommand* (Base) pointer'ı üzerinden silersek ve bu virtual olmazsa,
    // sadece üst sınıf silinir, alt sınıf bellekte kalır (Memory Leak).
    virtual ~ChangeStateCommand();

    void execute();
    std::string getDescription() const;
};

#endif

// bu Command Pattern'a aittir. Rolü Concrete Command'dır 
// (Somut Komut). Kullanıcının isteğini (State değiştirmek veya Geri almak) bir nesneye 
// dönüştürür ve arka plandaki MSHSystem'e iletir."
