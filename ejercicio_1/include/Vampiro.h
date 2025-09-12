#ifdef VAMPIRO_H
#define VAMPIRO_H

#include "Monstruo.h"

class Vampiro : public Monstruo{
public:
    Vampiro(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), 'V' {} 

    std::string getEspecie() const override{return "Vampiro"}
}
