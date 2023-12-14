#pragma once

#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <cstddef>

class DynArr {
public:
  [[nodiscard]] DynArr() = default;
  [[nodiscard]] DynArr(const DynArr&) = default;
  [[nodiscard]] DynArr(const int size) : size_(size), capacity_(size) {
    if (size <= 0) {
      throw std::invalid_argument("Zero size is not allowed in DynArr ctor");
    }
    else {
      data_ = new float[size];
    }
  }

  ~DynArr() = default;

  [[nodiscard]] DynArr& operator=(const DynArr&) = default;

  [[nodiscard]] int Size() const noexcept { return size_; }

  void Resize(const int size) { 
    if (size > capacity_) {
      int new_capacity = std::max(size, size * 2);
      float* new_data = new float[new_capacity];
      for (int i = 0; i < size_; ++i)
        new_data[i] = data_[i];
      delete[] data_;
      data_ = new_data;
      capacity_ = new_capacity;
    }
    size_ = size;
  }

  [[nodiscard]] float& operator[](const int idx) { return data_[idx]; }
  [[nodiscard]] const float& operator[](const int idx) const { return data_[idx]; }
private:
  int size_ = 0;
  int capacity_ = 0;
  float* data_ = 0;
};

std::ostream& operator<<(std::ostream& out, DynArr a);

#endif
