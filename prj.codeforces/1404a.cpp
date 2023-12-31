#include <iostream>

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0; // длина строки
    int k = 0; // параметр для сбалансированной бинарной строки
    std::string s; // строка
    std::cin >> n >> k >> s;
    bool flag = true;
    for (int i = 0; i < k; i++) {
      char temp = s[i];
      for (int j = i + k; i < n; i += k) {
        if (temp == '1' && s[j] == '0') {
          std::cout << "NO" << std::endl;
          flag = false;
          break;
        }
        else if (temp == '0' && s[j] == '1') {
          std::cout << "NO" << std::endl;
          flag = false;
          break;
        }
        else if (temp == '?' && s[j] != '?') {
          temp = s[j];
        }
      }
      s[i] = temp;
    }
    if (flag) {
      int zero_counter = 0;
      int uno_counter = 0;
      for (int i = 0; i < k; i++) {
        if (s[i] == '1') {
          uno_counter++;
        }
        else if (s[i] == '0') {
          zero_counter++;
        }
      }
      if (zero_counter > k / 2 || uno_counter > k / 2) {
        std::cout << "NO" << std::endl;
      }
      else {
        std::cout << "YES" << std::endl;
      }
    }
  }
  return 0;
}
