#include <iostream>
#include <cmath>
#include "../header/circulo.h"

void Circulo::imprimir() {
    std::cout << "Círculo(x = " << x << ", y = " << y << "; r = " << radio << ")" << std::endl;
}

float Circulo::obtener_area() {
    return M_PI * radio * radio;
}

float Circulo::obtener_perimetro() {
    const float diametro = 2 * radio;
    return M_PI * diametro;
}
