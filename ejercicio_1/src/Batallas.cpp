#include "../include/Batallas.h"
#include <iostream>
#include <random>
#include <utility>

/**
 * Constructor de la clase Batallas.
 * @param a Primer monstruo.
 * @param b Segundo monstruo.
 * @param tipo Tipo de batalla (fuerza, ingenio, espiritual).
 */
Batallas::Batallas(Monstruo* a, Monstruo* b, char tipo)
    : m1(a), m2(b), tipoBatalla(tipo) {}


/**
 * Ejecuta la batalla entre los dos monstruos.
 * @param out Flujo de salida para registrar los resultados.
 * @return Puntero al monstruo ganador.
 */
Monstruo* Batallas::ejecutar(std::ofstream& out) {
    out << "Batalla ";
    if (tipoBatalla == 'f') out << "de Fuerza\n";
    else if (tipoBatalla == 'i') out << "de Ingenio\n";
    else if (tipoBatalla == 'e') out << "Espiritual\n";

    out << m1->getNombre() << " (" << m1->getEspecie() << ") vs "
        << m2->getNombre() << " (" << m2->getEspecie() << ")";
    
    int puntos1;
    int puntos2;

    // Calcular puntos según el tipo de batalla
    if (tipoBatalla == 'f'){
        puntos1 = m1->getFuerza() + m1->getAgilidad();
        puntos2 = m2->getFuerza() + m2->getAgilidad();
    } else if (tipoBatalla == 'i'){
        puntos1 = m1->getAgilidad() + m1->getInteligencia();
        puntos2 = m2->getAgilidad() + m2->getInteligencia();
    } else if (tipoBatalla == 'e'){
        puntos1 = m1->getFuerza() + m1->getInteligencia();
        puntos2 = m2->getFuerza() + m2->getInteligencia();
    } else {
        puntos1 = 0;
        puntos2 = 0;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribucionTotal(0, puntos1 + puntos2 - 1);

    int victorias1 = 0;
    int victorias2 = 0;
        
    for (int i = 1; i <= 3; ++i){
        int resultado = distribucionTotal(gen);

        if (resultado < puntos1) {
            victorias1++;
            out << "Encuentro " << i << ": " << m1->getNombre() << " gana. \n";
        } else if (puntos2 > puntos1) {
            victorias2++;
            out << "Encuentro " << i << ": " << m2->getNombre() << " gana. \n";
        } else {
            out << "Hubo empate";
        }
    }

    out << "\n";

    //Ganador de la batalla
    if (victorias1 > victorias2) {
        out << "El ganador de la batalla es: " << m1->getNombre()
            << " (" << m1->getEspecie() << ")\n\n";
        return m1;
    } else if (victorias2 > victorias1) {
        out << "El ganador de la batalla es: " << m2->getNombre()
            << " (" << m2->getEspecie() << ")\n\n";
        return m2;
    }  else {
        out << "Hubo un empate";
        return m1;
    }

}






    