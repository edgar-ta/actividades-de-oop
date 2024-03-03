#ifndef __DEFENSA_H__
#define __DEFENSA_H__

#include "jugador-con-goles.h"
#include <string>

class Defensa   : public JugadorConGoles {
    public:
    Defensa(int numero, std::string nombre, int minutosJugados, int numeroDeGoles);
    void imprimir();
};

#endif
