/*
* PROJE: MY SWEET HOME (MSH)
* MAIN MODULE - FINAL CLEAN VERSION
* Aciklama: Program sadece menuyu baslatir. Tum islemler menu uzerinden manuel yapilir.
*/

#include <iostream>
#include "include/MSHSystem.h"         
#include "include/MSHMenuController.h" 
#include "include/Logger.h"            

using namespace std;

int main() {
    // 1. Sistemi Baslat
    // Log dosyasini aciyoruz ve sisteme hazir oldugunu soyluyoruz
    Logger::getInstance()->log("System Booting up... (User Manual Mode)");
    
    // Cekirdek sistemi olustur
    MSHSystem* coreSystem = new MSHSystem();

    // 2. Kullanici Arayuzunu (Menuyu) Baslat
    // Artik otomatik testler yok (runErhanTests vb. kaldirildi). 
    // Kontrol tamamen kullanicida.
    MSHMenuController* menuApp = new MSHMenuController(coreSystem);
    
    // 3. Menuyu Calistir 
    // (Kullanici 10'a basip Cikis diyene kadar bu satirda bekler)
    menuApp->run(); 

    // 4. Temizlik ve Kapanis
    // Program biterken hafizayi temizliyoruz
    delete menuApp;
    delete coreSystem;

    cout << "\n[SYSTEM] Graceful Shutdown Completed." << endl;
    return 0;
}