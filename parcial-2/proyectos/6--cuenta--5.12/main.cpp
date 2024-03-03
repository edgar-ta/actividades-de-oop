#include <cstdlib>
#include <iostream>

#include "./cuenta.h"

int main() {
    Cuenta origen(100);
    Cuenta destino(-50);

    bool transaccion_exitosa = Cuenta::transferir(origen, destino, 500);
    if (!transaccion_exitosa) {
        Cuenta::transferir(origen, destino, 100);
    }

    std::cout << "El saldo de la cuenta de origen es: $" << origen.obtener_saldo() << std::endl;
    std::cout << "El saldo de la cuenta de destino es: $" << destino.obtener_saldo() << std::endl;

    return EXIT_SUCCESS;
}
