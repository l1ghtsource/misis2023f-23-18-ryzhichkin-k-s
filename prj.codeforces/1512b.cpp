#include <iostream>
#include <vector>

void solve() {
  int n = 0;
  std::cin >> n;
  int x_1 = 0;
  int y_1 = 0;
  int x_2 = 0;
  int y_2 = 0;
  int curr_x = 0;
  int curr_y = 0;
  int count = 0;
  for (int i = 0; i < n * n; ++i) {
    char elem;
    std::cin >> elem;
    if (elem == '*' && count == 0) {
      x_1 = curr_x;
      y_1 = curr_y;
      count++;
    }
    else if (elem == '*' && count == 1) {
      x_2 = curr_x;
      y_2 = curr_y;
      count++;
    }
    curr_x += 1;
    curr_x %= n;
    if (curr_x == n - 1) {
      curr_y += 1;
    }
    curr_y %= n;
  }
  int x_ans_1 = 0;
  int y_ans_1 = 0;
  int x_ans_2 = 0;
  int y_ans_2 = 0;
  if (y_1 == y_2) {
    int d = std::abs(y_2 - y_1);
    if (y_1 - d < 0 || y_2 - d < 0) {
      x_ans_1 = x_1 + d;
      x_ans_2 = x_2 + d;
      y_ans_1 = y_1;
      y_ans_2 = y_2;
    }
    else {
      x_ans_1 = x_1 - d;
      x_ans_2 = x_2 - d;
      y_ans_1 = y_1;
      y_ans_2 = y_2;
    }
  }
  else if (x_1 == x_2) {
    int d = std::abs(x_2 - x_1);
    if (x_1 - d < 0 || x_2 - d < 0) {
      y_ans_1 = y_1 + d;
      y_ans_2 = y_2 + d;
      x_ans_1 = x_1;
      x_ans_2 = x_2;
    }
    else {
      y_ans_1 = y_1 - d;
      y_ans_2 = y_2 - d;
      x_ans_1 = x_1;
      x_ans_2 = x_2;
    }
  }
  else {
    int x_min = std::min(x_1, x_2);
    int x_max = std::max(x_1, x_2);
    int y_min = std::min(y_1, y_2);
    int y_max = std::max(y_1, y_2);
    int d = x_max - x_min;
    if (x_2 > x_1 && y_2 > y_1) {
      x_ans_1 = x_1;
      y_ans_1 = y_1 + d;
      x_ans_2 = x_2;
      y_ans_2 = y_2 - d;
    }
    else if (x_2 < x_1 && y_2 > y_1) {
      x_ans_1 = x_1;
      y_ans_1 = y_1 - d;
      x_ans_2 = x_2;
      y_ans_2 = y_2 - d;
    }
    else if (x_1 > x_2 && y_2 < y_1) {
      x_ans_1 = x_1;
      y_ans_1 = y_1 + d;
      x_ans_2 = x_2;
      y_ans_2 = y_2 + d;
    }
    else if (x_1 < x_2 && y_2 < y_1) {
      x_ans_1 = x_1;
      y_ans_1 = y_1 + d;
      x_ans_2 = x_2;
      y_ans_2 = y_2 + d;
    }
  }
  std::vector<std::vector<char>> a(n, std::vector<char>(n, '.'));
  a[x_ans_1][y_ans_1] = '*';
  a[x_ans_2][y_ans_2] = '*';
  a[x_1][y_1] = '*';
  a[x_2][y_2] = '*';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << a[i][j];
    }
    std::cout << std::endl;
  }
}

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
