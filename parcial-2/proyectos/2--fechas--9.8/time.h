#if !defined(__TIME_H__)
#define __TIME_H__

#include <string>

class Time {
private:
  int horas;
  int minutos;
  int segundos;
public:
  Time(int, int, int);

  void set_segundos(int);
  void set_minutos(int);
  void set_horas(int);

  int get_segundos() { return segundos; }
  int get_minutos() { return minutos; }
  int get_horas() { return horas; }

  void incrementar_segundos();

  std::string to_string();
};

#endif // __TIME_H__
