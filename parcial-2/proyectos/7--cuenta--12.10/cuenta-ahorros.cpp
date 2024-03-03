#include "./cuenta-ahorros.h"

CuentaAhorros::CuentaAhorros(
    double saldo_inicial, 
    bool* es_error, 
    double tasa_de_interes
): 
    Cuenta(saldo_inicial, es_error), 
    tasa_de_interes(tasa_de_interes) {}

double CuentaAhorros::calcular_interes() {
    return tasa_de_interes * get_saldo();
}
