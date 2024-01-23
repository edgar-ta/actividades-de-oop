#include "../header/punto.h"
#include <iostream>

Punto::Punto(int x, int y): x(x), y(y) {}

void Punto::imprimir() {
    std::cout << "Punto(" << this->x << ", " << this->y << ")" << std::endl;
}
