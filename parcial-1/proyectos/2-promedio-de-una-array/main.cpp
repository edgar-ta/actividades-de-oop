#include <cstdlib>
#include <iostream>

void obtener_array_del_usuario(int array[], int n);
float obtener_promedio(const int array[], int n);

void obtener_array_del_usuario(int array[], int n) {
  for (int i = 0; i < n; i++) {
    int value;

    std::cout << "Ingrese el siguiente número en la lista: ";
    std::cin >> value;
    array[i] = value;
  }
}

float obtener_promedio(const int array[], int n) {
  if (n == 0) return 0;
  float promedio = 0;
  for (int i = 0; i < n; i++) {
    promedio += array[i];
  }
  return promedio / (float) n;
}

int main() {
  int n = 10;
  int array[n];
  
  std::cout << "Ingrese " << n << " números enteros para obtener su promedio" << std::endl;
  obtener_array_del_usuario(array, n);

  float promedio = obtener_promedio(array, n);

  std::cout << "El promedio es: " << promedio << std::endl;

  return EXIT_SUCCESS;
}


