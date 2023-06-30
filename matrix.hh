#include <vector>

// Define Matrix Class in which data is represented as a 2d array.
class Matrix {

  int dimension_x;
  int dimension_y;
  std::vector<std::vector<double> > data;

public:

  Matrix(std::vector<std::vector<double> > new_data);

  // Getters
  std::vector<int> get_dimensions();
  int get_dimension_x();
  int get_dimension_y();
  std::vector<std::vector<double> > get_data();

  // Operations
  void apply(Matrix matrix);
  void apply(double constant);
  void add(Matrix matrix);
  void subtract(Matrix matrix);

};