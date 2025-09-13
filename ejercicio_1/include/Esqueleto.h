#ifndef ESQUELETO_H
#define ESQUELETO_H

#include "Monstruo.h"

class Esqueleto : public Monstruo{
public:
    Esqueleto(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : Monstruo(nombre, fuerza, agilidad, inteligencia, tipo = 'E') {} 

    std::string getEspecie() const override{return "Esqueleto"; }
};

#endif