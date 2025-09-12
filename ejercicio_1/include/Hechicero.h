#ifdef HECHICERO_H
#define HECHICERO_H

#include "Monstruo.h"

class Hechicero : public Monstruo{
public:
    Hechicero(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), 'H' {} 

    std::string getEspecie() const override{return "Hechicero"}
}
