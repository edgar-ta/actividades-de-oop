#include "medio.h"
#include <iostream>

Medio::Medio(int numero, std::string nombre, int minutosJugados, int numeroDeGoles): 
JugadorConGoles(numero, nombre, minutosJugados, numeroDeGoles)
{}

void Medio::imprimir() {
    std::cout << "Tipo de Jugador: Medio" << std::endl;
    JugadorConGoles::imprimir();
}
