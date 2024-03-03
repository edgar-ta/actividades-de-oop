#include "manager.h"
#include <cmath>

Manager::Manager(float wage): wage(wage) {}
inline float Manager::get_wage() { return wage; }
inline void Manager::set_wage(float wage) { this->wage = wage; }
float Manager::get_weekly_wage() { return wage; }

Manager* Manager::construct_from_user_input(std::ostream& cout, std::istream& cin) {
  cout << "Ingrese el sueldo semanal del gerente" << std::endl;
  cout << "Sueldo semanal: $";
  float wage;
  cin >> wage;
  Manager* manager = new Manager(wage);
  return manager;
}
