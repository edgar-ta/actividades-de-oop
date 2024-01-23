#ifndef CILINDRO_H
#define CILINDRO_H

#include "circulo.h"

#include <iostream>

class Cilindro : public Circulo {
    protected:
    int altura;

    public:
    Cilindro(int x, int y, int radio, int altura): Circulo(x, y, radio), altura(altura) {}

    void imprimir();
    float obtener_volumen();
    float obtener_perimetro();
    float obtener_area();
};

#endif
