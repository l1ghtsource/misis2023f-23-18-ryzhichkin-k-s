#include <iostream>
#include <cmath>

int main() {
  int t = 0; // количество наборов входных данных
  int n = 0; // задает кол-во спортсменов = 2^n
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    std::cout << (int)pow(2, n) - 1 << std::endl;
  }
  return 0;
}
