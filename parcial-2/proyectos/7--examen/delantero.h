#if !defined(__DELANTERO_H__)
#define __DELANTERO_H__

#include "jugador-con-goles.h"
#include <string>

class Delantero : public JugadorConGoles {
    public:
    Delantero(int numero, std::string nombre, int minutosJugados, int numeroDeGoles);
    void imprimir();
};

#endif // __DELANTERO_H__
