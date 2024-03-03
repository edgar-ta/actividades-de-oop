#include "jugador-con-goles.h"
#include <iostream>

JugadorConGoles::JugadorConGoles(int numero, std::string nombre, int minutosJugados, int numeroDeGoles):
Jugador(numero, nombre, minutosJugados), numeroDeGoles(numeroDeGoles)
{}

void JugadorConGoles::imprimir() {
    Jugador::imprimir();
    std::cout << "Número de goles: " << numeroDeGoles << std::endl;
}