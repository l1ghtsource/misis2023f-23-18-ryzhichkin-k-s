#include <iostream>

void solve() {
  int n = 0; // верхняя граница
  std::cin >> n;
  std::cout << ((n + 1) / 10) << std::endl; // нам подходят числа вида a0a1a2...an, где an = 9, таких чисел на отрезке [1, n] ровно (n + 1) // 10.
}

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  while (t--) {
    solve();
  }
}
