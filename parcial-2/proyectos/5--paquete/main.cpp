#include <iostream>
#include <string>
#include <iomanip>

#include "./interlocutor.h"
#include "./paquete.h"
#include "./paquete-dos-dias.h"
#include "./paquete-nocturno.h"

inline double limitar_minimo(double minimo, double valor);
void enviar_paquete(const PaqueteNocturno& paquete_nocturno);
void enviar_paquete(const PaqueteDosDias& paquete_dos_dias);

int main() {
    PaqueteDosDias paquete_dos_dias(
        Interlocutor( "Edgar Trejo Avila", "San Juan del Río", "Querétaro", "76806" ),
        Interlocutor( "María García", "Ciudad de México", "Ciudad de México", "12345" ),
        10.5, 
        2.5, 
        5.0
    );

    PaqueteNocturno paquete_nocturno(
        Interlocutor( "Juan Pérez", "Puebla", "Puebla", "54321" ),
        Interlocutor( "Ana López", "Guadalajara", "Jalisco", "98765" ),
        8.0, 
        3.0, 
        2.0
    );

    enviar_paquete(paquete_dos_dias);
    enviar_paquete(paquete_nocturno);

    return 0;
}

inline double limitar_minimo(double minimo, double valor) {
    if (valor < minimo) return minimo;
    return valor;
}

void enviar_paquete(const PaqueteNocturno& paquete_nocturno) {
    std::cout 
        << paquete_nocturno.obtener_remitente() 
        << " está enviando un paquete a " 
        << paquete_nocturno.obtener_destinatario()
        << " por la noche..."
        << std::endl
        << "Debido a que es un paquete nocturno, hay una tarifa adicional de $" 
        << std::setprecision(2) << paquete_nocturno.obtener_tarifa_adicional_por_onza()
        << " por onza en comparación con los regulares $"
        << std::setprecision(2) << paquete_nocturno.obtener_precio_por_onza()
        << " requeridos por paquete."
        << " Dado que el paquete pesa " 
        << std::setprecision(2) << paquete_nocturno.obtener_peso_en_onzas() 
        << " onzas, el costo de envío final es: $"
        << std::setprecision(2) << paquete_nocturno.obtener_costo()
        << std::endl
        ;
}

void enviar_paquete(const PaqueteDosDias& paquete_dos_dias) {
    std::cout 
        << paquete_dos_dias.obtener_remitente()
        << " está enviando un paquete a "
        << paquete_dos_dias.obtener_destinatario()
        << " en dos días..."
        << std::endl
        << "El paquete pesa "
        << std::setprecision(2) << paquete_dos_dias.obtener_peso_en_onzas()
        << " onzas, a $" 
        << std::setprecision(2) << paquete_dos_dias.obtener_precio_por_onza()
        << " por onza, pero debido a que es una entrega rápida, hay una tarifa adicional de $"
        << std::setprecision(2) << paquete_dos_dias.obtener_tarifa_dos_dias()
        << " sobre el costo de envío original de $"
        << std::setprecision(2) << paquete_dos_dias.Paquete::obtener_costo()
        << ", por lo tanto, el costo de envío final es: $" 
        << paquete_dos_dias.obtener_costo()
        << std::endl
        ;
}
