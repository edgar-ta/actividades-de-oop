#if !defined(__PORTERO_H__)
#define __PORTERO_H__

#include "jugador.h"
#include <string>

class Portero   : public Jugador {
    public:
    Portero(int numero, std::string nombre, int minutosJugados);
    void imprimir();
};

#endif // __PORTERO_H__
