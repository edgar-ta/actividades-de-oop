#if !defined(__PAQUETE_H__)
#define __PAQUETE_H__

#include "./interlocutor.h"

class Paquete {
private:
    Interlocutor remitente;
    Interlocutor destinatario;
    double peso_en_onzas;
    double precio_por_onza;

public:
    Paquete(Interlocutor, Interlocutor, double, double);

    double obtener_costo() const;
    inline double obtener_peso_en_onzas() const { return peso_en_onzas; };
    inline double obtener_precio_por_onza() const { return precio_por_onza; };
    inline const Interlocutor& obtener_remitente() const { return remitente; };
    inline const Interlocutor& obtener_destinatario() const { return destinatario; };
};

#endif // __PAQUETE_H__
