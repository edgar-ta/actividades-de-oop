# Repaso de la clase anterior

Un constructor sirve para establecer el estado inicial del objeto

Un destructor sirve para liberar los recursos que tenía alojados el objeto (por ejemplo, la memoria)

# Sobre la clase de hoy

Existen diferentes maneras de declarar una variable, la más común/conveniente de ellas siendo el utilizar paréntesis después del tipo de dato y nombre de la variable; en esta clase, el propósito es estudiar formas alternativas y sus efectos.

```cpp
int main() {
	int n = 0;
	Arreglo objeto(n);
	return 0;
};
```

## Sobre punteros

Una de las formas de declaración de variables alternativas involucra el uso de punteros; sin embargo, antes de poder usar esta sintaxis es necesario entender cuál es su propósito y cómo funciona bajo la superficie

### Sobre pilas y montones

Para que un programa pueda funcionar/correr en una computadora, ésta debe cargarlo en su memoria y después ejecutarlo. La memoria, sin embargo, es un recurso desordenado que puede volverse aún más complicada de manejar cuando se cargan incluso los programas más sencillos. Para poder utilizar la memoria de una computadora, ésta se divide en secciones dedicadas a procesos específicos. De entre estas divisiones, las más utilizadas en programación en C++ son el *heap* y el *stack*.

El *heap* (traducido en español como "montón") es una sección de memoria que almacena valores dinámicos --es decir, a control del programador--, mientras que el *stack* es una sección que almacena valores estáticos. La existencia de (o en su defecto, la falta de) dinamismo en el valor almacenado tiene implicaciones importantes en la forma en que se trata una variable en C++, para empezar, [[#Sintaxis para declarar usando el *heap*|la sintaxis]], y para seguir, el hecho de que las variables dinámicas [[#Sintaxis adicional para usar el *heap*|deben ser eliminadas explícitamente por el programador]] (una fuente clásica de errores de ejecución), mientras que las variables estáticas son eliminadas automáticamente por el programa.

### Sintaxis para declarar usando el *heap*

```cpp
int main() {
	int n = 0;
	Arreglo* objeto = new Arreglo(n);
	delete objeto;
	return 0;
};
```

La sintaxis para declarar variables usando el *heap* se diferencia de la sintaxis del *stack* en que se añade un asterisco después del tipo de dato (`Arreglo*` en vez de `Arreglo`, declarando así un [[Puntero|puntero]]) y que el constructor se llama usando el nombre de la clase y la palabra `new` (`new Arreglo(n)` en vez de `objeto(n)`).

### Sintaxis adicional para usar el *heap*

Otra de las idiosincrasias que vienen con usar el *heap* para almacenar variables es que, para poder acceder propiedades del objeto como tal, se debe usar el operador de la flecha (`->`) en vez del punto:

```cpp
#include <iostream>

int main() {
	int n = 0;
	Arreglo* objeto = new Arreglo(n);
	
	int valor = objeto->valor;   // si `objeto` no fuera un puntero,
							    // se utilizaría `objeto.valor`
	std::cout << "El valor es: " << valor << std::endl;
	
	delete objeto;
	return 0;
};
```

Además, dado que el *heap* almacena variables dinámicas en vez de automáticas, el programador debe liberar la memoria de la variable usando el operador `delete`:

```cpp
int main() {
	int n = 0;
	Arreglo* objeto = new Arreglo(n);
	delete objeto;  // si `objeto` no fuera un puntero,
					// esta línea sería innecesaria
	return 0;
};
```


