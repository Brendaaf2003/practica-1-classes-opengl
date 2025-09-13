#include "Torneo.h"
#include "Orco.h"
#include "Dragon.h"
#include "Troll.h"
#include "Vampiro.h"
#include "Esqueleto.h"
#include "Hechicero.h"
#include <fstream>
#include <random>
#include <iostream>

/**
 * Carga los participantes del torneo desde un archivo.
 * @param archivo Ruta del archivo con los participantes.
 */
void Torneo::cargarParticipantes(const std::string& archivo) {
    std::ifstream in(archivo);
    if (!in.is_open()) {
        std::cerr << "Error al abrir el archivo de participantes: " << archivo << std::endl;
        return;
    }
    char tipo;
    std::string nombre;
    int f, a, i;

    //Lee el archivo y crea los monstruos correspondientes
    while (in >> tipo >> nombre >> f >> a >> i) {
        Monstruo* m = nullptr;
        switch (tipo) {
            case 'O': m = new Orco(nombre, f, a, i, tipo); break;
            case 'D': m = new Dragon(nombre, f, a, i, tipo); break;
            case 'T': m = new Troll(nombre, f, a, i, tipo); break;
            case 'V': m = new Vampiro(nombre, f, a, i, tipo); break;
            case 'E': m = new Esqueleto(nombre, f, a, i, tipo); break;
            case 'H': m = new Hechicero(nombre, f, a, i, tipo); break;
        }
        if (m) participantes.push_back(m);
    }
}

/**
 * Ejecuta el torneo y registra los resultados en un archivo.
 * @param archivoResultados Ruta del archivo para guardar los resultados.
 */
void Torneo::ejecutar(const std::string& archivoResultados) {
    std::ofstream out(archivoResultados);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> tipoDist(0, 2); // 0=f,1=i,2=e

    //Definimos las rondas del torneo
    std::vector<std::string> rondas = {
        "--- Octavos de final ---",
        "--- Cuartos de final ---",
        "--- Semifinales ---",
        "--- Final ---"
    };

    int ronda = 0;
    while (participantes.size() > 1) {
        out << rondas[ronda++] << "\n";
        std::vector<Monstruo*> ganadores;

        //Empareja a los participantes y realiza las batallas
        for (size_t i = 0; i < participantes.size(); i += 2) {
            char tipoBatalla;
            int t = tipoDist(gen);
            if (t == 0) tipoBatalla = 'f';
            else if (t == 1) tipoBatalla = 'i';
            else tipoBatalla = 'e';

            Batallas b(participantes[i], participantes[i+1], tipoBatalla);
            Monstruo* ganador = b.ejecutar(out);
            ganadores.push_back(ganador);

            out << participantes[i]->getNombre() << " vs " 
                << participantes[i+1]->getNombre() 
                << " → Gana " << ganador->getNombre() << "\n";
        }
        participantes = ganadores;
        out << "\n";
    }

    out << "Campeón: " << participantes[0]->getNombre() << "\n";
}

//Lista de participantes
const std::vector<Monstruo*>& Torneo::obtenerParticipantes() const {
    return participantes;
}

//Destructor para liberar memoria
Torneo::~Torneo() {
    for (auto m : participantes) delete m;
}
