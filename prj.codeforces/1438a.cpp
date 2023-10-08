#include <iostream>
#include <vector>

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cout << 1 << ' ';
    }
  }
  return 0;
}