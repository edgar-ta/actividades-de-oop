#if !defined(__CUENTA_H__)
#define __CUENTA_H__

class Cuenta {
protected:
    int saldo;
public:
    Cuenta(int);
    Cuenta(int, bool*);

    bool set_saldo(int);
    inline int obtener_saldo() const;

    void credit(int);
    bool cargar(int);

    static bool transferir(Cuenta& origen, Cuenta& destino, int cantidad);
};

#endif // __CUENTA_H__
