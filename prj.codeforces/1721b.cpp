#include <iostream>

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0; // размер поля n x m
    int m = 0; // размер поля n x m
    int s_x = 0; // координата клетки с лазером
    int s_y = 0; // координата клетки с лазером
    int d = 0; // испепеляющее расстояние лазера
    std::cin >> n >> m >> s_x >> s_y >> d;
    if (std::min(s_x - 1, m - s_y) > d || std::min(s_y - 1, n - s_x) > d) {
      std::cout << n + m - 2 << std::endl; // (n - 1) + (m - 1)
    }
    else {
      std::cout << -1 << std::endl; // если лазер касается > 1 стены
    }
  }
  return 0;
}
