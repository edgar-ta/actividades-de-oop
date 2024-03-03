#include "delantero.h"
#include <iostream>

Delantero::Delantero(int numero, std::string nombre, int minutosJugados, int numeroDeGoles): 
JugadorConGoles(numero, nombre, minutosJugados, numeroDeGoles)
{}

void Delantero::imprimir() {
    std::cout << "Tipo de Jugador: Delantero" << std::endl;
    JugadorConGoles::imprimir();
}