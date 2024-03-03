#include "./paquete-nocturno.h"

PaqueteNocturno::PaqueteNocturno(
    Interlocutor remitente,
    Interlocutor destinatario,
    double peso_en_onzas,
    double precio_por_onza,
    double tarifa_adicional_por_onza
)
    : Paquete(remitente, destinatario, peso_en_onzas, precio_por_onza),
      tarifa_adicional_por_onza(tarifa_adicional_por_onza) {}

double PaqueteNocturno::obtener_costo() const {
    return Paquete::obtener_costo() + (obtener_tarifa_adicional_por_onza() * obtener_peso_en_onzas());
}