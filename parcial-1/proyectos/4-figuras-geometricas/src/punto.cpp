#include "../header/punto.h"
#include <iostream>

void Punto::imprimir() {
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}
