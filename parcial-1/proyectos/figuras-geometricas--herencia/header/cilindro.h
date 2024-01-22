#ifndef CILINDRO_H
#define CILINDRO_H

#include "circulo.h"

#include <iostream>

class Cilindro : public Circulo {
    protected:
    int altura;

    public:
    Cilindro(int x, int y, int radio, int altura): Circulo(x, y, radio), altura(altura) {}

    void imprimir() override;
    float obtener_volumen();
};

#endif
