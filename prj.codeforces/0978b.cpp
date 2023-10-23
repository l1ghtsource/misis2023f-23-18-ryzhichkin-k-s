#include <iostream>

int main() {
  int n = 0; // длина имени файла
  int x_counter = 0; // количество подряд идущих 'x' в строке
  int max_x = 0; // максимальное количество подряд идущих 'x' в строке
  int summary = 0; // минимальное количество символов, которые нужно удалить из имени файла так, чтобы название не содержало «xxx» в качестве подстроки
  std::string s; // исходная строка
  s += 'z';
  std::cin >> n;
  std::cin >> s;
  for (int i = 0; i <= n; i++) {
    if (s[i] == 'x') {
      x_counter += 1;
    }
    else {
      max_x = (x_counter > max_x) ? x_counter : max_x;
      summary += (max_x > 2) ? max_x - 2 : 0;
      x_counter = 0;
      max_x = 0;
    }
  }
  std::cout << summary;
  return 0;
}
