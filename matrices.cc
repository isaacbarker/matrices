#include <iostream>
#include <vector>

#include "matrix.hh"

int main() {

  std::vector<std::vector<double> > data = {{1, 2}, {3, 4}};
  Matrix my_first_matrix(data);
  std::vector<int> dimensions = my_first_matrix.get_dimensions();

  std::vector<std::vector<double> > new_data = {{1, 0}, {0, 1}};
  Matrix my_second_matrix(new_data);

  my_second_matrix.apply(my_first_matrix);



}