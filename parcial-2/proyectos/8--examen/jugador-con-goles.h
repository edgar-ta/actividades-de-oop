#if !defined(__JUGADOR_CON_GOLES_H__)
#define __JUGADOR_CON_GOLES_H__

#include "jugador.h"
#include <string>

class JugadorConGoles : public Jugador {
    int numeroDeGoles;

    public:
    JugadorConGoles(int numero, std::string nombre, int minutosJugados, int numeroDeGoles);

    int getNumeroDeGoles() { return numeroDeGoles; }
    void setNumeroDeGoles(int numeroDeGoles) { this->numeroDeGoles = numeroDeGoles; }

    void imprimir();
};

#endif // __JUGADOR_CON_GOLES_H__
