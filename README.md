# Matrices

Matrix operations using C++. My first project in C++ is a matrix class which implements basic operations. In future I would like to add optimisation to decrease the speed of multiplication in particular which uses 3 for loops traversing over the matrices. 

## Currently implemented:

  - .apply() Applies another matrix or constant to a Matrix object. 
  - .get_dimensions() Returns a `std::vector` with [x, y] 
  - .get_dimension_x() Returns x dimension
  - .get_dimension_y() Returns y dimension
  - .get_data() Returns a 2d array of `std::vector<double>` with the data stored in the matrix.
