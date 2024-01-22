#ifndef PUNTO_H
#define PUNTO_H

#include "figura-geometrica.h"

class Punto : public FiguraGeometrica {
    public:
    Punto(int x, int y): FiguraGeometrica(x, y) {}
    Punto(const Punto& otro): FiguraGeometrica(otro.x, otro.y) {}
    virtual void imprimir() override;
};

#endif
