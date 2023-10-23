#include <vector>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  int t = 0; // количество наборов входных данных
  std::cin >> t; 
  for (int i = 0; i < t; i++) {
    int n = 0; // длина пароля
    std::cin >> n;
    std::string s; // пароль
    std::cin >> s;
    int k = 0; // количество особых букв
    std::cin >> k;
    std::vector<bool> spec(30, false); // особые буквы
    int res = 0;
    int dr = 0;
    for (int j = 0; j < k; j++) {
      char c = ' ';
      std::cin >> c; // очередная особа буква
      spec[c - 'a'] = true;
    }
    for (int r = 0; r < n; r++) {
      if (spec[s[r] - 'a']) {
        res = std::max(res, r - dr);
        dr = r;
      }
    }
    std::cout << res << std::endl;
  }
  return 0;
}
