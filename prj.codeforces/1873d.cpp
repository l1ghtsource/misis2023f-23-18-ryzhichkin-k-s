#include <iostream>
#include <vector>
#include <string>

void solve() {
  int length = 0;
  int step = 0;
  std::cin >> length >> step;
  std::string s;
  std::cin >> s;
  int total = 0;
  for (int i = 0; i < length; i++) {
    if (s[i] == 'W') {
      continue;
    }
    else {
      total++;
      for (int j = i; j < std::min(i + step, length); j++) {
        s[j] = 'W';
      }
    }
  }
  std::cout << total << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
