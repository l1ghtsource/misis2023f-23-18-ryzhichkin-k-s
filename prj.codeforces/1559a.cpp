#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
  int n = 0;
  std::cin >> n;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      arr[i] = arr[i] & arr[j];
    }
  }
  int ans = *std::min_element(begin(arr), end(arr));
  std::cout << ans << std::endl;
}

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}