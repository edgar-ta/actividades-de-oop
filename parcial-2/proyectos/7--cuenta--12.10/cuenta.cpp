#include "./cuenta.h"

bool Cuenta::set_saldo(double saldo) {
    if (saldo < 0) {
        this->saldo = 0;
        return false;
    }
    return true;
}

Cuenta::Cuenta(double saldo_inicial, bool* es_error) {
    if (es_error != nullptr) {
        *es_error = set_saldo(saldo_inicial);
    }
}

bool Cuenta::cargar(double cantidad) {
    return set_saldo(saldo - cantidad);
}

void Cuenta::abonar(double cantidad) {
    set_saldo(saldo + cantidad);
}
