#if !defined(__INTERLOCUTOR_H__)
#define __INTERLOCUTOR_H__

#include <iostream>
#include <string>

class Interlocutor {
private:
    std::string nombre;
    std::string nombre_ciudad;
    std::string nombre_estado;
    std::string codigo_postal;

public:
    Interlocutor(
        std::string nombre,
        std::string nombre_ciudad,
        std::string nombre_estado,
        std::string codigo_postal
    );

    std::string obtener_nombre() const { return nombre; }
    std::string obtener_nombre_ciudad() const { return nombre_ciudad; }
    std::string obtener_nombre_estado() const { return nombre_estado; }
    std::string obtener_codigo_postal() const { return codigo_postal; }
};

std::ostream& operator<<(std::ostream& cout, const Interlocutor& interlocutor);

#endif // __INTERLOCUTOR_H__

