#include <sparce-matrix/sparce_matrix.hpp>

#include <iostream>
#include <vector>

int main() {
  std::cout << "Hello, World!" << std::endl;

  // Example usage of sparce_matrix
  SparseMatrix2D<int, 0> matrix;
  matrix.set(0, 0, 10);
  matrix.set(2, 3, 20);
  matrix.set(4, 4, 30);
  
  std::cout << "Matrix element at (0, 0): " << matrix.get(0, 0) << std::endl;
  std::cout << "Matrix element at (2, 3): " << matrix.get(2, 3) << std::endl;
  std::cout << "Matrix element at (4, 4): " << matrix.get(4, 4) << std::endl;

  matrix[0][0] = 15; // Using ElementProxy to set a value
  std::cout << "Updated matrix element at (0, 0): " << matrix[0][0] << std::endl;
  return 0;
}