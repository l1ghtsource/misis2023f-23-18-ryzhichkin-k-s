#include <iostream>

int main() {
  int elem = 0;
  int x = 0;
	int y = 0;
  int elem = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cin >> elem;
      if (elem == 1) {
        x = j + 1;
        y = i + 1;
        break;
      }
    }
  }
  ans = abs(x - 3) + abs(y - 3);
  std::cout << ans;
  return 0;
}
