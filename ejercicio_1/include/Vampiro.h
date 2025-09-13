#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "Monstruo.h"

class Vampiro : public Monstruo{
public:
    Vampiro(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : Monstruo(nombre, fuerza, agilidad, inteligencia, 'V') {} 

    std::string getEspecie() const override{return "Vampiro";}
}

#endif