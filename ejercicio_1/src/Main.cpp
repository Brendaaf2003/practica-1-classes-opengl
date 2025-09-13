/**
 * @file Main.cpp
 * @brief Programa principal para ejecutar batallas o torneos de monstruos.
 */

#include "../include/Torneo.h"
#include "../include/Batallas.h"
#include "../include/Dragon.h"
#include "../include/Esqueleto.h"
#include "../include/Hechicero.h"
#include "../include/Orco.h"
#include "../include/Troll.h"
#include "../include/Vampiro.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Creamos los monstruos segun el tipo
Monstruo* crearMonstruo(char tipo, const std::string& nombre, int f, int a, int i) {
    switch (tipo) {
        case 'O': return new Orco(nombre, f, a, i, tipo);
        case 'D': return new Dragon(nombre, f, a, i, tipo);
        case 'T': return new Troll(nombre, f, a, i, tipo);
        case 'V': return new Vampiro(nombre, f, a, i, tipo);
        case 'E': return new Esqueleto(nombre, f, a, i, tipo);
        case 'H': return new Hechicero(nombre, f, a, i, tipo);
        default: return nullptr;
    }
}

//Se hizo un menú para elegir entre batallas o torneo
//Tambien se manejan los archivos de entrada y salida
int main() {
    int opcion;
    std::cout << "=== Simulador de Monstruos ===" << std::endl;
    std::cout << "1. Ejecutar batallas desde Input/batallas.txt" << std::endl;
    std::cout << "2. Ejecutar torneo desde Input/torneo.txt" << std::endl;
    std::cout << "Elige una opcion: ";
    std::cin >> opcion;

    if (opcion == 1) {
        std::ifstream archivo("Input/batallas.txt");
        std::ofstream salida("Output/resultados.txt");

        if (!archivo.is_open() || !salida.is_open()) {
            std::cerr << "Error al abrir los archivos. Asegurate de que 'Input/batallas.txt' y 'Output/' existen." << std::endl;
            return 1;
        }

        while (!archivo.eof()) {
            char tipo1, tipo2, tipoBatalla;
            std::string nombre1, nombre2;
            int f1, a1, i1, f2, a2, i2;

            archivo >> tipo1 >> nombre1 >> f1 >> a1 >> i1
                    >> tipo2 >> nombre2 >> f2 >> a2 >> i2
                    >> tipoBatalla;

            if (archivo.fail()) break; // fin del archivo o error

            Monstruo* m1 = crearMonstruo(tipo1, nombre1, f1, a1, i1);
            Monstruo* m2 = crearMonstruo(tipo2, nombre2, f2, a2, i2);
            
            if (m1 && m2) {
                Batallas batalla(m1, m2, tipoBatalla);
                batalla.ejecutar(salida);
            }

            delete m1;
            delete m2;
        }

        std::cout << "Batallas finalizadas. Revisa Output/resultados.txt" << std::endl;

    } else if (opcion == 2) {
        Torneo torneo;
        torneo.cargarParticipantes("Input/torneo.txt");
        if (torneo.obtenerParticipantes().size() < 2) {
            std::cerr << "Error: No hay suficientes participantes en el archivo 'Input/torneo.txt'." << std::endl;
            return 1;
        }
        torneo.ejecutar("Output/resultados_torneo.txt");
        std::cout << "Torneo finalizado. Revisa Output/resultados_torneo.txt" << std::endl;
    } else {
        std::cout << "Opcion invalida." << std::endl;
    }

    return 0;
}