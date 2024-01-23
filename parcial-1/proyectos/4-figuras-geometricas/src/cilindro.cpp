#include <iostream>

#include "../header/cilindro.h"

void Cilindro::imprimir() {
    std::cout << "Cilindro(x = " << x << ", y = " << y << ", r = " << radio << ", h = " << altura << ")" << std::endl;
}

float Cilindro::obtener_volumen()  {
    return Circulo::obtener_area() * altura;
}
