#include <iostream>
#include <vector>

#include <sparce-matrix/sparce_matrix.hpp>

int main() {
  // Example usage of sparce_matrix
  SparseMatrix2D<int, 0> matrix;
  // matrix.set(0, 0, 10);
  // matrix.set(2, 3, 20);
  // matrix.set(4, 4, 30);

  // std::cout << "Matrix element at (0, 0): " << matrix.get(0, 0) << std::endl;
  // std::cout << "Matrix element at (2, 3): " << matrix.get(2, 3) << std::endl;
  // std::cout << "Matrix element at (4, 4): " << matrix.get(4, 4) << std::endl;

  // matrix[0][0] = 15;
  // std::cout << "Updated matrix element at (0, 0): " << matrix[0][0] << std::endl;

  // matrix[5][2] = 55;
  // std::cout << "Matrix element at [5], [2]: " << matrix[5][2] << std::endl;
  // std::cout << "Matrix element at (5, 2): " << matrix.get(5, 2) << std::endl;

  // std::cout << "Matrix size: " << matrix.size() << std::endl;

  for (int i = 0, j = 0; i < 10; ++i, ++j) {
    matrix[i][j] = i;
  }
  for (int i = 0, j = 9; i < 10; ++i, --j) {
    matrix[i][j] = j;
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }


  std::cout << "Matrix size: " << matrix.size() << std::endl;
  return 0;
}