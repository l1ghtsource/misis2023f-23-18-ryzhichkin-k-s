#include <iostream>
#include <cmath>
#include <vector>

int main() {
  std::vector<int> nums; // числа, входящие в разложение n на круглые
  int t = 0; // количество наборов входных данных 
  int n = 0; // очередное целое число
  int k = 0; // минимальное количество слагаемых в разложении n на круглые числа
  int true_len = 0; // длина n
  int true_n = 0; // копия n
  int zero_counter = 0; // счётчик нулей в n
  int pseudo_n = 0; // копия n
  int r = 0; // разряды n
  int x = 0; // входное число
  double l; // длина куска n
  std::cin >> t;
  std::vector<int> data; // числа
  for (int h = 0; h < t; h++) {
    std::cin >> x;
    data.push_back(x);
  }
  for (int i = 0; i < t; i++) {
    n = data[i];
    true_len = floor(log10(n) + 1);
    true_n = n;
    pseudo_n = n;
    zero_counter = 0;
    nums.push_back(n);
    while (n > 10) {
      l = floor(log10(n) + 1);
      n = n % (int)pow(10, l - 1);
      if (n != 0) {
        nums.push_back(n);
      }
    }
    while (pseudo_n > 0) {
      r = pseudo_n % 10;
      if (r == 0) {
        zero_counter++;
      }
      pseudo_n /= 10;
    }
    nums.push_back(0);
    if (zero_counter + 1 == true_len) {
      std::cout << 1 << std::endl;
      std::cout << true_n << std::endl;
    }
    else {
      std::cout << nums.size() - 1 << std::endl;
      for (int j = 1; j < nums.size(); j++) {
        std::cout << nums[j - 1] - nums[j] << " ";
      }
      std::cout << std::endl;
    }
    nums.clear();
  }
  return 0;
}
