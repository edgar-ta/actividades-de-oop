#include "defensa.h"
#include <iostream>

Defensa::Defensa(int numero, std::string nombre, int minutosJugados, int numeroDeGoles): 
JugadorConGoles(numero, nombre, minutosJugados, numeroDeGoles)
{}

void Defensa::imprimir() {
    std::cout << "Tipo de Jugador: Defensa" << std::endl;
    JugadorConGoles::imprimir();
}
