#include <iostream>

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  while (t--) {
    int n = 0; // длина массива
    std::cin >> n;
    // массив {1, 1, ..., 1} (n единиц), очевидно, является прекрасным
    for (int i = 0; i < n; ++i) {
      std::cout << 1 << ' ';
    }
  }
  return 0;
}
