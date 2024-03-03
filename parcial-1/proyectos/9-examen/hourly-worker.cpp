#include "hourly-worker.h"
#include <cmath>

HourlyWorker::HourlyWorker(float wage, float worked_hours): wage(wage), worked_hours(worked_hours) {}
inline float HourlyWorker::get_wage() { return wage; }
inline void HourlyWorker::set_wage(float wage) { this->wage = wage; }
inline float HourlyWorker::get_worked_hours() { return worked_hours; }
inline void HourlyWorker::set_worked_hours(float worked_hours) { this->worked_hours = worked_hours; }

float HourlyWorker::get_weekly_wage() {
  auto basic_hours = fmin(worked_hours, 40);
  auto extra_hours = fmax(worked_hours - 40, 0);
  return basic_hours * wage + extra_hours * wage * 1.5;
}

void HourlyWorker::__construct_from_user_input(std::ostream & cout, std::istream & cin) {
  cout << "Ingrese las horas trabajadas del trabajador y su salario base" << std::endl;
  cout << "Horas trabajadas: ";
  cin >> worked_hours;
  cout << "Salario base: $";
  cin >> wage;
}

HourlyWorker* HourlyWorker::construct_from_user_input(std::ostream & cout, std::istream & cin) {
  cout << "Ingrese las horas trabajadas del trabajador y su salario base" << std::endl;
  float worked_hours, wage;
  cout << "Horas trabajadas: ";
  cin >> worked_hours;
  cout << "Salario base: $";
  cin >> wage;
  HourlyWorker* hourly_worker = new HourlyWorker(wage, worked_hours);
  cout << "El sueldo semanal del trabajador es: $" << hourly_worker->get_weekly_wage() << std::endl;
  return hourly_worker;
}
