﻿#include <iostream>

int main() {
  int x = 0; // координата дома
  std::cin >> x;
  // ищем расстояние до 0
  if (x % 5 == 0) {
    std::cout << x / 5;
  }
  else {
    std::cout << x / 5 + 1;
  }
  return 0;
}
