#include "comision-worker.h"
#include <cmath>

ComisionWorker::ComisionWorker(float weekly_sales): weekly_sales(weekly_sales) {}
void ComisionWorker::set_weekly_sales(float weekly_sales) { this->weekly_sales = weekly_sales; }
float ComisionWorker::get_weekly_sales() { return weekly_sales; }

float ComisionWorker::get_weekly_wage() {
  return 250.0 + 5.7 / 100 * weekly_sales;
}

ComisionWorker* ComisionWorker::construct_from_user_input(std::ostream &cout, std::istream &cin) {

  Cuadrado c(5);
  c.perimetro = 20;

  cambiar_lado(c, 10);
  // c.perimetro = 40;

  std::cout << "Ingrese las ventas semanales del trabajador" << std::endl;
  float weekly_sales;
  std::cout << "Ventas mensuales: $";
  std::cin >> weekly_sales;
  ComisionWorker* comision_worker = new ComisionWorker(weekly_sales);
  std::cout << "El sueldo semanal del trabajador es: $" << comision_worker->get_weekly_wage() << std::endl;
  return comision_worker;
}
