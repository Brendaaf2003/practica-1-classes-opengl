#ifndef TORNEO_H
#define TORNEO_H

#include "Monstruo.h"
#include "Batallas.h"
#include <vector>
#include <string>

class Torneo {
private:
    std::vector<Monstruo*> participantes;
public:

    void cargarParticipantes(const std::string& archivo);
    void ejecutar(const std::string& archivoResultados);
    const std::vector<Monstruo*>& obtenerParticipantes() const;

    ~Torneo();
};

#endif
