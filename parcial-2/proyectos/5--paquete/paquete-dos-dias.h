#if !defined(__PAQUETE_DOS_DIAS_H__)
#define __PAQUETE_DOS_DIAS_H__

#include "./interlocutor.h"
#include "./paquete.h"

class PaqueteDosDias : public Paquete {
private:
    double tarifa_dos_dias;

public:
    PaqueteDosDias(Interlocutor, Interlocutor, double, double, double);

    double obtener_costo() const;
    inline double obtener_tarifa_dos_dias() const { return tarifa_dos_dias; };
};

#endif // __PAQUETE_DOS_DIAS_H__
