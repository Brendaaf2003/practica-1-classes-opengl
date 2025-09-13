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
    // Carga los participantes desde torneo.txt
    void cargarParticipantes(const std::string& archivo);

    // Ejecuta todas las rondas y guarda en resultados_torneo.txt
    void ejecutar(const std::string& archivoResultados);

    // Destructor para liberar memoria
    ~Torneo();
};

#endif
