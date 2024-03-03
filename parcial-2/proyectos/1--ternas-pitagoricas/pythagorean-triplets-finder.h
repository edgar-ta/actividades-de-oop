#ifndef PYTHAGOREAN_TRIPLET_FINDER_H
#define PYTHAGOREAN_TRIPLET_FINDER_H

#include <iostream>

class PythagoreanTripletFinder {
public:
  inline static void find_triplets() {
    int counter = 1;
    for (int a = 1; a <= 500; a++) 
    for (int b = 1; b <= 500; b++) 
    for (int c = 1; c <= 500; c++) 
    if (a * a + b * b == c * c) {
      std::cout << counter << ". (" << a << ", " << b << ", " << c << ")" << std::endl;
      counter++;
    }
  };
};

#endif // !PYTHAGOREAN_TRIPLET_FINDER_H
