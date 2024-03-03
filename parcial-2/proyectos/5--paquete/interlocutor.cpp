#include "./interlocutor.h"

std::ostream& operator<<(std::ostream& cout, const Interlocutor& interlocutor) {
    return cout
        << interlocutor.obtener_nombre()
        << " (quien vive en "
        << interlocutor.obtener_nombre_ciudad()
        << ", "
        << interlocutor.obtener_nombre_estado()
        << ")";
}

Interlocutor::Interlocutor(
    std::string nombre,
    std::string nombre_ciudad,
    std::string nombre_estado,
    std::string codigo_postal
) :
    nombre(nombre),
    nombre_ciudad(nombre_ciudad),
    nombre_estado(nombre_estado),
    codigo_postal(codigo_postal)
{}
