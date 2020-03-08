#pragma once
// Copyright 2020 yht
// insert_soft
#include <iostream>
#include <utility>

#include "../../inc/type.h"

namespace algor_yht {
namespace sort {
template <typename T>
// 指针版本
void insert_sort(T* input, const type::uint_t len) {
  T key = 0;
  for (int i = 1; i < len; ++i) {
    key = *(input + i);
    int j = i - 1;
    while (*(input + j) > key && j >= 0) {
      *(input + j + 1) = *(input + j);
      --j;
      *(input + j+1) = key;
    }
  }
}
template <typename T, const typename type::uint_t N>
void insert_sort(T (&input)[N]) {
  insert_sort(input, N);
}
}  // namespace sort
}  // namespace algor_yht
