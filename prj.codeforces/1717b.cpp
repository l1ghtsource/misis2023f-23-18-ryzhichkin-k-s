#include <iostream>
#include <vector>

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  for (int h = 0; h < t; h++) {
    int n = 0; // размер таблицы
    int k = 0; // такое число, что среди любых k подряд идущих по вертикали или по горизонтали клеток должна быть хотя бы одна, в которой записан символ 'X'.
    int r = 0; // координата клетки (r, c)
    int c = 0; // координата клетки (r, c)
    std::cin >> n >> k >> r >> c;
    std::vector<std::vector<char>> mat(n, std::vector<char>(n)); // сама матрица
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = '.';
      }
    }
    for (int p = 1; p <= n; p++) {
      for (int q = 1; q <= n; q++) {
        if (((r + c) % k) == ((p + q) % k)) {
          mat[p - 1][q - 1] = 'X'; // ставим 'X' в тех клетках, сумма координат которых сравнима с суммой координат клетки (r, c) по модулю k.
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << mat[i][j];
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
