#ifndef HECHICERO_H
#define HECHICERO_H

#include "Monstruo.h"

class Hechicero : public Monstruo{
public:
    Hechicero(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : Monstruo(nombre, fuerza, agilidad, inteligencia, tipo = 'H') {} 

    std::string getEspecie() const override{return "Hechicero";}
};

#endif
