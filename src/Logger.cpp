#include "../include/Logger.h"

// Singleton Tasarım Örüntüsü için Statik Değişken Başlatma
// C++98'de bu satır ZORUNLUDUR. Yoksa "Undefined reference" hatası verir.
Logger* Logger::instance = 0;