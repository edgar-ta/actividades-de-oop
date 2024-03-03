# La función `to_string`

Definida en el espacio de nombres estándar del encabezado `string`, esta función permite obtener la representación textual de diferentes tipos de valores numéricos, como enteros, enteros largos, números flotantes de precisión sencilla, de precisión doble, etc. Esta conversión se realiza bajo los mismos criterios que la función `format` (definida también en el espacio de nombres estándar, ahora en el encabezado `format`) y nótese que, por lo tanto, el resultado puede diferir bastante de aquél que `std::cout` imprime por defecto, especialmente cuando se trata de números de punto flotante, como ilustra el ejemplo siguiente:

```c++
// main.cpp; programa que compara la salida de las funciones
// `std::cout` y `std::to_string` para un mismo caso extremo

#include <iostream> // para poder imprimir valores en la consola
#include <string>   // para poder usar la función `to_string`

int main() {
    constexpr double valor = 1e40; // un valor muy pequeño a imprimir
    std::cout 
        << "std::cout:" << valor << std::endl
        << "std::to_string:" << std::to_string(valor) << std::endl;
    return 0;
}
```

Salida del programa anterior:

```
std::cout: 1e+40
to_string: 10000000000000000303786028427003666890752.000000
```

## Referencias

- std::to_string - cppreference.com. (n.d.). https://en.cppreference.com/w/cpp/string/basic_string/to_string
