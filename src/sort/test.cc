// Copyright yht 2020 SegmentFaultCPP
#include <gtest/gtest.h>

#include <iostream>
#include "./insert_sort.h"

TEST(algor_yht, insert_sort) {
  int array[11] = {10, 3, 4, 2, 1, 5, 8, 9, 7, 6, 0};
  int result[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10};
  algor_yht::sort::insert_sort(array);
  int array1[11] = {10, 3, 4, 2, 1, 5, 8, 9, 7, 6};
  algor_yht::sort::insert_sort(array1, 11);
  EXPECT_TRUE(!memcmp(array, result, 11));
  EXPECT_TRUE(!memcmp(array1, result, 11));
}