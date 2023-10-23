#include <iostream>

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c; // 3 целых числа
    std::cout << a + b + c << " " << b + c << " " << c << std::endl; // такая тройка (x, y, z), что x mod y = a, y mod z = b, z mod x = c.
    // (a + b + c) mod (b + c) = a, (b + c) mod c = b, (b + c) mod (a + b + c) = c, c mod (a + b + c) = c.
  }
  return 0;
}
