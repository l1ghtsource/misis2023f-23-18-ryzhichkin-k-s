#include <iostream>
#include <cmath>

int main() {
  int t = 0;
  int a = 0;
  int b = 0; 
  int c = 0;
  int ans = 0;
  double delta = 0.0;
  double n = 0.0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> a >> b >> c;
    delta = abs(a - b);
    n = delta / (2 * c);
    std::cout << ceil(n) << std::endl;
  }
  return 0;
}
