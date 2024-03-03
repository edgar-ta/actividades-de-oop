#if !defined(__CUENTA_H__)
#define __CUENTA_H__

class Cuenta {
    double saldo = 0;

    public:

    Cuenta(double saldo_inicial = 0.0, bool* es_error = nullptr);
    // retirar de la cuenta
    bool cargar(double cantidad);

    // añadir a la cuenta
    void abonar(double cantidad);
    double get_saldo() { return saldo; };

    // cambiar el saldo y retornar un
    // valor de estatus
    bool set_saldo(double saldo);
};

#endif // __CUENTA_H__
