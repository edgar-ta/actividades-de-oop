#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

class FiguraGeometrica {
    protected:
    int x, y;

    public:
    FiguraGeometrica(int x, int y): x(x), y(y) {}

    virtual void imprimir() = 0;
};

#endif
