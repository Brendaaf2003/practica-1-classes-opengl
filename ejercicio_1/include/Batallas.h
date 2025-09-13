#ifndef BATALLAS_H
#define BATALLAS_H

#include "Monstruo.h"
#include <string>
#include <fstream>
#include <random>

class Batallas {
private:
    Monstruo* m1;
    Monstruo* m2;
    char tipoBatalla;
public:
    Batallas(Monstruo* a, Monstruo* b, char tipo);
    Monstruo* ejecutar(std::ofstream& out);
};

#endif
