#include <iostream>

int main() {
  int n, k, f, t, p, m;
  int n = 0; // кол-во ресторанов
  int k = 0; // кол-во единиц времени
  int f = 0; // безымянная характеристика
  int t = 0; // время, которое кролики затратят на обед в i-ом ресторане
  int p = 0; // удовольствие
  int m = 0; // максимальное кроличье удовольствие
  m = -100000000000000000;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> f >> t;
    if (t > k) {
      p = f - (t - k);
    }
    else {
      p = f;
    }
    if (p > m) {
      m = p;
    }
  }
  std::cout << m;
  return 0;
}
