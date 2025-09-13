#ifndef TROLL_H
#define TROLL_H

#include "Monstruo.h"

class Troll : public Monstruo{
public:
    Troll(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : Monstruo(nombre, fuerza, agilidad, inteligencia, 'T') {} 

    std::string getEspecie() const override{return "Troll";}
}

#endif