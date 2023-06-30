#include <iostream>
#include <vector>
#include <cassert>

#include "matrix.hh"

// Matrix functions

Matrix::Matrix(std::vector<std::vector<double> > new_data) {
  // Obtain dimensions
  dimension_y = new_data.size();
  
  // Validate the data to ensure it is full
  int row_length;
  for (int i = 0; i < dimension_y; i++) {
    std::vector<double> row = new_data[i];

    if (i == 0) {
      row_length = row.size();
    } 

    assert(row_length == row.size());
  }

  dimension_x = row_length;

  // Assign data
  data = new_data;
}

// Getters

std::vector<int> Matrix::get_dimensions() {
  // Returns vector with [x, y]
  std::vector<int> dimensions = {dimension_x, dimension_y};
  return dimensions;
}

int Matrix::get_dimension_x() {
  return dimension_x;
}

int Matrix::get_dimension_y() {
  return dimension_y;
}

std::vector<std::vector<double> > Matrix::get_data() {
  return data;
}

// Operations

void Matrix::apply(Matrix matrix) {

  int m_dimension_x = matrix.get_dimension_x();
  int m_dimension_y = matrix.get_dimension_y();
  std::vector<std::vector<double> > m_data = matrix.get_data();

  // Check dimensions are correct
  assert(m_dimension_x == dimension_y);

  // Apply m to this
  std::vector<std::vector<double> > result_matrix_data(
    m_dimension_y,
    std::vector<double>(dimension_x)
  );

  for (int i = 0; i < m_dimension_y; i++) {

    // Load row from m
    std::vector<double> row = m_data[i];

    // For each column from this
    for (int j = 0; j < dimension_x; j++) {

      // Multiply
      double result = 0;

      for (int k = 0; k < m_dimension_x; k++) {
        result += (row[k] * data[k][j]);
      }

      // Insert into result
      result_matrix_data[i][j] = result;

    }
  }

  // Update current matrix
  data = result_matrix_data;
  dimension_y = m_dimension_y;

}

void Matrix::apply(double constant) {

  // Iterate over each value and multiply by constant
  for (int i = 0; i < dimension_y; i++) {
    for (int j = 0; j < dimension_x; j++) {
      data[i][j] *= constant;
    }
  }

}

void Matrix::add(Matrix matrix) {

  // Ensure dimensions are equal
  assert(get_dimensions() == matrix.get_dimensions());

  // Add corresponding values to this
  std::vector<std::vector<double> > m_data = matrix.get_data();

  for (int i = 0; i < dimension_y; i++) {
    for (int j = 0; j < dimension_x; j++) {
      data[i][j] += m_data[i][j];
    }
  }

}

void Matrix::subtract(Matrix matrix) {

  // Ensure dimensions are equal
  assert(get_dimensions() == matrix.get_dimensions());

  // Add corresponding values to this
  std::vector<std::vector<double> > m_data = matrix.get_data();

  for (int i = 0; i < dimension_y; i++) {
    for (int j = 0; j < dimension_x; j++) {
      data[i][j] -= m_data[i][j];
    }
  }

}

// Misc.

void Matrix::print() {

  for (int i = 0; i < dimension_y; i++) {
    for (int j = 0; j < dimension_x; j++) {
      std::cout << data[i][j] << " ";
    } 
    std::cout << "\n";
  }

}
