#include <iostream>
#include <iomanip>

#include "./cuenta.h"
#include "./cuenta-ahorros.h"
#include "./cuenta-cheques.h"

CuentaAhorros crear_cuenta_ahorros();
void probar_cuenta_de_ahorros();
CuentaCheques crear_cuenta_cheques();
void probar_cuenta_de_cheques();


int main() {
    probar_cuenta_de_ahorros();    
    probar_cuenta_de_cheques();

    return 0;
}

CuentaAhorros crear_cuenta_ahorros() {
    std::cout 
        << "Ingrese el monto inicial de su cuenta de ahorros: " 
        << std::endl 
        << "$";
    double ahorros_iniciales;
    std::cin >> ahorros_iniciales;

    std::cout 
        << "Ingrese la tasa de interés de su cuenta de ahorros: " 
        << std::endl 
        << " ";
    double tasa_de_interes;
    std::cin >> tasa_de_interes;

    bool error_de_ahorros = false;
    CuentaAhorros ahorros(ahorros_iniciales, &error_de_ahorros, tasa_de_interes);
    if (error_de_ahorros) {
        std::cout 
            << "El saldo inicial de la cuenta es inválido; fue reemplazado con cero" 
            << std::endl;
    }
    return ahorros;
}

void probar_cuenta_de_ahorros() {
    CuentaAhorros ahorros = crear_cuenta_ahorros();

    std::cout 
        << "Los intereses generados por la cuenta son: "
        << std::endl 
        << "$"
        << std::setprecision(2) << ahorros.calcular_interes()
        << std::endl;
    
    ahorros.abonar(ahorros.calcular_interes());

    std::cout 
        << "Después de recibir los intereses, la cuenta de ahorros ahora tiene: "
        << std::endl
        << "$"
        << std::setprecision(2) << ahorros.calcular_interes() 
        << std::endl;
}

CuentaCheques crear_cuenta_cheques() {
    std::cout 
        << "Ingrese el monto inicial de su cuenta de cheques: " 
        << std::endl 
        << "$";
    double monto_inicial;
    std::cin >> monto_inicial;

    std::cout 
        << "Ingrese la cuota por transacción de su cuenta de cheques: " 
        << std::endl 
        << "$";
    double cuota_por_transaccion;
    std::cin >> cuota_por_transaccion;

    bool error_de_cheques = false;
    CuentaCheques cheques(monto_inicial, &error_de_cheques, cuota_por_transaccion);
    if (error_de_cheques) {
        std::cout 
            << "El saldo inicial de la cuenta es inválido; fue reemplazado con cero" 
            << std::endl;
    }
    return cheques;
}

void probar_cuenta_de_cheques() {
    CuentaCheques cheques = crear_cuenta_cheques();

    while (true) {
        std::cout 
            << "¿Qué operación quiere realizar en la cuenta?"
            << std::endl
            << "[1] -> Abonar, [2] -> Cargar, [Otro] -> Salir"
            << std::endl;
        
        int respuesta;
        std::cin >> respuesta;
        if (respuesta < 1 || respuesta > 2) {
            break;
        }

        double argumento;
        std::cin >> argumento;
        switch (respuesta) {
            case 1:
                cheques.abonar(argumento);
                break;
            case 2:
                bool resultado = cheques.cargar(argumento);
                if (resultado) {
                    std::cout << "No se pudo cargar de la cuenta" << std::endl;
                }
                break;
        }
        std::cout << cheques.get_saldo();
    }
}
