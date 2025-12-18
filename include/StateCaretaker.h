/*
Bu dosya, senin Memento Design Pattern yapısının "Depo" veya "Kütüphaneci" kısmıdır.
 "Tarihçe Yönetimi" (History Management).

 TASARIM ÖRÜNTÜSÜ: MEMENTO PATTERN
 Rolü: "Caretaker" (Bakıcı / Saklayıcı).

Memento nesnelerini güvenli bir yerde tutar, ancak içlerini asla açıp okumaz.
Sadece "Al bunu sakla" (saveState) ve "En sonuncuyu geri ver" (undo) emirlerini uygular
*/


#ifndef STATECARETAKER_H
#define STATECARETAKER_H

#include "HomeMemento.h"
#include <vector>

class StateCaretaker {
private:
    std::vector<HomeMemento*> historyStack;
/*
// REQ-11: "Sistem önceki durumları state listesine kaydetmelidir."
 pointer: Nesnelerin kopyasını oluşturup belleği şişirmek yerine,
 heap bellekte oluşturulan nesnelerin adreslerini (pointer) tutuyorum.
 Bu sayede bellek yönetimini (Memory Management) daha verimli
*/
public:
    StateCaretaker();
/*
Destructor önemlidir çünkü vector içindeki pointerları 
tek tek 'delete' ile silip belleği temizlememiz gerekir.
*/
    ~StateCaretaker();

    /*
Save REQ-11'i karşılar.
 Yeni oluşturulan bir Memento'yu alır ve listenin en sonuna ekler.
*/
    void saveState(HomeMemento* m);

/*
 UNDO (GERİ ALMA) 
REQ-12'yi karşılar.
 Listenin en sonundaki (en güncel) kaydı listeden çıkarır ve geri döndürür.
*/
    HomeMemento* undo();
};

#endif

/*
Caretaker 'Bakıcı' demektir. HomeMemento nesnelerini 
(yani sistemin eski durumlarını) saklamakla yükümlüdür. 
Ancak Memento'nun içeriğini (hangi modda olduğunu) bilmez ve değiştirmez. 
Sadece saklar ve istendiğinde geri verir. Bu sayede Encapsulation (Kapsülleme) korunmuş olur.

undo mantığı
LIFO (Last-In, First-Out / Son giren ilk çıkar) mantığıyla çalışıyor.
Kullanıcı her mod değiştirdiğinde saveState ile durumu vector'ün sonuna ekliyorum (push_back).
Kullanıcı 'Geri Al' dediğinde undo fonksiyonu vector'ün en sonundaki elemanı alıyor (back) ve listeden düşürüyor (pop_back).
Böylece bir adım geriye gitmiş oluyoruz."
*/
