#ifdef TROLL_H
#define TROLL_H

#include "Monstruo.h"

class Troll : public Monstruo{
public:
    Troll(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), 'T' {} 

    std::string getEspecie() const override{return "Troll"}
}
