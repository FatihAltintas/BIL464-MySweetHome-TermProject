
/*Memento Design Pattern'in 3 ayağı vardır:
Originator (Yaratıcı): MSHSystem (Durumu değiştiren).
Caretaker (Bakıcı): StateCaretaker (Kutuyu saklayan).
Memento (Hatıra/Kutu): İŞTE BU DOSYA (HomeMemento).
Bu dosya, sistemin o anki fotoğrafını (Snapshot) çeken ve saklayan "Kara Kutu"dur.
*/
#ifndef HOMEMEMENTO_H
#define HOMEMEMENTO_H
/* 
REQ-11: Durum değişmeden önce bu nesne oluşturulur.
REQ-12: Geri alma işlemi için bu nesne içindeki veri okunur.
*/
#include "ModeManager.h" // ModeType tanimi icin gerekli

class HomeMemento {
private:
    ModeType mode; // Sadece modu sakliyoruz
/*
analiz (LLR) aşamasında tüm cihazları saklamayı düşünmüştük.
Ancak kodlama aşamasında 'Memory Optimization' (Bellek Optimizasyonu) yaptık.
Sistemin 'Modu'nu (Örn: NIGHT) bilirsek, o moda ait kuralları tekrar çalıştırarak
cihazları eski haline getirebiliriz. Bu yüzden sadece Mod bilgisini saklamak
 hem daha az yer kaplıyor hem de aynı işi görüyor."
*/
public:
    // Constructor: Durumu kaydeder
    HomeMemento(ModeType m);
/*
 Memento nesneleri genellikle değiştirilemez (Immutable) tasarlanır.
 Bir kere oluşturulur, veriyi saklar, sonra sadece okunur.
*/
    // Getter: Kaydedilen modu geri verir
    ModeType getMode() const;
/*
saklanan bir anı/hatıra değiştirilmemelidir.
 Sadece okunmalıdır. Bu fonksiyonun veriyi değiştirmeyeceğini garanti ediyoruz
*/
};

#endif

/*
1)bu sınıf Memento rolündedir. MSHSystem (Originator) 
sınıfının iç durumunu (State) dış dünyaya sızdırmadan paketleyip saklamamızı sağlar. 
Bu paket daha sonra StateCaretaker tarafından saklanır."
2) "Kullanıcı 'Undo' dediğinde;
1.StateCaretaker sınıfından en son kaydedilen HomeMemento nesnesini alıyorum.
2.getMode() fonksiyonu ile içindeki eski modu (örneğin 'Normal Mode') öğreniyorum.
3.Sistemi tekrar o moda geçiriyorum."

3)ModeType bir Enum (tam sayı) olduğu için çok az yer kaplar (4 byte). 
Bunu pointer ile tutmak gereksiz karmaşıklık yaratırdı ve dinamik bellek yönetimi gerektirirdi. 
Değer tipi (Value type) olarak tutmak en performanslı yöntemdir."
*/
