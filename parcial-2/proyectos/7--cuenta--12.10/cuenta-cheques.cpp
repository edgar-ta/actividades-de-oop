#include "./cuenta-cheques.h"

CuentaCheques::CuentaCheques(
    double saldo_inicial, 
    bool* es_error, 
    double cuota_por_transaccion
): 
Cuenta(
    saldo_inicial, 
    es_error
), cuota_por_transaccion(cuota_por_transaccion) {}

bool CuentaCheques::cargar(double cantidad) {
    return Cuenta::cargar(cantidad + cuota_por_transaccion);
}

void CuentaCheques::abonar(double cantidad) {
    Cuenta::abonar(cantidad);
    if (!Cuenta::cargar(cuota_por_transaccion)) {
        Cuenta::cargar(cantidad);
    }
}
