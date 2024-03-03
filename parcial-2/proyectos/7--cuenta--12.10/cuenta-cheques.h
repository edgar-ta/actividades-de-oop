#if !defined(__CUENTA_CHEQUES_H__)
#define __CUENTA_CHEQUES_H__

#include "./cuenta.h"

class CuentaCheques : public Cuenta {
    double cuota_por_transaccion;

    public:

    CuentaCheques(
        double saldo_inicial = 0.0, 
        bool* es_error = nullptr, 
        double cuota_por_transaccion
    );

    // retirar
    bool cargar(double cantidad);
    // añadir
    void abonar(double cantidad);
};

#endif // __CUENTA_CHEQUES_H__
