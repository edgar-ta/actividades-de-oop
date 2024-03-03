#if !defined(__MEDIO_H__)
#define __MEDIO_H__

#include "jugador-con-goles.h"
#include <string>

class Medio     : public JugadorConGoles {
    public:
    Medio(int numero, std::string nombre, int minutosJugados, int numeroDeGoles);
    void imprimir();
};

#endif // __MEDIO_H__
