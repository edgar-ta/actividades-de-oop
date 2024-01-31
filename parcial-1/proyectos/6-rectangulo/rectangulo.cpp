#include <iostream>

#include "rectangulo.h"

int Rectangulo::contador_de_rectangulos = 0;

float clamp(float minimum, float maximum, float value) {
  if (value < minimum) return minimum;
  if (value > maximum) return maximum;
  return value;
}

Rectangulo::Rectangulo() {
  id = Rectangulo::contador_de_rectangulos;
  Rectangulo::contador_de_rectangulos++;

  std::cout << "Creando al rectángulo xd" << std::endl;
}

Rectangulo::Rectangulo(float longitud, float anchura): Rectangulo() {
  set_longitud(longitud);
  set_anchura(anchura);
}

Rectangulo::~Rectangulo() {
  std::cout << "Eliminando al rectángulo xd" << std::endl;
}

void Rectangulo::set_longitud(float longitud) {
  this->longitud = clamp(0.0f, 20.0f, longitud);
}

void Rectangulo::set_anchura(float anchura) {
  this->anchura = clamp(0.0f, 20.0f, anchura);
}

float Rectangulo::get_area() { return anchura * longitud; }
float Rectangulo::get_perimetro() { return 2 * (anchura + longitud); }
float Rectangulo::get_longitud() { return longitud; }
float Rectangulo::get_anchura() { return anchura; }

void Rectangulo::imprimir_datos() {
  std::cout << "Valores del rectángulo con id=" << id << ":" << std::endl;
  std::cout << "\tanchura: " << anchura << std::endl;
  std::cout << "\tlongitud: " << longitud << std::endl;
  std::cout << std::endl;
  std::cout << "\tperimetro(): " << get_perimetro() << std::endl;
  std::cout << "\tarea(): " << get_area() << std::endl;
}

