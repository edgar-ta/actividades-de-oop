#include <iostream>
#include "./time.h"

int main() {
  Time time(22, 58, 59);
  time.incrementar_segundos();

  std::cout << time.to_string();

  return 0;
}
