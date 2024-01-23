El propósito de este proyecto es crear un programa que le pide una array de 10 números enteros al usuario y calcula el promedio de dichos números, para luego imprimirlo una vez que fue calculado, ayudándose de las funciones auxiliares `obtener_promedio` y `obtener_array_del_usuario`, cuya [[Firma de la función|firma]] se presenta a continuación:

```cpp
void obtener_array_del_usuario(int array[], int n);

float obtener_promedio(const int array[], int n);
```

A continuación se detalla el propósito de cada función usada y una implementación posible

# Obtener array del usuario

```cpp
void obtener_array_del_usuario(int array[], int n);
```

| Parámetro | Propósito |
| ---- | ---- |
| `n` | La longitud de la array dada |
| `array` | La array a llenar con datos enteros |

Esta función llena la array `array` con `n` enteros que le son pedidos al usuario a través de la consola, usando un ciclo `for`.

Ejemplo de implementación:
```cpp
void obtener_array_del_usuario(int array[], int n) {
  for (int i = 0; i < n; i++) {
    int value;

    std::cout << "Ingrese el siguiente número en la lista: ";
    std::cin >> value;
    array[i] = value;
  }
}
```

# Obtener promedio

```cpp
float obtener_promedio(const int array[], int n);
```

| Parámetro | Propósito |
| ---- | ---- |
| `array` | Array de cuyos números se va a obtener el promedio, de tipo `const` dado que sus datos no serán modificados |
| `n` | Longitud de la array (es decir, la cantidad de enteros que posee) |

Esta función tiene el propósito de calcular el promedio de los `n` números enteros de `array` (manejando el caso cuando `n = 0`), regresando para ello un valor de tipo `float`.

Ejemplo de implementación:
```cpp
float obtener_promedio(const int array[], int n) {
  if (n == 0) return 0;
  float promedio = 0;
  for (int i = 0; i < n; i++) {
    promedio += array[i];
  }
  return promedio / (float) n;
}
```

# Main

La función `main` debería lograr el propósito descrito al inicio de este documento; una posible implementación (omitiendo la implementación de las funciones auxiliares explicadas anteriormente) es la siguiente:

```cpp
#include <cstdlib>
#include <iostream>

void obtener_array_del_usuario(int array[], int n);
float obtener_promedio(const int array[], int n);

int main() {
  int n = 10;
  int array[n];
  
  std::cout << "Ingrese " << n << " números enteros para obtener su promedio" << std::endl;
  obtener_array_del_usuario(array, n);

  float promedio = obtener_promedio(array, n);

  std::cout << "El promedio es: " << promedio << std::endl;

  return EXIT_SUCCESS;
}
```
