Este proyecto tiene como propósito crear un programa que le pida al usuario una array de 10 enteros y obtenga los valores mínimo y máximo de dicha array, imprimiéndolos, por supuesto, después de haberlos obtenido. Para ello se deberá hacer uso de tres funciones: una que obtenga una array de enteros de la entrada del usuario, y dos que obtengan los números mayor y menor de esa array, respectivamente; un snippet de la [[Firma de la función|firma de las funciones]] es dado a continuación:

```cpp
void obtener_array_del_usuario(int array[], int n);

int obtener_maximo(const int array[], int n); 

int obtener_minimo(const int array[], int n);
```

A continuación, se detalla el propósito de cada función y una implementación posible.
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

# Obtener máximo

```cpp
int obtener_maximo(const int array[], int n); 
```

| Parámetro | Propósito |
| ---- | ---- |
| `n` | La longitud de la array dada |
| `array` | La array de cuyos valores se busca el mayor, de tipo `const` dado que sus datos no serán modificados |

Esta función obtiene el número máximo de entre los `n` elementos de `array`; debería ser capaz de manejar el caso cuando `array` tiene 1 o 0 elementos.

Ejemplo de implementación:
```cpp
int obtener_maximo(const int array[], int n) {
  if (n == 0) throw "No se puede obtener el máximo de una array de cero elementos";
  int maximo = array[0];
  for (int i = 1; i < n; i++) {
    const int valor = array[i];
    if (valor > maximo) maximo = valor;
  }
  return maximo;
}
```

# Obtener mínimo 

```cpp
int obtener_minimo(const int array[], int n); 
```

| Parámetro | Propósito |
| ---- | ---- |
| `n` | La longitud de la array dada |
| `array` | La array de cuyos valores se busca el mayor, de tipo `const` dado que sus datos no serán modificados |

Esta función es análoga a [[#Obtener máximo|obtener máximo]], y se encarga de obtener el número mínimo de entre los `n` elementos de `array`; debería ser capaz de manejar el caso cuando `array` tiene 1 o 0 elementos.

Ejemplo de implementación:
```cpp
int obtener_minimo(const int array[], int n) {
  if (n == 0) throw "No se puede obtener el mínimo de una array de cero elementos";
  int minimo = array[0];
  for (int i = 1; i < n; i++) {
    const int valor = array[i];
    if (valor < minimo) minimo = valor;
  }
  return minimo;
}
```

# Main

La función `main` debería cumplir con el propósito descrito al inicio de este documento.

Una posible implementación (que omite la implementación de las tres funciones auxiliares descritas anteriormente) es la siguiente:

```cpp
#include <iostream>
#include <cstdlib>

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
```
