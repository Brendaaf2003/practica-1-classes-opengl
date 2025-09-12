#ifdef OCRO_H
#define OCRO_H

#include "Monstruo.h"

class Orco : public Monstruo{
public:
    Ocro(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), 'O' {} 

    std::string getEspecie() const override{return "Ocro"}
}
