#include <iostream>
#include <string>
#include <queue>

void solve() {
  int n(0);
  int ans(0);
  char c(0);
  std::string s;
  std::queue<int> q;
  std::cin >> n >> c;
  std::cin >> s;
  s += s;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == c) {
      q.push(i);
    }
    else if (s[i] == 'g' && !q.empty()) {
      ans = std::max(ans, i - q.front());
      q = std::queue<int>();
    }
  }
  std::cout << ans << std::endl;
}

int main() {
  int t(0);
  std::cin >> t;
  while (t--) {
    solve();
  }
}