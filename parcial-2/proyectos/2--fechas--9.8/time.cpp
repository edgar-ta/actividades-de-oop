#include "./time.h"

#include <tuple>

std::tuple<int, int> divmod(int m, int n) {
  int modulo = m % n;
  int cleanM = m - modulo;
  int division = cleanM / n;
  return std::make_tuple(division, modulo);
}

Time::Time(int horas, int minutos, int segundos): 
  horas(horas), 
  minutos(minutos), 
  segundos(segundos) {}

void Time::set_segundos(int segundos) {
  auto valores = divmod(segundos, 60);

  auto minutos_adicionales = std::get<0>(valores);
  auto segundos_finales = std::get<1>(valores);

  this->segundos = segundos_finales;
  set_minutos(get_minutos() + minutos_adicionales);
}

void Time::set_minutos(int minutos) {
  auto valores = divmod(minutos, 60);

  auto horas_adicionales = std::get<0>(valores);
  auto minutos_finales = std::get<1>(valores);

  this->minutos = minutos_finales;
  set_horas(get_horas() + horas_adicionales);
}

void Time::set_horas(int horas) {
  this->horas = horas % 24;
}

void Time::incrementar_segundos() {
  set_segundos(get_segundos() + 1);
}

std::string zero_pad_with_two_digits(int value) {
  if (value < 10) return "0" + std::to_string(value);
  return std::to_string(value);
}

std::string Time::to_string() {
  return zero_pad_with_two_digits(horas) 
    + ":" + zero_pad_with_two_digits(minutos) 
    + ":" + zero_pad_with_two_digits(segundos);
}
