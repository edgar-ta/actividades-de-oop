#include "./paquete-dos-dias.h"

PaqueteDosDias::PaqueteDosDias(
    Interlocutor remitente,
    Interlocutor destinatario,
    double peso_en_onzas,
    double precio_por_onza,
    double tarifa_dos_dias
)
    : Paquete(remitente, destinatario, peso_en_onzas, precio_por_onza),
      tarifa_dos_dias(tarifa_dos_dias) {}

double PaqueteDosDias::obtener_costo() const {
    return Paquete::obtener_costo() + tarifa_dos_dias;
}
