#include <cstdlib>
#include <iostream>

#include "employee.h"
#include "manager.h"
#include "hourly-worker.h"
#include "comision-worker.h"
#include "parts-worker.h"

void print_introductory_message() {
  std::cout << "Ingrese los datos solicitados para obtener el sueldo semanal de los trabajadores que desee" << std::endl;
}

void print_employee_type_options() {
  std::cout << "El tipo de empleado (un valor numérico) está dado de la siguiente forma: " << std::endl;
  std::cout << "1. Gerente" << std::endl;
  std::cout << "2. Trabajador por horas" << std::endl;
  std::cout << "3. Trabajador por comisión" << std::endl;
  std::cout << "4. Trabajador por partes" << std::endl;
}

int main() {
  int number_of_processed_employees = 0;
  float accumulated_wages = 0.0;

  print_introductory_message();
  while (true) {
    std::cout << "Ingrese el tipo de empleado del que desee calcular el sueldo" << std::endl;
    print_employee_type_options();
    std::cout << std::endl;
    std::cout << "Tipo de empleado: ";

    int employee_type;
    std::cin >> employee_type;
    if (employee_type > 4 || employee_type < 1) {
      std::cout << "El tipo de empleado ingresado es inválido" << std::endl;
      continue;
    }

    Employee* employee = nullptr;
    switch (employee_type) {
      case 1: employee = Manager::construct_from_user_input(std::cout, std::cin); break;
      case 2: employee = HourlyWorker::construct_from_user_input(std::cout, std::cin); break;
      case 3: employee = ComisionWorker::construct_from_user_input(std::cout, std::cin); break;
      case 4: employee = PartsWorker::construct_from_user_input(std::cout, std::cin); break;
    }

    accumulated_wages += employee->get_weekly_wage();
    number_of_processed_employees++;

    std::cout << "¿Desea continuar registrando empleados? (Ingrese 'y' para confirmar)" << std::endl;
    std::cout << "¿Continuar?: ";
    char __continue;
    std::cin >> __continue;
    if (__continue != 'y') break;

    std::cout << "Guardando los valores ingresados...";
    std::cout << std::endl;
    std::cout << "Número de empleados procesados hasta ahora: " << number_of_processed_employees << std::endl;
    std::cout << "Suma de sueldos hasta ahora: " << accumulated_wages << std::endl;
  }

  std::cout << "Número de empleados procesados hasta ahora: " << number_of_processed_employees << std::endl;
  std::cout << "Suma de sueldos hasta ahora: " << accumulated_wages << std::endl;

  std::cout << "Terminando el programa" << std::endl;

  return EXIT_SUCCESS;
}

