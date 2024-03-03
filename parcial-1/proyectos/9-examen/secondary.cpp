#include <iostream>

class Empleado {
    public:
    virtual float get_sueldo_semanal() = 0;
};

class Gerente : public Empleado {
    private:
    float sueldo_semanal;

    public:
    Gerente(float sueldo_semanal): 
        sueldo_semanal(sueldo_semanal)
    {};

    float get_sueldo_semanal() override 
        { return sueldo_semanal; };
};

class EmpleadoPorComision : public Empleado {
    private:
    float ventas_realizadas;

    public:
    EmpleadoPorComision(float ventas_realizadas):
        ventas_realizadas(ventas_realizadas)
    {};

    float get_sueldo_semanal() override {
        return ventas_realizadas * 20 / 100;
    };
};

class MiClase {
    private:
    int valor;

    public:
    int get_valor() { return valor; }
    void set_valor(int otro_valor) 
    { this->valor = otro_valor; }
};

int main() {
    MiClase mi_clase;
    mi_clase.set_valor(5);
    mi_clase.get_valor();

    while (true) {
        std::cout << "Ingrese el tipo de empleado" << std::endl;
        int tipo_de_empleado;
        std::cin >> tipo_de_empleado;

        switch(tipo_de_empleado) {
            case 1:
            std::cout << "Ingrese el sueldo semanal del gerente: $" << std::endl;
            float sueldo_semanal;
            std::cin >> sueldo_semanal;
            Gerente gerente(sueldo_semanal);
            std::cout << "El sueldo semanal del gerente es: $" << gerente.get_sueldo_semanal() << std::endl;
            break;

            case 2:
            std::cout << "Ingrese las ventas realizadas: $" << std::endl;
            float ventas_realizadas;
            std::cin >> ventas_realizadas;
            EmpleadoPorComision empleado_por_comision(ventas_realizadas);
            std::cout << "El sueldo semanal es: $" << empleado_por_comision.get_sueldo_semanal() << std::endl;
            break;

            case 3:
            break;
            case 4:
            break;
        }
    }
    return 0;
}
