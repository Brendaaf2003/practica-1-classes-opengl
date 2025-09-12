#ifdef ESQUELETO_H
#define ESQUELETO_H

#include "Monstruo.h"

class Esqueleto : public Monstruo{
public:
    Esqueleto(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), 'E' {} 

    std::string getEspecie() const override{return "Esqueleto"}
}
