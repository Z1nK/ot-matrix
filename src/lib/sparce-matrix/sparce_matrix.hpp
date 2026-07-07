#pragma once

#include "pair_hash.hpp"

#include <iostream>
#include <unordered_map>
#include <utility>

template <typename T, T DefaultValue>
class SparseMatrix2D {
public:
  SparseMatrix2D() = default;

  void set(int32_t x, int32_t y, T value) {
    if (value == DefaultValue) {
      size_ -= data_.erase({x, y});
    } else {
      auto [it, inserted] = data_.insert_or_assign({x, y}, value);
      if (inserted) {
        ++size_;
      }
    }
  }

  std::size_t size() const { return size_; }

  T get(int32_t x, int32_t y) const {
    auto it = data_.find({x, y});
    if (it != data_.end()) {
      return it->second;
    }
    return DefaultValue;
  }

  class ElementProxy {
  public:
    ElementProxy(SparseMatrix2D& matrix, int32_t x, int32_t y) : matrix_(matrix), x_(x), y_(y) {}

    operator T() const { return matrix_.get(x_, y_); }

    ElementProxy& operator=(T value) {
      matrix_.set(x_, y_, value);
      return *this;
    }

  private:
    SparseMatrix2D& matrix_;
    int32_t x_;
    int32_t y_;
  };

  class RowProxy {
  public:
    RowProxy(SparseMatrix2D& matrix, int32_t x) : matrix_(matrix), x_(x) {}

    ElementProxy operator[](int32_t y) { return ElementProxy(matrix_, x_, y); }

  private:
    SparseMatrix2D& matrix_;
    int32_t x_;
  };

  class ConstRowProxy {
  public:
    ConstRowProxy(const SparseMatrix2D& matrix, int32_t x) : matrix_(matrix), x_(x) {}

    T operator[](int32_t y) const { return matrix_.get(x_, y); }

  private:
    const SparseMatrix2D& matrix_;
    int32_t x_;
  };

  RowProxy operator[](int32_t x) { return RowProxy(*this, x); }

  ConstRowProxy operator[](int32_t x) const { return ConstRowProxy(*this, x); }

private:
  std::unordered_map<std::pair<int32_t, int32_t>, T, pair_fast_hash> data_;
  std::size_t size_ = 0;
};
