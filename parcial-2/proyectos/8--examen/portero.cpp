#include "portero.h"
#include <iostream>

Portero::Portero(int numero, std::string nombre, int minutosJugados): 
Jugador(numero, nombre, minutosJugados)
{}

void Portero::imprimir() {
    std::cout << "Tipo de Jugador: Portero" << std::endl;
    Jugador::imprimir();
}
