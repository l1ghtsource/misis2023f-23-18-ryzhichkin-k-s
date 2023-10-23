#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int total = 0;
  char prev = 'a';
  for (char& i : s) {
    total += std::min(std::abs(i - prev), 26 - std::abs(i - prev));
    prev = i;
  }
  std::cout << total;
  return 0;
}