#include <iostream>
#include <set>

bool check(int num) {
  int l = 0;
  std::set<int> digits;
  while (num > 0) {
    digits.insert(num % 10);
    num /= 10;
    l += 1;
  }
  if (digits.size() == l) {
    return false;
  }
  else {
    return true;
  }
}

int main() {
  int y = 0;
  std::cin >> y;
  y++;
  while (check(y)) {
    y++;
  }
  std::cout << y;
  return 0;
}
