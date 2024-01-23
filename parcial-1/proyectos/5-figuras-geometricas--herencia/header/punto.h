#ifndef PUNTO_H
#define PUNTO_H

#include "figura-geometrica.h"

class Punto : public FiguraGeometrica {
  protected:
    int x, y;

  public:
    Punto(int, int);
    void imprimir();
};

#endif
