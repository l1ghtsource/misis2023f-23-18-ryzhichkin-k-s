#include <iostream>
#include <string>
#include <vector>

void solve() {
  int n = 0;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<std::string> ss;
  std::string temp_str;
  for (char c : s) {
    if (c == 'W') {
      if (!temp_str.empty()) {
        ss.push_back(temp_str);
        temp_str.clear();
      }
    }
    else {
      temp_str += c;
    }
  }
  if (!temp_str.empty()) {
    ss.push_back(temp_str);
  }
  bool flag = false;
  for (std::string q : ss) {
    bool flag1 = (q.find('R') != std::string::npos);
    bool flag2 = (q.find('B') != std::string::npos);
    if (flag1 ^ flag2) {
      flag = true;
      break;
    }
  }
  std::cout << (flag ? "NO" : "YES") << std::endl;
}

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}