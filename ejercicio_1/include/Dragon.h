#ifndef DRAGON_H
#define DRAGON_H

#include "Monstruo.h"

class Dragon : public Monstruo{
public:
    Dragon(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : Monstruo(nombre, fuerza, agilidad, inteligencia, tipo = 'D') {} 

    std::string getEspecie() const override{return "Dragon";}
};

#endif
