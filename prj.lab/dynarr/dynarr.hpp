#pragma once

#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <cstddef>

class DynArr {
public:
  [[nodiscard]] DynArr() = default;
  [[nodiscard]] DynArr(const DynArr&) = default;
  [[nodiscard]] DynArr(const ptrdiff_t size) : size_(size), capacity_(size) {
    if (size <= 0) {
      throw std::invalid_argument("Zero size is not allowed in DynArr ctor");
    }
    else {
      data_ = new float[size] {0};
    }
  }

  ~DynArr() = default;

  [[nodiscard]] DynArr& operator=(const DynArr&) = default;

  [[nodiscard]] ptrdiff_t Size() const noexcept { return size_; }

  void Resize(const ptrdiff_t size) {
    if (size > capacity_) {
      int new_capacity = size * 2;
      float* new_data = new float[new_capacity] {0};
      for (int i = 0; i < size_; ++i)
        new_data[i] = data_[i];
      delete[] data_;
      data_ = new_data;
      capacity_ = new_capacity;
    }
    size_ = size;
  }

  [[nodiscard]] float& operator[](const ptrdiff_t idx) { 
    if (idx < 0) {
      throw std::invalid_argument("Negative index is not allowed in [] operator");
    }
    else if (idx >= size_) {
      throw std::invalid_argument("Index that greater than size is not allowed in [] operator");
    }
    else {
      return data_[idx];
    }
  }

  [[nodiscard]] const float& operator[](const ptrdiff_t idx) const {
    if (idx < 0) {
      throw std::invalid_argument("Negative index is not allowed in [] operator");
    }
    else if (idx >= size_) {
      throw std::invalid_argument("Index that greater than size is not allowed in [] operator");
    }
    else {
      return data_[idx];
    }
  }
private:
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
  float* data_ = nullptr;
};

std::ostream& operator<<(std::ostream& out, DynArr a);

#endif