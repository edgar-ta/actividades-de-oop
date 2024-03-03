#include "jugador.h"
#include <iostream>

Jugador::Jugador(int numero, std::string nombre, int minutosJugados):
numero(numero), nombre(nombre), minutosJugados(minutosJugados)
{}

void Jugador::imprimir() {
    std::cout 
        << "Nombre: " << nombre << std::endl
        << "Numero: " << numero << std::endl
        << "Minutos Jugados: " << minutosJugados << std::endl
        ;
}
