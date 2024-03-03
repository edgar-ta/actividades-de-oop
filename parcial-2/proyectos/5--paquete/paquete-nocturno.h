#if !defined(__PAQUETE_NOCTURNO_H__)
#define __PAQUETE_NOCTURNO_H__

#include "./interlocutor.h"
#include "./paquete.h"

class PaqueteNocturno : public Paquete {
private:
    double tarifa_adicional_por_onza;

public:
    PaqueteNocturno(Interlocutor, Interlocutor, double, double, double);

    double obtener_costo() const;
    inline double obtener_tarifa_adicional_por_onza() const { return tarifa_adicional_por_onza; };
};


#endif // __PAQUETE_NOCTURNO_H__
