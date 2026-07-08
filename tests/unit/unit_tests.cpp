#include <sparce-matrix/sparce_matrix.hpp>

#include <gtest/gtest.h>

TEST(SparseMatrix2D, DefaultGetReturnsDefaultValue) {
  SparseMatrix2D<int, 0> matrix;

  EXPECT_EQ(matrix.get(0, 0), 0);
  EXPECT_EQ(matrix.get(100, -100), 0);
}

TEST(SparseMatrix2D, SetAndGetReturnsStoredValue) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(2, 3, 42);

  EXPECT_EQ(matrix.get(2, 3), 42);
  EXPECT_EQ(matrix.get(0, 0), 0);
}

TEST(SparseMatrix2D, SetOverwritesExistingValue) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(1, 1, 10);
  matrix.set(1, 1, 20);

  EXPECT_EQ(matrix.get(1, 1), 20);
}

TEST(SparseMatrix2D, OperatorBracketsGetAndSet) {
  SparseMatrix2D<int, 0> matrix;

  matrix[5][2] = 55;

  EXPECT_EQ(matrix[5][2], 55);
  EXPECT_EQ(matrix.get(5, 2), 55);
}

TEST(SparseMatrix2D, OperatorBracketsOnConstMatrix) {
  SparseMatrix2D<int, 0> matrix;
  matrix.set(3, 4, 7);

  const SparseMatrix2D<int, 0>& const_matrix = matrix;

  EXPECT_EQ(const_matrix[3][4], 7);
  EXPECT_EQ(const_matrix[0][0], 0);
}

TEST(SparseMatrix2D, SizeIsZeroForEmptyMatrix) {
  SparseMatrix2D<int, 0> matrix;

  EXPECT_EQ(matrix.size(), 0u);
}

TEST(SparseMatrix2D, SizeIncreasesOnNewNonDefaultValue) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(0, 0, 10);
  EXPECT_EQ(matrix.size(), 1u);

  matrix.set(1, 1, 20);
  EXPECT_EQ(matrix.size(), 2u);
}

TEST(SparseMatrix2D, SizeDoesNotChangeWhenOverwritingExistingValue) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(0, 0, 10);
  matrix.set(0, 0, 20);

  EXPECT_EQ(matrix.size(), 1u);
}

TEST(SparseMatrix2D, SettingDefaultValueDoesNotIncreaseSize) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(0, 0, 0);

  EXPECT_EQ(matrix.size(), 0u);
}

TEST(SparseMatrix2D, SettingExistingValueToDefaultDecreasesSize) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(0, 0, 10);
  matrix.set(1, 1, 20);
  matrix.set(0, 0, 0);

  EXPECT_EQ(matrix.size(), 1u);
  EXPECT_EQ(matrix.get(0, 0), 0);
  EXPECT_EQ(matrix.get(1, 1), 20);
}

TEST(SparseMatrix2D, SettingDefaultValueOnUnsetCellKeepsSizeZero) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(0, 0, 0);
  matrix.set(1, 1, 0);

  EXPECT_EQ(matrix.size(), 0u);
}

TEST(SparseMatrix2D, MultipleCellsAreIndependent) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(0, 0, 1);
  matrix.set(0, 1, 2);
  matrix.set(1, 0, 3);

  EXPECT_EQ(matrix.get(0, 0), 1);
  EXPECT_EQ(matrix.get(0, 1), 2);
  EXPECT_EQ(matrix.get(1, 0), 3);
  EXPECT_EQ(matrix.size(), 3u);
}

TEST(SparseMatrix2D, NegativeCoordinatesWork) {
  SparseMatrix2D<int, 0> matrix;

  matrix.set(-5, -10, 99);

  EXPECT_EQ(matrix.get(-5, -10), 99);
  EXPECT_EQ(matrix.size(), 1u);
}
