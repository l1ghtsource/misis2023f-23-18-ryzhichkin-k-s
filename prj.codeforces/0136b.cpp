#include <iostream>
#include <string>
#include <cmath>

std::string reverse(std::string s) {
  std::string res = "";
  for (int i = s.size() - 1; i >= 0; --i) {
    res += s[i];
  }
  return res;
}

std::string convert_to_another_base(unsigned long long num, int base) {
  std::string reversed_converted_num = "";
  while (num > 0) {
    reversed_converted_num += std::to_string(num % base);
    num /= base;
  }
  std::string normal_converted_num = reverse(reversed_converted_num);
  return normal_converted_num;
}

void solve() {
  unsigned long long a = 0;
  unsigned long long c = 0;
  std::cin >> a >> c;
  std::string converted_a = convert_to_another_base(a, 3);
  std::string converted_c = convert_to_another_base(c, 3);
  int size_delta = converted_c.size() - converted_a.size();
  int abs_size_delta = std::abs(size_delta);
  if (a == 0 && c == 0) {
    std::cout << 0;
  }
  else {
    if (converted_c.size() > converted_a.size()) {
      for (int i = 0; i < abs_size_delta; ++i) {
        converted_a.insert(converted_a.begin(), '0');
      }
    }
    else {
      for (int i = 0; i < abs_size_delta; ++i) {
        converted_c.insert(converted_c.begin(), '0');
      }
    }
    std::string b = "";
    for (int i = 0; i < std::max(converted_c.size(), converted_a.size()); ++i) {
      b += std::to_string((converted_c[i] - converted_a[i] + 3) % 3);
    }
    unsigned long long ans = std::stoull(b, nullptr, 3);
    std::cout << ans;
  }
}

int main() {
  solve();
}