Un objeto es un tipo de datos nuevo, que viene derivado de una [[Clase|clase]] y consta de [[Atributo|atributos]] (i. e., propiedades) y [[Método|métodos]] (i. e., acciones que puede realizar).

Una vez creado un objeto, puedes acceder con un punto a sus atributos, ya sea para consultarlos, modificarlos, o para usar sus métodos.

Ejemplo:

```cpp
#include <cstdlib>

class Taza {
public:
	int cantidad;
	Taza(int cantidad): cantidad(cantidad);
};

int main() {
	Taza miTaza(5);
	return EXIT_SUCCESS;
}
```

El [[Snippet|snippet]] anterior [[Instanciar|instancia]] una variable del tipo `Taza` usando su [[Constructor|constructor]] que toma un entero; para acceder al [[Atributo|atributo]] `cantidad` de `miTaza`, uno sigue la siguiente sintaxis:

```cpp
miTaza.cantidad;
```

El siguiente [[Snippet|snippet]] hace uso de dicha sintaxis para imprimir el valor de `cantidad` en la pantalla:

```cpp
#include <cstdlib>
#include <iostream>

class Taza {
public:
	int cantidad;
	Taza(int cantidad): cantidad(cantidad);
};

int main() {
	Taza miTaza(5);
	std::cout << "La cantidad de mi taza es: " << miTaza.cantidad << std::endl;
	return EXIT_SUCCESS;
}
```
