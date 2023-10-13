#include <iostream>
#include <vector>

int main() {
  int t = 0;
  int b = 0;
  int c = 0;
  int h = 0;
  int curr_bread = 0;
  int curr_others = 0;
  int counter = 0;
  std::vector<int> breads;
  std::vector<int> others;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> b >> c >> h;
    breads.push_back(b);
    others.push_back(c + h);
  }
  for (int j = 0; j < t; j++) {
    curr_bread = breads[j];
    curr_others = others[j];
    curr_bread -= 2;
    curr_others -= 1;
    counter += 3;
    while (true) {
      if (curr_bread > 0 && curr_others > 0) {
        curr_bread--;
        counter++;
      }
      else {
        break;
      }
      if (curr_others > 0) {
        curr_others--;
        counter++;
      }
      else {
        break;
      }
    }
    std::cout << counter << std::endl;
    counter = 0;
  }
  return 0;
}
