# Constructores por defecto

Un constructor por defecto es un tipo de constructor que no requiere argumentos para ser llamado; se conoce como "por defecto" pues es el que se utiliza para crear objetos cuando ningún otro constructor de la clase a la que pertenecen puede ser llamado (es decir, es la última alternativa para construir el objeto, como si se tratase de la última opción en una estructura `switch`).

Los constructores por defecto pueden ser **declarados explícitamente**, es decir, de la misma forma que cualquier otro constructor de una clase (basta con dejar vacía la lista de parámetros en la declaración); sin embargo, también pueden ser **declarados implícitamente** (es decir, añadidos a la definición de la clase de manera automática) por el compilador cuando la clase en cuestión cumple con una serie de criterios, los cuales, de manera simplificada, especifican que la clase no debe tener otros constructores definidos anteriormente. Véase el siguiente ejemplo:

```cpp
class PrimeraClase {
    int primerValor;

    public:
    PrimeraClase();
};

class SegundaClase {
    int segundoValor;

    public:
    // SegundaClase();
};

class TerceraClase {
    int tercerValor;

    public:
    TerceraClase(int tercerValor);
};
```

La clase `PrimeraClase` declara explícitamente un constructor que no toma argumentos (es decir, un constructor por defecto), el cual es sencillamente un constructor más.

La clase `SegundaClase`, a pesar de no haber declarado ningún constructor, implícitamente recibe uno que le da el compilador; este constructor no tiene ningún parámetro.

La clase `TerceraClase` declara un constructor que toma un argumento, y es gracias a este constructor que el compilador no le asigna un constructor por defecto de manera implícita.

## Definición de un constructor

Ahora bien, cuando la clase en cuestión cumple con los criterios para recibir implícitamente un constructor por defecto, el compilador añade no solo la **declaración**, sino también la **definición** de dicho constructor, de modo que el ejemplo de `SegundaClase` en la parte de arriba está más completo si se presenta de la siguiente forma...

```cpp
class SegundaClase {
    int segundoValor;

    public:
    // SegundaClase(); // declaración del constructor
};

// SegundaClase::SegundaClase() { // definición del constructor
//  ...
// }
```

...Donde las líneas comentadas representan código añadido automáticamente por el compilador.

Cuando viene como parte de una **declaración implícita** de un constructor por defecto, a esta definición se le conoce como **definición automática implícita**, dado que el código añadido es, por supuesto, automático y lo da el compilador implícitamente. 

Existe también la **definición automática explícita**, que puede ser usada para que un constructor declarado explícitamente (como en la clase `PrimeraClase`) sea definido por el compilador automáticamente.

Existe también la **definición del usuario** que, en contraste con la **definición automática**, es dada por el programador para satisfacer su caso de uso particular.

El siguiente fragmento ilustra los diferentes tipos de definición de un constructor:

```cpp
class PrimeraClase {
    int primerValor;

    public:
    PrimeraClase() = default;
};

// PrimeraClase::PrimeraClase() {
//  ...
// }



class SegundaClase {
    int segundoValor;

    public:
    // SegundaClase();
};

// SegundaClase::SegundaClase() {
//  ...
// }



class TerceraClase {
    int tercerValor;

    public:
    TerceraClase(int tercerValor);
};

TerceraClase::TerceraClase(int tercerValor):
    tercerValor(tercerValor)
{}

```

En el fragmento anterior, la clase `PrimeraClase` utiliza la sintaxis `Constructor() = default` para hacer que el constructor que declaró sea implementado en automático por el compilador.

La clase `SegundaClase`, a pesar de no utilizar la misma sintaxis que `PrimeraClase`, también recibe una definición de constructor en automático.

Finalmente, la clase `TerceraClase` implementa su constructor manualmente; es decir, de forma explícita, como se hace comúnmente con los archivos de código fuente de C++.
