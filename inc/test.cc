#include "./array.h"
#include <iostream>

int main(void) {
  algor_yht::type::Array test(new int[4]{1, 2, 3, 4}, 4);
  for (int i = 0; i < 4; ++i) {
    std::cout << test[i];
  }
}
