#ifndef FOREIGNLIGHT_H
#define FOREIGNLIGHT_H

#include <string>

// Bu sinif Device'dan turemez! (3. Parti Cihaz)
class ForeignLight {
private:
    std::string model;
public:
    ForeignLight(const std::string& m);
    ~ForeignLight();

    // Bizim sistem 'powerOn' beklerken, bu cihazda 'turnOn220V' var.
    // Iste uyumsuzluk burada!
    void turnOn220V();
    void turnOff220V();
    std::string getModelName() const;
};

#endif