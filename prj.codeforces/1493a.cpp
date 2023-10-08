#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int c = k / 2 + n - k;
    if (c == 0) {
      std::cout << c << std::endl;
    }
    else {
      std::cout << c << std::endl;
      for (int i = ceil((double) k / 2); i < k; ++i) {
        std::cout << i << ' ';
      }
      for (int i = k + 1; i <= n; ++i) {
        std::cout << i << ' ';
      }
    }
  }
  return 0;
}