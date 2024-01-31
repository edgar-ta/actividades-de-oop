#include "coordinate.h"
#include "rectangle.h"
#include <iostream>
#include <cstdlib>

int main (int argc, char *argv[]) {
  Rectangle rectangle_2({
    Coordinate(5.0, 10.0),
    Coordinate(5.0, 20.0),
    Coordinate(10.0, 50.0),
    Coordinate(10.0, 50.0)
  });

  rectangle_2.print_values(std::cout);

  return EXIT_SUCCESS;
}


