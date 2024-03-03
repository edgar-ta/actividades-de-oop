#include "./cuenta.h"

#include <iostream>

Cuenta::Cuenta(int saldo_inicial, bool* es_saldo_invalido) {
    bool resultado = set_saldo(saldo_inicial);
    if (es_saldo_invalido != nullptr) {
        *es_saldo_invalido = resultado;
    }
}

Cuenta::Cuenta(int saldo_inicial): Cuenta(saldo_inicial, nullptr) {}

bool Cuenta::set_saldo(int saldo) {
    if (saldo >= 0) {
        this->saldo = saldo;
        return true;
    } else {
        this->saldo = 0;
        std::cout 
            << "El saldo inicial pasado al constructor era inválido" 
            << std::endl;
        return false;
    }
}

void Cuenta::credit(int credito) {
    this->saldo += credito;
}

bool Cuenta::cargar(int cantidad) {
    if (cantidad > this->saldo) {
        std::cout 
            << "El monto a cargar excede el saldo de la cuenta (se intentaron cargar $" 
            << cantidad << " cuando solo se tenían $" << saldo << ")" << std::endl;
        return false;
    } else {
        this->saldo -= cantidad;
        return true;
    }
}

inline int Cuenta::obtener_saldo() const { return this->saldo; }

bool Cuenta::transferir(Cuenta& origen, Cuenta& destino, int cantidad) {
    bool cargo_exitoso = origen.cargar(cantidad);
    if (cargo_exitoso) {
        destino.credit(cantidad);
        std::cout 
            << "Se han transferido exitosamente $" 
            << cantidad << " a la cuenta del destino" 
            << std::endl;
    }
    return cargo_exitoso;
}