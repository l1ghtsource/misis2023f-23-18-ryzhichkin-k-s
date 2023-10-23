#include <iostream>

// ставим факела по боковым стенкам пирамиды

void solve() {
  int n = 0; // количество этажей в пирамиде
  std::cin >> n;
  if (n == 1) {
    std::cout << 1 << std::endl;
  }
  else if (n == 2) {
    std::cout << 1 << std::endl;
    std::cout << 1 << ' ' << 1 << std::endl;
  }
  else {
    std::cout << 1 << std::endl;
    std::cout << 1 << ' ' << 1 << std::endl;
    for (int i = 1; i < n - 1; ++i) {
      std::cout << 1 << ' ';
      for (int j = 0; j < i; ++j) {
        std::cout << 0 << ' ';
      }
      std::cout << 1 << ' ' << std::endl;
    }
  }
}

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
