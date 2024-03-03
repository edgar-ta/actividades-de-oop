#if !defined(__CUENTA_AHORROS_H__)
#define __CUENTA_AHORROS_H__

#include "./cuenta.h"

class CuentaAhorros : public Cuenta {
    double tasa_de_interes;

    public:
    CuentaAhorros(
        double saldo_inicial = 0.0, 
        bool* es_error = nullptr, 
        double tasa_de_interes = 0.0
    );

    double calcular_interes();
};

#endif // __CUENTA_AHORROS_H__
