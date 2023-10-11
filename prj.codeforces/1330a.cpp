#include <iostream>
#include <vector>

int main() {
  int t = 0; // количество наборов входных данных
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n = 0; // количество раундов
    int x = 0; // положительное целое число
    std::cin >> n >> x;
    std::vector<int> arr(300);
    for (int i = 1; i <= n + x; i++) {
      arr[i] = 0;
    }
    for (int j = 0; j < n; j++) {
      int a = 0; // место в j-м раунде
      std::cin >> a;
      arr[a] = 1;
    }
    int ans = 0;
    for (int k = n + x; k > 0; k--) {
      int v = 0; // такое число, что будет возможно собрать все места от 1 до v спустя x следующих контестов
      for (int r = 1; r <= k; r++) {
        if (arr[r] == 0) {
          v++;
        }
      }
      if (v <= x) {
        ans = k;
        break;
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
