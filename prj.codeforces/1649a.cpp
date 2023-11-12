#include <iostream>
#include <vector>

void solve() {
  int t(0);
  std::vector<int> a(105);
  int n(0);
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int left(0);
  int right(n - 1);
  while (a[left + 1] == 1 && left < right) {
    left++;
  }
  while (a[right - 1] == 1 && right > left) {
    right--;
  }
  std::cout << right - left << std::endl;
}

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

