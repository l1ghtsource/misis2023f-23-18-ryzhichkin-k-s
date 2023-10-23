#include <iostream>
#include <vector>

void solve() {
  int n = 0;
  std::cin >> n;
  std::vector<int> level(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> level[i];
  }
  int left_last_uno = 0;
  int right_first_uno = n - 1;
  while (left_last_uno < n - 1 && level[left_last_uno + 1] != 0) {
    left_last_uno += 1;
  }
  while (right_first_uno > 1 && level[right_first_uno - 1] != 0) {
    right_first_uno -= 1;
  }
  int total = right_first_uno - left_last_uno;
  std::cout << total << std::endl;
}

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}