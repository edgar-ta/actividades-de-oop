#include <iostream>
#include <string>

#include "portero.h"
#include "defensa.h"
#include "medio.h"
#include "delantero.h"

void imprimirDatosSegunTipo(int tipo, int numero, std::string nombre, int minutosJugados, int numeroDeGoles);
void imprimirLetreroSegunTipo(int tipo);

int main() {
    int numero; 
    std::string nombre; 
    int minutosJugados; 
    int numeroDeGoles;

    for (int tipo = 0; tipo < 4; tipo++) {
        imprimirLetreroSegunTipo(tipo);

        std::cout << "Ingrese el número del jugador: " << std::endl;
        std::cin >> numero;

        std::cout << "Ingrese el nombre del jugador: " << std::endl;
        std::cin >> nombre;

        std::cout << std::endl << "Ingrese los minutos jugados del jugador: " << std::endl;
        std::cin >> minutosJugados;

        if (tipo != 0) {
            std::cout << "Ingrese el número de goles del jugador: " << std::endl;
            std::cin >> numeroDeGoles;
        }
        imprimirDatosSegunTipo(tipo, numero, nombre, minutosJugados, numeroDeGoles);
    }
    return 0;
}

void imprimirDatosSegunTipo(int tipo, int numero, std::string nombre, int minutosJugados, int numeroDeGoles) {
    switch(tipo) {
        case 0:
        Portero(numero, nombre, minutosJugados).imprimir();
        break;

        case 1:
        Defensa(numero, nombre, minutosJugados, numeroDeGoles).imprimir();
        break;

        case 2:
        Medio(numero, nombre, minutosJugados, numeroDeGoles).imprimir();
        break;

        case 3:
        Delantero(numero, nombre, minutosJugados, numeroDeGoles).imprimir();
        break;
    }
}

void imprimirLetreroSegunTipo(int tipo) {
    switch(tipo) {
        case 0: std::cout << "Ingrese los datos del portero" << std::endl; break;
        case 1: std::cout << "Ingrese los datos del defensa" << std::endl; break;
        case 2: std::cout << "Ingrese los datos del medio" << std::endl; break;
        case 3: std::cout << "Ingrese los datos del delantero" << std::endl; break;
    }
}
