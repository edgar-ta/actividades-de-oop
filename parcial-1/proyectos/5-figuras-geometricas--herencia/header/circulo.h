#ifndef CIRCULO_H
#define CIRCULO_H

#include "punto.h"

class Circulo : public Punto {
    protected:
    int radio;

    public:
    Circulo(int x, int y, int radio): Punto(x, y), radio(radio) {}
    void imprimir();
    float obtener_perimetro();
    float obtener_area();
};

#endif
