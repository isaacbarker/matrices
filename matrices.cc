#include <iostream>
#include <vector>

#include "matrix.hh"

int main() {

  // Examples
  Matrix matrix_1({{2, 0}, {3, 4}});
  Matrix matrix_2({{1, 0}, {0, 1}});

  // Multiplication
  matrix_1.apply(matrix_2);
  matrix_1.apply(3);

  // Addition
  matrix_2.add(matrix_1);
  
  // Subtraction
  matrix_2.subtract(matrix_1);

}