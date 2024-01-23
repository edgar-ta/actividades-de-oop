#include <cstdlib>
#include <iostream>

#include "header/punto.h"
#include "header/circulo.h"
#include "header/cilindro.h"

int main() {
    Circulo circulo(5, 5, 1);
    Cilindro cilindro(5, 5, 1, 10);
    Punto punto(5, 5);

    punto.imprimir();
    circulo.imprimir();
    cilindro.imprimir();

    std::cout << "El número de figuras geométricas creadas es: " << FiguraGeometrica::contador_de_figuras << std::endl;

    return EXIT_SUCCESS;
}
