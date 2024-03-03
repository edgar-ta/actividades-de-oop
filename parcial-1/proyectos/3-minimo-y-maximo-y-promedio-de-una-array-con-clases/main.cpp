#include <cstdlib>
#include <iostream>

class Array {
  private:
    std::size_t n;
    int* valores;

  public:
    Array(std::size_t);
    ~Array();
    float obtener_promedio();
    int obtener_maximo();
    int obtener_minimo();
    void imprimir();

    static Array obtener_array_del_usuario(std::size_t n);
};

int main() {
  Array array = Array::obtener_array_del_usuario(10);
  array.imprimir();

  return EXIT_SUCCESS;
}

Array::Array(std::size_t n): n(n), valores(new int[n]) {}

Array::~Array() {
  if (n > 0 && valores != nullptr) {
    delete[] valores;
  }
}

float Array::obtener_promedio() {
  if (n == 0) return 0;
  float promedio = 0;
  for (int i = 0; i < n; i++) {
    promedio += valores[i];
  }
  return promedio / (float) n;
}

int Array::obtener_maximo() {
  if (n == 0) throw "No se puede obtener el máximo de una array de cero elementos";
  int maximo = valores[0];
  for (int i = 1; i < n; i++) {
    const int valor = valores[i];
    if (valor > maximo) maximo = valor;
  }
  return maximo;
}

int Array::obtener_minimo() {
  if (n == 0) throw "No se puede obtener el mínimo de una array de cero elementos";
  int minimo = valores[0];
  for (int i = 1; i < n; i++) {
    const int valor = valores[i];
    if (valor < minimo) minimo = valor;
  }
  return minimo;
}

Array Array::obtener_array_del_usuario(std::size_t n) {
  Array array(n);
  for (int i = 0; i < n; i++) {
    int value;

    std::cout << "Ingrese el siguiente número en la lista: ";
    std::cin >> value;
    array.valores[i] = value;
  }
  return array;
}

void Array::imprimir() {
  std::cout << "Imprimiendo valores de la `Array`" << std::endl;
  std::cout << "\tEl promedio es: " << obtener_promedio() << std::endl;
  std::cout << "\tEl máximo es: " << obtener_maximo() << std::endl;
  std::cout << "\tEl mínimo es: " << obtener_minimo() << std::endl;
  std::cout << "Fin de la impresión de la `Array`" << std::endl;
}
