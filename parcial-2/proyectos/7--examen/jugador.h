#if !defined(__JUGADOR_H__)
#define __JUGADOR_H__

#include <string>

class Jugador {
    int numero;
    std::string nombre;
    int minutosJugados;

    public:
    Jugador(int numero, std::string nombre, int minutosJugados);

    void imprimir();

    int getNumero() { return numero; }
    std::string getNombre() { return nombre; }
    int getMinutosJugados() { return minutosJugados; }

    void setNumero(int numero) { this->numero = numero; };
    void setNombre(int nombre) { this->nombre = nombre; };
    void setMinutosJugados(int minutosJugados) { this->minutosJugados = minutosJugados; };
};

#endif // __JUGADOR_H__
