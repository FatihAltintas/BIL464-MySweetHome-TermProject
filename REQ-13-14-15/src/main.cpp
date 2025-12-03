#include <iostream>
#include "../include/SystemManager.h"
#include "../include/Detector.h"


int main() {
    SystemManager* manager = SystemManager::getInstance();
    
    std::cout << "=== MSH System Setup ===" << std::endl;
    
    // Cihazları Kur
    manager->addBulkDevices("Alarm", 1);          
    manager->addBulkDevices("Light", 2);          
    manager->addBulkDevices("Camera", 1);         
    manager->addBulkDevices("SmokeDetector", 1);  
    
    // Başlangıç Durumu
    manager->listDevices();

    // --- SENARYO 1: Güvenlik İhlali (REQ13) ---
    std::cout << "\n\n>>> SCENARIO 1: Security Breach Test <<<" << std::endl;
    
    // 1. Sistemi Aktif Et
    manager->setSystemStatus("ACTIVE"); 
    
    // 2. Kamerada hareket simüle et (Bunu yapmak için kamerayı bulup set etmeliyiz)
    // Gerçek hayatta sensör donanımsal sinyal yollar.
    Camera* cam = dynamic_cast<Camera*>(manager->getDevice(4)); 
    if (cam) cam->setMotionDetected(true); // Hareket var!

    // 3. Sistem Döngüsünü Çalıştır (Birkaç adım)
    // 1. Döngü: Hareketi algılamalı, Polisi aramalı.
    manager->runCycle(100); 

    // --- SENARYO 2: Yangın ve Blink (REQ14 & REQ15) ---
    std::cout << "\n\n>>> SCENARIO 2: Fire Hazard & Blinking Lights <<<" << std::endl;
    
    // Önce sistemi temizleyelim
    manager->setSystemStatus("INACTIVE"); // Alarmı susturur
    if (cam) cam->setMotionDetected(false); // Hareketi sıfırla

    // Duman algılandı simülasyonu (ID 5: SmokeDetector)
    // Detector.h include etmediysek dynamic cast hata verebilir, Device.h'a virtual metod eklemek daha temizdir 
    // ama şimdilik logic çalışır.

    // (Simülasyon: Duman sensörü tetiklendi varsayalım. 
    //  Kodu karmaşıklaştırmamak için manuel tetikleme kodu yerine 
    //  SystemManager içinde test amaçlı bir "forceHazard" fonksiyonu yazılabilir
    //  veya yukarıdaki gibi cast edilebilir.)
    
    std::cout << "[Time 0ms] Checking sensors..." << std::endl;
    manager->runCycle(100); // 100ms geçti
    
    // Alarmın çaldığını varsayalım (Hazard triggered)
    // 1 saniye boyunca (10 x 100ms) döngüyü çalıştırırsak ışıkların yanıp söndüğünü görmeliyiz (REQ15)
    
    // Hazard'ı manuel tetikle (Alarm zaten loop'ta tetiklenecek duman varsa)
    // Biz burada REQ15 test etmek için alarmı manuel açalım:
    // (Alarm class'ına erişip set edebiliriz ama SystemManager private yönetiyor)
    // Bu senaryoyu tam görmek için duman sensörünü set etmemiz lazım.
    
    std::cout << "--- Simulating 2 seconds of Alarm State ---" << std::endl;
    // Alarmı dışarıdan tetikleyelim (Test için public metoda ihtiyaç olabilir, şimdilik varsayalım)
    // Veya Hazard logic'i çalıştıralım:
    // SmokeDetector* sd = (SmokeDetector*)manager->getDevice(5); sd->setSmokeDetected(true);
    
    for (int t = 0; t < 2000; t += 500) { // 500ms adımlarla 2 saniye
        std::cout << "[Time " << t << "ms] Cycle running..." << std::endl;
        manager->runCycle(500); 
    }

    delete manager;
    return 0;
}