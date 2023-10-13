#include <iostream>

int main() {
  int t = 0; // количество наборов входных данных
  int n = 0; // длину массива
  int a = 0; // очередной элемент массива
  int c = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    c = 0;
    for (int j = 0; j < n; j++) {
      std::cin >> a;
      if (a % 2 != 0) {
        c++;
      }
    }
    if (c % 2 == 0) {
      std::cout << "YES" << std::endl;
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}
