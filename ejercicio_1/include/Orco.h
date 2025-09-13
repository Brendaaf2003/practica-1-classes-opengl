#ifndef OCRO_H
#define OCRO_H

#include "Monstruo.h"

class Orco : public Monstruo{
public:
    Orco(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char tipo)
    : Monstruo(nombre, fuerza, agilidad, inteligencia, tipo = 'O') {}

    std::string getEspecie() const override{return "Ocro";}
};

#endif


