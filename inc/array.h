#pragma once
// Copyright 2020 yht SegmentFaultCPP
// 指针仿照数组的类型
#include "../src/smart_pointer/smart_pointer.h"
#include "../src/meta/remove_pointer.h"
#include <iostream>

namespace algor_yht {
namespace type {
template <typename T>
class Array : public smart_pointer::SmartPointer<T> {
 public:
  explicit Array(T* src, uint_t len)
      : len(len), smart_pointer::SmartPointer<T>(src) {}
  virtual ~Array() {}
  T operator[](const uint_t index) {
    if (index < len) {
        std::cout << *(this->m_ptr + index);
      return *((this->m_ptr) + index);
    } else {
      return *((this->m_ptr) + (len - 1));
    }
  }

 private:
  uint_t len = 0;
};
}  // namespace type
}  // namespace algor_yht
