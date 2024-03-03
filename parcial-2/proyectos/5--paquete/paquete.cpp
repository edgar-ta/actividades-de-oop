#include "./paquete.h"

Paquete::Paquete(
    Interlocutor remitente,
    Interlocutor destinatario,
    double peso_en_onzas,
    double precio_por_onza
)
    : remitente(remitente),
      destinatario(destinatario),
      peso_en_onzas(peso_en_onzas),
      precio_por_onza(precio_por_onza) {}

double Paquete::obtener_costo() const {
    return peso_en_onzas * precio_por_onza;
}
