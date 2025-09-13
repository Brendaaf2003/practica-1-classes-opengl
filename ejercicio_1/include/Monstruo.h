#ifndef MONSTRUO_H
#define MONSTRUO_H

#include <string>
#include <iostream>

class Monstruo {
protected:
    std::string nombre;
    int fuerza;
    int agilidad;
    int inteligencia;
    char tipo;

public:
    Monstruo(const std::string& nombre, int fuerza, int agilidad, int inteligencia,char tipo)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), tipo(tipo) {}

    virtual ~Monstruo() {}

    std::string getNombre() const{return nombre;}
    int getFuerza() const{return fuerza;}
    int getAgilidad() const{return agilidad;}
    int getInteligencia() const{return inteligencia;}
    char getTipo() const{return tipo;}

    virtual std::string getEspecie() const = 0;
};

#endif