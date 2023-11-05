#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n = 0;
  int k = 0;
  std::string s;
  std::cin >> n >> k;
  std::cin >> s;
  std::vector<int> a(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W') {
      a[i + 1] = 1;
    }
  }
  std::vector<int> dp(n + 1, 0);
  int min_white = 1000000000;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1] + a[i];
  }
  // dp[r] - dp[l] + 1 = кол-во белых на [l, r]
  for (int i = k; i <= n; ++i) {
    min_white = std::min(min_white, dp[i] - dp[i - k]);
  }
  std::cout << min_white << std::endl;
}

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
}