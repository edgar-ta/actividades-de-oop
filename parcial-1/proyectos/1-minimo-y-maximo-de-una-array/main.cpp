#include <cstdlib>
#include <iostream>

void obtener_array_del_usuario(int array[], int n);
int obtener_maximo(const int array[], int n);
int obtener_minimo(const int array[], int n);

int main() {
  int n = 10;
  int array[n];
  
  std::cout << "Ingrese " << n << " números enteros para obtener los valores máximo y mínimo" << std::endl;
  obtener_array_del_usuario(array, n);

  int maximo = obtener_maximo(array, n);
  int minimo = obtener_minimo(array, n);

  std::cout << "El valor máximo es: " << maximo << std::endl;
  std::cout << "El valor mínimo es: " << minimo << std::endl;

  return EXIT_SUCCESS;
}

void obtener_array_del_usuario(int array[], int n) {
  for (int i = 0; i < n; i++) {
    int valor;

    std::cout << "Ingrese el siguiente número en la lista: ";
    std::cin >> valor;
    array[i] = valor;
  }
}

int obtener_maximo(const int array[], int n) {
  if (n == 0) throw "No se puede obtener el máximo de una array de cero elementos";
  int maximo = array[0];
  for (int i = 1; i < n; i++) {
    const int valor = array[i];
    if (valor > maximo) maximo = valor;
  }
  return maximo;
}

int obtener_minimo(const int array[], int n) {
  if (n == 0) throw "No se puede obtener el mínimo de una array de cero elementos";
  int minimo = array[0];
  for (int i = 1; i < n; i++) {
    const int valor = array[i];
    if (valor < minimo) minimo = valor;
  }
  return minimo;
}

