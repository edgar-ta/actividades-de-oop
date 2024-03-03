#include <iostream>

#include "../header/cilindro.h"

void Cilindro::imprimir() {
    std::cout << "Cilindro(x = " << x << ", y = " << y << ", r = " << radio << ", h = " << altura << ")" << std::endl;
}

float Cilindro::obtener_volumen()  {
    return Circulo::obtener_area() * altura;
}

float Cilindro::obtener_perimetro() {
  return 2 * (altura + Circulo::obtener_perimetro());
}

float Cilindro::obtener_area() {
  return 2 * Circulo::obtener_area() + Circulo::obtener_perimetro() * altura;
}
