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
      data_.erase({x, y});
    } else {
      data_[{x, y}] = value;
    }
  }

  T get(int32_t x, int32_t y) const {
    auto it = data_.find({x, y});
    if (it != data_.end()) {
      return it->second;
    }
    return DefaultValue;
  }

  class ElementProxy {
  public:
    ElementProxy(SparseMatrix2D& matrix, int32_t x)
        : matrix_(matrix), x_(x) {}

    T operator[](int32_t y) const {
      return matrix_.get(x_, y);
    }

    T& operator[](int32_t y) {
      return matrix_.data_[{x_, y}];
    }

  private:
    SparseMatrix2D& matrix_;
    int32_t x_;
  };

  ElementProxy operator[](int32_t x) {
    return ElementProxy(*this, x);
  }

  const T operator[](int32_t x) const = delete;

private:
  std::unordered_map<std::pair<int32_t, int32_t>, T, pair_fast_hash> data_;
  friend class ElementProxy;
};
