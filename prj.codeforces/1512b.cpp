#include <iostream>
#include <vector>

// runtime error на cf по неведомым причинам

void solve() {
  int n = 0;
  std::cin >> n;
  std::vector<std::vector<char>> a(n, std::vector<char>(n, '.'));
  int x_1 = 0;
  int y_1 = 0;
  int x_2 = 0;
  int y_2 = 0;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
      if (a[i][j] == '*' && count == 0) {
        x_1 = i;
        y_1 = j;
        count++;
      }
      else if (a[i][j] == '*' && count == 1) {
        x_2 = i;
        y_2 = j;
        count++;
      }
    }
  }
  int x_ans_1 = 0;
  int y_ans_1 = 0;
  int x_ans_2 = 0;
  int y_ans_2 = 0;
  if (y_1 == y_2) {
    if (y_1 - 1 < 0) {
      x_ans_1 = x_1;
      x_ans_2 = x_2;
      y_ans_1 = y_1 + 1;
      y_ans_2 = y_2 + 1;
    }
    else {
      x_ans_1 = x_1;
      x_ans_2 = x_2;
      y_ans_1 = y_1 - 1;
      y_ans_2 = y_2 - 1;
    }
  }
  else if (x_1 == x_2) {
    if (x_1 - 1 < 0) {
      y_ans_1 = y_1;
      y_ans_2 = y_2;
      x_ans_1 = x_1 + 1;
      x_ans_2 = x_2 + 1;
    }
    else {
      y_ans_1 = y_1;
      y_ans_2 = y_2;
      x_ans_1 = x_1 - 1;
      x_ans_2 = x_2 - 1;
    }
  }
  else {
    x_ans_1 = x_1;
    y_ans_1 = y_2;
    x_ans_2 = x_2;
    y_ans_2 = y_1;
  }
  a[x_ans_1][y_ans_1] = '*';
  a[x_ans_2][y_ans_2] = '*';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << a[i][j];
    }
    std::cout << std::endl;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}