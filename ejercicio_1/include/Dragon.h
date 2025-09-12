#ifdef DRAGON_H
#define DRAGON_H

#include "Monstruo.h"

class Dragon : public Monstruo{
public:
    Dragon(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), 'D' {} 

    std::string getEspecie() const override{return "Dragon"}
}
